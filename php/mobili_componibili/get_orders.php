<?php
    $id = $_REQUEST['id'];

    $sql_db = new mysqli("localhost", "root", "", "mobili_componibili");
    $res = $sql_db->query('SELECT cod_ordine from articoli INNER JOIN ordini_articoli ON id_articolo=cod_articolo WHERE id_articolo="'.$id.'"');
    $sql_db -> close();

    $orders = "";
    foreach($res as $row){
        $orders .= $row["cod_ordine"] . "\n";
    }

    echo $orders;
?>