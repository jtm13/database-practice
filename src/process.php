<?php

function xml_create(string $meat) {
    echo '<?xml version="1.0" encoding="UTF-8"?>
        <ROOT>
            ' . $meat . '
        </ROOT>';
}

session_start();
if (!isset($_SESSION["User"]) || !isset($_SESSION["Pass"])) {
    xml_create("<ERROR>Cannot get credentials</ERROR>");
    http_response_code(400);
    exit();
}
if (!isset($_REQUEST["value"]) || !isset($_REQUEST["method"])) {
    xml_create("<ERROR>Server must have parameters!</ERROR>");
    http_response_code(400);
    exit();
}
$value = $_REQUEST["value"];
$method = $_REQUEST["method"];

if ($method === "signOut") {
    session_destroy();
    xml_create("<URL>login.php</URL>");
    http_response_code(300);
    exit();
}

require_once("bankAccount.php");
require_once("private/defined.php");
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
    
    $account = null;
    // set the resulting array to associative
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
    foreach(new RecursiveArrayIterator($stmt->fetchAll()) as $it) $account = new BankAccount($it);
    $stmt->closeCursor();
    if ($account === null) {
        xml_create("<ERROR>Cannot get account</ERROR>");
        http_response_code(400);
        exit();
    }
    $stmt = $test->prepare("CALL update_Money(:user,:money,:debt);");
    $stmt->bindParam(":user", $user);
    $stmt->bindParam(":money", $money);
    $stmt->bindParam(":debt", $debt);
    $user = $_SESSION["User"];
    $truth = true;
    switch($method) {
        case "deposit":
            $truth = $account->deposit($value);
            break;
        case "withdraw":
            $truth = $account->withdraw($value);
            break;
        case "loan":
            $truth = $account->loan($value);
            break;
        case "payBack":
            $truth = $account->payBack($value);
            break;
        default:
            $truth = false;
    }
    if ($truth === false) {
        xml_create("<ERROR>Cannot process current transaction</ERROR>");
        http_response_code(400);
        exit();
    }
    $money = $account->getMoney();
    $debt = $account->getDebt();
    $stmt->execute();
    $stmt->closeCursor();
    xml_create('<USER>
            <MONEY>' . $money . '</MONEY>
            <DEBT>' . $debt . '</DEBT>
            <NET>' . $account->getNet() . '</NET>
        </USER>');
} catch(PDOException $e) {
    xml_create("<ERROR>Connection failed</ERROR>"); // . $e->getMessage());
    http_response_code(500);
    exit();
}
?>