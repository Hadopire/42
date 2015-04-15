<?PHP

Class Color {

	static $verbose = FALSE;
	public $red = 0;
	public $green = 0;
	public $blue = 0;

	function __construct($kwargs) {
		if (array_key_exists('rgb', $kwargs))
		{
			$this->red = intval($kwargs['rgb']) >> 16 & 0xff;
			$this->green = intval($kwargs['rgb']) >> 8 & 0xff;
			$this->blue = intval($kwargs['rgb']) & 0xff;
		}
		else
		{
			if (array_key_exists('red', $kwargs))
			{
				$this->red = intval($kwargs['red']);
			}
			if (array_key_exists('green', $kwargs))
			{
				$this->green = intval($kwargs['green']);
			}
			if (array_key_exists('blue', $kwargs))
			{
				$this->blue = intval($kwargs['blue']);
			}
		}
		if (self::$verbose === TRUE)
			echo 'Color( red: '.str_pad($this->red, 3, " ", STR_PAD_LEFT).', green: '
			.str_pad($this->green, 3, " ", STR_PAD_LEFT).', blue: '.str_pad($this->blue, 3, " ", STR_PAD_LEFT).' ) constructed.'."\n";
		return ;
	}

	static function doc() {
		return (file_get_contents('Color.doc.txt'));
	}

	function __destruct() {
		if (self::$verbose === TRUE)
			echo 'Color( red: '.str_pad($this->red, 3, " ", STR_PAD_LEFT).', green: '
			.str_pad($this->green, 3, " ", STR_PAD_LEFT).', blue: '.str_pad($this->blue, 3, " ", STR_PAD_LEFT).' ) destructed.'."\n";
		return ;
	}

	function __toString() {
		return ('Color( red: '.str_pad($this->red, 3, " ", STR_PAD_LEFT).', green: '
		.str_pad($this->green, 3, " ", STR_PAD_LEFT).', blue: '.str_pad($this->blue, 3, " ", STR_PAD_LEFT)." )");
	}

	public function add($color) {
		return (new Color( array('red' => $color->red + $this->red, 'green' => $color->green + $this->green, 'blue' => $color->blue + $this->blue) ));
	}

	public function sub($color) {
		return (new Color( array('red' => $this->red - $color->red, 'green' => $this->green - $color->green, 'blue' => $this->blue - $color->blue) ));
	}

	public function mult($factor) {
		return (new Color( array('red' => $this->red * $factor, 'green' => $this->green * $factor, 'blue' => $this->blue * $factor) ));
	}
}
?>
