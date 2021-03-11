<?php
    $user = $_POST['user'];
    $password = $_POST['password'];
    $option = $_POST['option'];

    $sql_db = new mysqli("localhost", "root", "", "auth");
    $res = $sql_db->query('SELECT password FROM accounts WHERE username ="'.$user.'"');
    $res = $res->fetch_assoc();
    $sql_db -> close();
    if($password == $res['password']){
        header('Location: '. $option . '.php');
    }
    echo get_object_vars($res);
?>