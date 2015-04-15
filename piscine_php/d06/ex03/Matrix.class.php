<?PHP
require_once 'Vector.class.php';

class Matrix {

	const IDENTITY = 1;
	const SCALE = 2;
	const RX = 3;
	const RY = 4;
	const RZ = 5;
	const TRANSLATION = 6;
	const PROJECTION = 7;
	static $verbose = FALSE;
	private $_matrix;

	function __construct($kwargs) {
		$type;
		if (array_key_exists('preset', $kwargs))
		{
			if (($kwargs['preset'] === self::RX || $kwargs['preset'] === self::RZ || $kwargs['preset'] === self::RY) && !array_key_exists('angle', $kwargs))
			{
				echo "Matrix: angle key needed in constructor when preset is Matrix::RX||RY|RZ\n";
				exit (-1);
			}
			if ($kwargs['preset'] === self::SCALE)
			{
				$type = "SCALE preset";
				if (!array_key_exists('scale', $kwargs))
				{
					echo "Matrix: scale key needed in constructor when preset is Matrix::scale\n";
					exit (-1);
				}
				$this->_matrix = array(
					'a1' => array ('1' => $kwargs['scale'], '2' => 0, '3' => 0, '4' => 0),
					'a2' => array ('1' => 0, '2' => $kwargs['scale'], '3' => 0, '4' => 0),
					'a3' => array ('1' => 0, '2' => 0, '3' => $kwargs['scale'], '4' => 0),
					'a4' => array ('1' => 0, '2' => 0, '3' => 0, '4' => 1)
				);
			}
			else if ($kwargs['preset'] === self::RX)
			{
				$type = "Ox ROTATION preset";
				$angle = floatval($kwargs['angle']);
				$this->_matrix = array(
					'a1' => array ('1' => 1, '2' => 0, '3' => 0, '4' => 0),
					'a2' => array ('1' => 0, '2' => cos($angle), '3' => -sin($angle), '4' => 0),
					'a3' => array ('1' => 0, '2' => sin($angle), '3' => cos($angle), '4' => 0),
					'a4' => array ('1' => 0, '2' => 0, '3' => 0, '4' => 1)
				);
			}
			else if ($kwargs['preset'] === self::RY)
			{
				$type = "Oy ROTATION preset";
				$angle = floatval($kwargs['angle']);
				$this->_matrix = array(
					'a1' => array ('1' => cos($angle), '2' => 0, '3' => sin($angle), '4' => 0),
					'a2' => array ('1' => 0, '2' => 1, '3' => 0, '4' => 0),
					'a3' => array ('1' => -sin($angle), '2' => 0, '3' => cos($angle), '4' => 0),
					'a4' => array ('1' => 0, '2' => 0, '3' => 0, '4' => 1)
				);
			}
			else if ($kwargs['preset'] === self::RZ)
			{
				$type = "Oz ROTATION preset";
				$angle = floatval($kwargs['angle']);
				$this->_matrix = array(
					'a1' => array ('1' => cos($angle), '2' => -sin($angle), '3' => 0, '4' => 0),
					'a2' => array ('1' => sin($angle), '2' => cos($angle), '3' => 0, '4' => 0),
					'a3' => array ('1' => 0, '2' => 0, '3' => 1, '4' => 0),
					'a4' => array ('1' => 0, '2' => 0, '3' => 0, '4' => 1)
				);
			}
			else if ($kwargs['preset'] === self::TRANSLATION)
			{
				$type = "TRANSLATION preset";
				if (!array_key_exists('vtc', $kwargs))
				{
					echo "Matrix: vtc key needed in constructor when preset is Matrix::TRANSLATION\n";
					exit (-1);
				}
				$vector = $kwargs['vtc'];
				$this->_matrix = array(
					'a1' => array ('1' => 1, '2' => 0, '3' => 0, '4' => $vector->getX()),
					'a2' => array ('1' => 0, '2' => 1, '3' => 0, '4' => $vector->getY()),
					'a3' => array ('1' => 0, '2' => 0, '3' => 1, '4' => $vector->getZ()),
					'a4' => array ('1' => 0, '2' => 0, '3' => 0, '4' => 1)
				);
			}
			else if ($kwargs['preset'] === self::PROJECTION)
			{
				if (!array_key_exists('fov', $kwargs) || !array_key_exists('ratio', $kwargs) || !array_key_exists('near', $kwargs) || !array_key_exists('far', $kwargs))
				{
					echo "Matrix: fov, ratio, near and far keys needed in constructor when preset is Matrix::PROJECTION\n";
					exit (-1);
				}
				$type = "PROJECTION preset";
				$focal_length = 1 / tan(deg2rad($kwargs['fov']) / 2);
				$n = $kwargs['near'];
				$f = $kwargs['far'];
				$viewport = $kwargs['ratio'];
				$this->_matrix = array(
					'a1' => array ('1' => $focal_length / $viewport, '2' => 0, '3' => 0, '4' => 0),
					'a2' => array ('1' => 0, '2' => $focal_length, '3' => 0, '4' => 0),
					'a3' => array ('1' => 0, '2' => 0, '3' => -( ($f + $n) / ($f - $n) ), '4' => -( (2 * $f * $n ) / ($f - $n) ) ),
					'a4' => array ('1' => 0, '2' => 0, '3' => -1, '4' => 0)
				);
			}
			else if ($kwargs['preset'] === self::IDENTITY)
			{
				$type = "IDENTITY";
				$this->_matrix = array(
					'a1' => array ('1' => 1, '2' => 0, '3' => 0, '4' => 0),
					'a2' => array ('1' => 0, '2' => 1, '3' => 0, '4' => 0),
					'a3' => array ('1' => 0, '2' => 0, '3' => 1, '4' => 0),
					'a4' => array ('1' => 0, '2' => 0, '3' => 0, '4' => 1)
				);

			}
			else
			{
				echo "Matrix: preset key bad value in constructor\n";
				exit (-1);
			}
		}
		else
		{
			echo "Matrix: preset key needed in constructor\n";
			return (-1);
		}	
		if (self::$verbose === TRUE)
		{
			printf("Matrix $type instance constructed\n");
		}
	}

