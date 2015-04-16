<?PHP
require_once 'Matrix.class.php';

class Camera {

	private $_position;
	private $_orientation;
	private $_fov;
	private $_ratio;
	private $_nearplane;
	private $_farplane;
	static $verbose = FALSE;

	function __construct($kwargs) {
		if (!array_key_exists('origin', $kwargs) || !array_key_exists('orientation', $kwargs) || !array_key_exists('near', $kwargs)
			|| !array_key_exists('far', $kwargs) || !array_key_exists('fov', $kwargs) || ( !array_key_exists('ratio', $kwargs) &&
			(!array_key_exists('width', $kwargs) && !array_key_exists('height', $kwargs))))
		{
			echo "Camera: incorrect array keys, use Camera::doc for more informations on the class\n";
			exit(-1);
		}
		$this->_position = $kwargs['origin'];
		$this->_orientation = $kwargs['orientation'];
		$this->_nearplane = $kwargs['near'];
		$this->_farplane = $kwargs['far'];
		$this->_fov = $kwargs['fov'];
		if (array_key_exists('width', $kwargs) && array_key_exists('height', $kwargs) && !array_key_exists('ratio', $kwargs))
		{
			$this->_ratio = $kwargs['width'] / $kwargs['height'];
		}
		else if (array_key_exists('ratio', $kwargs) && !array_key_exists('width', $kwargs) && !array_key_exists('height', $kwargs))
		{
			$this->_ratio = $kwargs['ratio'];
		}
		else
		{
			echo "Camera: incorrect array keys, use Camera::doc for more informations on the class\n";
		}
		if (self::$verbose === TRUE)
		{
			
		}
	}

	public function getTt() {
		$vtc = (new Vector( array('dest' => $this->_position) ))->opposite();
		return new Matrix( array('preset' => Matrix::TRANSLATION, 'vtc' => $vtc) );
	}

	public function getTr() {
        return $this->_orientation->transpose();
	}

    public function getViewmatrix() {
        return $this->gettR()->mult($this->getTt() );
    }

    public function getProj() {
        return new Matrix( array( 'preset' => Matrix::PROJECTION, 'ratio' => $this->_ratio, 'fov' => $this->_fov,
            'near' => $this->_nearplane, 'far' => $this->_farplane) );
    }

	function __destruct() {

		if (self::$verbose === TRUE)
		{
			printf("Matrix instance destructed\n");
		}
	}

	function __toString() {
		return (sprintf("+ Origine: %s\n+ tT:\n%s\ntR:\n%s\nViewmatrix:\n%s\nProj:\n%s", $this->_position,
            $this->getTt(), $this->getTr(), $this->getViewmatrix(), $this->getProj() ));
	}

	function doc() {
		return ("camera\n");
	}

}
?>
