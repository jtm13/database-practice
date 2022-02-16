<?php 
abstract class Container {
    private $ar;
    function __construct($it) {
        $this->ar = $it;
    }

    protected function getArray() {
        return $this->ar;
    }

    protected function checkPicture(string $source): string {
        if (strcmp($source, "no img") !== 0) {
            return $source;
        }
        return "img/no_img.png";
    }

    function getID(): int {
        return $this->ar["ID"];
    }
          
    abstract function info(): string;
}
?>