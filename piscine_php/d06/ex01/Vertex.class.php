<?PHP
require_once('Color.class.php');

Class Vertex {

	private $_x;
	private $_y;
	private $_z;
	private $_w;
	private $_color;
	static $verbose = FALSE;

	function __construct($kwargs) {
		if (array_key_exists('x', $kwargs))
		{
			$this->_x = floatval($kwargs['x']);
		}
		else
		{
			echo "Vertex : missing x key in constructor\n";
			exit(-1);
		}
		if (array_key_exists('y', $kwargs))
		{
			$this->_y = floatval($kwargs['y']);
		}
		else
		{
			echo "Vertex : missing y key in constructor\n";
			exit(-1);
		}
		if (array_key_exists('z', $kwargs))
		{
			$this->_z = floatval($kwargs['z']);
		}
		else
		{
			echo "Vertex : missing z key in constructor\n";
			exit(-1);
		}
		if (array_key_exists('w', $kwargs))
		{
			$this->_w = floatval($kwargs['w']);
		}
		else
		{
			$this->_w = 1.0;
		}
		if (array_key_exists('color', $kwargs))
		{
			$this->_color = clone $kwargs['color'];
		}
		else
		{
			$this->_color = new Color( array('red' => 255, 'green' => 255, 'blue' => 255) );
		}
		if (self::$verbose === TRUE)
			printf("Vertex( x: %.02f, y: %.02f, z:%.02f, w:%.02f, %s ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
	}
	
	function __toString() {
		if (self::$verbose === TRUE)
			return sprintf("Vertex( x: %.02f, y: %.02f, z:%.02f, w:%.02f, %s )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
		else
			return sprintf("Vertex( x: %.02f, y: %.02f, z:%.02f, w:%.02f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	function __destruct() {
		if (self::$verbose === TRUE)
			printf("Vertex( x: %.02f, y: %.02f, z:%.02f, w:%.02f, %s ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
	}

	static function doc() {
		return (file_get_contents('Vertex.doc.txt'));
	}

	public function getX() {
		return $this->_x;
	}

	public function getY() {
		return $this->_y;
	}

	public function getZ() {
		return $this->_z;
	}

	public function getW() {
		return $this->_w;
	}

	public function getColor() {
		return $this->_color;
	}

	public function setX($x) {
		$this->_x = $x;
	}

	public function setY($y) {
		$this->_y = $y;
	}

	public function setZ($z) {
		$this->_z = $z;
	}

	public function setW($w) {
		$this->_w = $w;
	}

	public function setColor($color) {
		$this->color = $color;
	}
}
?>