	function __destruct() {

		if (self::$verbose === TRUE)
		{
			printf("Matrix instance destructed\n");
		}
	}

	function __toString() {
		return sprintf(
			"M | vtcX | vtcY | vtcZ | vtxO\n".
			"-----------------------------\n".
			"x | %.02f | % .02f | %.02f | %.02f\n".
			"y | %.02f | % .02f | %.02f | %.02f\n".
			"z | %.02f | % .02f | %.02f | %.02f\n".
			"w | %.02f | % .02f | %.02f | %.02f",
			$this->_matrix['a1']['1'], $this->_matrix['a1']['2'], $this->_matrix['a1']['3'], $this->_matrix['a1']['4'],
			$this->_matrix['a2']['1'], $this->_matrix['a2']['2'], $this->_matrix['a2']['3'], $this->_matrix['a2']['4'],
			$this->_matrix['a3']['1'], $this->_matrix['a3']['2'], $this->_matrix['a3']['3'], $this->_matrix['a3']['4'],
			$this->_matrix['a4']['1'], $this->_matrix['a4']['2'], $this->_matrix['a4']['3'], $this->_matrix['a4']['4']);
	}

	function doc() {
		return (file_get_contents('Matrix.doc.txt'));
	}

	public function mult($rhs) {
		$res = clone $this;
		$i = 0;
		while (++$i < 5)
		{
			$j = 0;
			while (++$j < 5)
			{
				$k = 0;
				$sum = 0;
				while (++$k < 5)
					$sum += $this->_matrix['a'.$i][$k] * $rhs->_matrix['a'.$k][$j];
				$res->_matrix['a'.$i][$j] = $sum;
			}
		}
		return ($res);
	}

	public function transformVertex($vtx) {
		$res = new Vertex( array(
			'x' => $this->_matrix['a1']['1'] * $vtx->getX() + $this->_matrix['a1']['2'] * $vtx->getY() + $this->_matrix['a1']['3'] * $vtx->getZ() + $this->_matrix['a1']['4'] * $vtx->getW(),
			'y' => $this->_matrix['a2']['1'] * $vtx->getX() + $this->_matrix['a2']['2'] * $vtx->getY() + $this->_matrix['a2']['3'] * $vtx->getZ() + $this->_matrix['a2']['4'] * $vtx->getW(),
			'z' => $this->_matrix['a3']['1'] * $vtx->getX() + $this->_matrix['a3']['2'] * $vtx->getY() + $this->_matrix['a3']['3'] * $vtx->getZ() + $this->_matrix['a3']['4'] * $vtx->getW(),
			'w' => $this->_matrix['a4']['1'] * $vtx->getX() + $this->_matrix['a4']['2'] * $vtx->getY() + $this->_matrix['a4']['3'] * $vtx->getZ() + $this->_matrix['a4']['4'] * $vtx->getW()
		));
		return $res;
	}
}
?>
