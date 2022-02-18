<?php
include_once("container.php");
class BankAccount extends Container {
    function __construct($it) {
        parent::__construct($it);
    }

    function info(): string {
        return "<div class=\"account-info\" \">
        \n<header class=\"info-header\">
        \n<h3 class=\"Username\">Hello " .$_SESSION["User"] . ",</h3>
        \n<div class=\"account-number\">
        \n<p class=\"number\">Account Number: " . parent::getArray()["AccountNumber"] . "</p>
        \n</div>
        \n</header>
        \n<div class=\"info\">
        \n<table>
        \n<tr>
        \n<th class=\"first\">Cash</td>
        \n<th class=\"first\">Debt</td>
        \n<th class=\"first\">Net</td>
        \n</tr>
        \n<tr>
        \n<td>" . parent::getArray()["Money"] . "</td>
        \n<td>" . parent::getArray()["Debt"] . "</td>
        \n<td>" . parent::getArray()["Net"] . "</td>
        \n</tr>
        \n</table>
        \n</div>
        \n</div>";
    }
}
?>