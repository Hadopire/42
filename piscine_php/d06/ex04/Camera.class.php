<?PHP
require_once 'Matrix.class.php';

class Camera {

    private $_position;
    private $_orientation;
    private $_fov;
    private $_ratio;
    private $_nearplane;
    private $_farplane;
    private $_width;
    private $_height;
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
            $this->_width = $kwargs['width'];
            $this->_height = $kwargs['height'];
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

    private function _getTt() {
        $vtc = (new Vector( array('dest' => $this->_position) ))->opposite();
        return new Matrix( array('preset' => Matrix::TRANSLATION, 'vtc' => $vtc) );
    }

    private function _getTr() {
        return $this->_orientation->transpose();
    }

    private function _getViewmatrix() {
        return $this->_getTr()->mult($this->_getTt() );
    }

    private function _getProj() {
        return new Matrix( array( 'preset' => Matrix::PROJECTION, 'ratio' => $this->_ratio, 'fov' => $this->_fov,
                    'near' => $this->_nearplane, 'far' => $this->_farplane) );
    }

    public function watchVertex($worldVertex) {
        $trans = $this->_getViewMatrix()->mult($this->_getProj());
        $worldVertex = $trans->transformVertex($worldVertex);
        $pixel = new Vertex( array('x' => ( $worldVertex->getX() + 1 ) * $this->_width * 0.5,
                                    'y' => ($worldVertex->getY() + 1 ) * $this->_height * 0.5,
                                    'z' => 0));
        return $pixel;
    }

    public function setWidth($width) {
        $this->_width = intval($width);
    }

    public function setHeight($height) {
        $this->_width = intval($height);
    }

    function __destruct() {

        if (self::$verbose === TRUE)
        {
            printf("Matrix instance destructed\n");
        }
    }

    function __toString() {
        return (sprintf("+ Origine: %s\n+ tT:\n%s\ntR:\n%s\nViewmatrix:\n%s\nProj:\n%s", $this->_position,
                    $this->_getTt(), $this->_getTr(), $this->_getViewmatrix(), $this->_getProj() ));
    }

    function doc() {
        return ("camera\n");
    }

}
?>
