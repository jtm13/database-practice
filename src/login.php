<!DOCTYPE html>
<?php require_once("template.php"); ?>
<html lang="en-US">
    <head>
        <title>Login</title>
        <?php headInfo("Login", "Login", ["login"]); ?>
    </head>
    <body>
        <?php head(false); ?>
        <div id="pane">
            <h1>Bank Of Justin,</h1>
            <h2>Login</h2>
            <form method="post" action="bank_account.php" autocomplete="on">
                <label for="user">Username:</label>
                <input type="text" id="user" name="user" autofocus required><br/>
                <label for="pass">Password:</label>
                <input type="password" id="pass" name="pass" autocomplete="yes" required><br/>
                <input type="submit" id="submit-button" value="Submit">
            </form>
        </div>
        <?php foot(); ?>
    </body>
</html>