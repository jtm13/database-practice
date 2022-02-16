<?php
include_once("container.php");
class BankAccount extends Container {
    function __construct($it) {
        parent::__construct($it);
    }

    function info(): string {
        return "<div class=\"account-info\" \">
        \n<header class=\"info-header\">
        \n<h3 class=\"Username\">Hello " . parent::getArray()["User"] . ",</h3>\n
        <div class=\"account-number\">
        \n<p class=\"number\">Account Number: " . parent::getArray()["AccountNumber"] . "</p>
        \n</div>
        \n</header>
        \n<div class\"info\">
        \n<table>
        \n<tt>
        \n<td class=\"first\">Cash</td>
        \n<td class=\"first\">Debt</td>
        \n<td class=\"first\">Net</td>
        \n</tt>
        \n<tt>
        \n<td>" . parent::getArray()["Money"] . "</td>
        \n<td>" . parent::getArray()["Debt"] . "</td>
        \n<td>" . parent::getArray()["Net"] . "</td>
        \n</div>
        \n</div>";
    }
}
?>