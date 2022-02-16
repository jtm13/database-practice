<!DOCTYPE html>
<html lang="en-US">
    <head>
        <title>BankAccount</title>
        <link rel="stylesheet" type="text/css" href="normalize.css">
    </head>
    <body id="Bank-body">
        <?php
         include("bankAccount.php");
         include_once("private/defined.php");
         $conn = false;
         try {
            $test = new PDO("mysql:host=" . SERVER_NAME . ";dbname=" . DATABASE_NAME, USERNAME, PASSWORD);
           // set the PDO error mode to exception
           $test->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
           $stmt = $test->prepare("CALL getUserInfo();");
            $stmt->execute();
             
            // set the resulting array to associative
            $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
            foreach(new RecursiveArrayIterator($stmt->fetchAll()) as $it) {
                $conn = true;
                $ev = new BankAccount($it);
                echo $ev->info();
            }
         } catch(PDOException $e) {
             $conn = true;
           echo "<h1><b>Connection failed:</b></h1>\n<p>Sorry, we could not connect with the server.
            Try again in a few hours.</p>" /*. $e->getMessage()*/;
         }
         if (!$conn) {
             echo "<p>You do not have an account with us.</p>";
         }
        ?>
    </body>
</html>