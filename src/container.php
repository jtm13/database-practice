<?php
define("NO_PICTURE", "placeholder");
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
        return NO_PICTURE;
    }
          
    abstract function info(): string;
}
?>