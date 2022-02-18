<!DOCTYPE html>

<html lang="en-US">
    <head>
        <title>Bank of Justin</title>
        <link rel="stylesheet" type="text/css" href="normalize.css">
        <link rel="icon" type="image/x-icon" href="img/favicon.svg">
    </head>
    <body>
        <nav>
            Bank of Justin
        </nav>
        <?php
        session_start();
        $_SESSION["User"] = $_POST["user"];
        $_SESSION["Pass"] = $_POST["pass"];
        include("main.php");
        ?>
        <footer id="foot">
            <p>&#169 BANK OF JUSTIN COPYRIGHT 2022</p>
        </footer>
    </body>
</html>