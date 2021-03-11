<?php
    $sql_db = new mysqli("localhost", "root", "", "bici");
    $res = $sql_db->query('');
    $res = $res->fetch_assoc();
    $sql_db -> close();
?>