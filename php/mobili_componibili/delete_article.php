<?php
    $id = $_REQUEST['id'];

    $sql_db = new mysqli("localhost", "root", "", "mobili_componibili");
    $res = $sql_db->query('DELETE FROM articoli WHERE id_articolo="'.$id.'"');
    $sql_db -> close();

    echo "Done";
?>