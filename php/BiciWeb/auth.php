<?php
    session_start();
    if(!isset($_SESSION["username"]) || !isset($_SESSION["password"])){
        $_SESSION["username"] = $_POST['user'];
        $_SESSION["password"] = $_POST['password'];
    }

    $sql_db = new mysqli("localhost", "root", "", "bici");
    $res = $sql_db->query('SELECT password FROM amministratori WHERE username ="'.$_SESSION["username"].'"');
    $res = $res->fetch_assoc();
    $sql_db -> close();
    if(hash('sha256', $_SESSION["password"]) == $res['password']){
        header('Location: admin.php');
    }
    else{
        header('Location: login.php');
    }
?>