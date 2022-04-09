<?php
 include("bankAccount.php");
 include_once("private/defined.php");
 $conn = false;
 try {
    $test = new PDO("mysql:host=" . SERVER_NAME . ";dbname=" . DATABASE_NAME, USERNAME, PASSWORD);
    // set the PDO error mode to exception
    $test->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $test->prepare("CALL getUserInfo(:user,:pass);");
    $stmt->bindParam(":user", $user);
    $stmt->bindParam(":pass", $pass);
    $user = $_SESSION["User"];
    $pass = $_SESSION["Pass"];
    $stmt->execute();
     
    // set the resulting array to associative
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
    foreach(new RecursiveArrayIterator($stmt->fetchAll()) as $it) {
        $conn = true;
        $ev = new BankAccount($it);
        echo $ev->info();
    }
    $stmt->closeCursor();
 } catch(PDOException $e) {
     $conn = true;
   echo "<h1><b>Connection failed:</b></h1>\n<p>Sorry, we could not connect with the server.
    Try again in a few hours.</p>" /*. $e->getMessage()*/;
 }
 if (!$conn) {
    header("Location: login.html", true);
    exit();
 }
?>