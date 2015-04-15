<?PHP
require_once 'Vertex.class.php';
require_once 'Color.class.php';

class Vector {

	static $verbose = FALSE;
	private $_x;
	private $_y;
	private $_z;
	private $_w;

	function __construct($kwargs) {
		if (array_key_exists('dest', $kwargs))
		{
			$dest = $kwargs['dest'];
			$this->_x = $dest->getX();
			$this->_y = $dest->getY();
			$this->_z = $dest->getZ();
			$this->_w = $dest->getW();
		}
		else
		{
			echo "Vector: missing dest key in constructor\n";
			exit (-1);
		}
		if (array_key_exists('orig', $kwargs))
		{
			$orig = $kwargs['orig'];
			$this->_x -= $orig->getX();
			$this->_y -= $orig->getY();
			$this->_z -= $orig->getZ();
			$this->_w -= $orig->getW();
		}
		else
		{
			$orig = new Vertex( array( 'x' => 0, 'y' => 0, 'z' => 0, 'w' => 1) );
			$this->_w -= $orig->getW();
		}
		if (self::$verbose === TRUE)
		{
			printf("Vector( x:%.02f, y:%.02f, z:%.02f, w:%.02f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
		}
	}

	function __destruct() {
		if (self::$verbose === TRUE)
		{
			printf("Vector( x:%.02f, y:%.02f, z:%.02f, w:%.02f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
		}
	}

	function __toString() {
		return sprintf("Vector( x:%.02f, y:%.02f, z:%.02f, w:%.02f )", $this->_x, $this->_y, $this->_z, $this->_w);
	}

	function doc() {
		return file_get_contents('Vector.doc.txt');
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

	public function magnitude() {
		return (sqrt( pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2) ));
	}

	public function normalize() {
		$norm = new Vertex( array('x' => $this->_x / $this->magnitude(), 'y' => $this->_y / $this->magnitude(), 'z' => $this->_z / $this->magnitude() ) );
		return new Vector( array('dest' => $norm) );
	}

	public function add($rhs) {
		$add = new Vertex( array( 'x' => $this->_x + $rhs->getX(), 'y' => $this->_y + $rhs->getY(), 'z' => $this->_z + $rhs->getZ() ) );
		return new Vector( array('dest' => $add) );
	}

	public function sub($rhs) {
		$sub = new Vertex( array( 'x' => $this->_x - $rhs->getX(), 'y' => $this->_y - $rhs->getY(), 'z' => $this->_z - $rhs->getZ() ) );
		return new Vector( array('dest' => $sub) );
	}

	public function opposite() {
		$opp = new Vertex( array( 'x' => $this->_x * -1, 'y' => $this->_y * -1, 'z' => $this->_z * -1) );
		return new Vector( array('dest' => $opp) );
	}

	public function scalarProduct($k) {
		$sca = new Vertex( array( 'x' => $this->_x * $k, 'y' => $this->_y * $k, 'z' => $this->_z * $k ) );
		return new Vector( array('dest' => $sca) );
	}

	public function dotProduct($rhs) {
		return (($this->_x * $rhs->getX()) + ($this->_y * $rhs->getY()) + ($this->_z * $rhs->getZ()));
	}

	public function cos($rhs) {
		return ($this->dotProduct($rhs) / ( $this->magnitude() * $rhs->magnitude() ));
	}

	public function crossProduct($rhs) {
		$cross = new Vertex( array( 'x' => ($this->_y * $rhs->getZ()) - ($this->_z * $rhs->getY()),
			'y' => ($this->_z * $rhs->getX()) - ($this->_x * $rhs->getZ()),
			'z' => ($this->_x * $rhs->getY()) - ($this->_y * $rhs->getX())));
		return (new Vector( array('dest' => $cross) ));
	}
}

?>
