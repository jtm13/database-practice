<!DOCTYPE html>

<?php
if (!in_array("user", array_keys($_POST)) || !in_array("pass", array_keys($_POST))) {
    header("Location: login.php");
    exit();
}
session_start();
$_SESSION["User"] = $_POST["user"];
$_SESSION["Pass"] = $_POST["pass"];
require_once("template.php");
?>

<html lang="en-US">
    <head>
        <title>Bank Account</title>
        <?php headInfo("$_SESSION[User]'s Account", "Profile", ["bank_account"]); ?>
    </head>
    <body>
        <?php 
        head();
        include("main.php");
        foot();
        ?>
    </body>
</html>