<?php
    $id = $_REQUEST['id'];

    $sql_db = new mysqli("localhost", "root", "", "mobili_componibili");
    $res = $sql_db->query('SELECT cod_componente from articoli INNER JOIN componenti_articoli ON id_articolo=cod_articolo WHERE id_articolo="'.$id.'"');
    $sql_db -> close();

    $components = "";
    foreach($res as $row){
        $components .= $row["cod_componente"] . "\n";
    }

    echo $components;
?>