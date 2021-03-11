<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Articoli</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <style>
    </style>
</head>
<body>
    <div id="title">Articoli</div>
    <?php
        $sql_db = new mysqli("localhost", "root", "", "mobili_componibili");

        if ($sql_db->connect_errno) {
            echo '<p>Failed to connect to MySQL: '.$sql_db->connect_error .'</p>';
        }
        else{
            $res = $sql_db->query('SELECT * from articoli');
        
            echo '<table>';
            echo '<th>Codice</th><th>Categoria</th><th>Descrizione</th><th>Prezzo</th><th>Spese di trasporto</th><th>Modifica</th><th>Elimina</th><th>Componenti</th><th>Ordini</th>';
            foreach($res as $row){
                echo '<tr>';
                echo $row['id_articolo'] ? '<td>'.$row['id_articolo'].'</td>' : '<td><i class="material-icons">clear</i></td>';
                echo $row['cod_categoria'] ? '<td>'.$row['cod_categoria'].'</td>' : '<td><i class="material-icons">clear</i></td>';
                echo $row['descrizione'] ? '<td>'.$row['descrizione'].'</td>' : '<td><i class="material-icons">clear</i></td>';
                echo $row['prezzo'] ? '<td>'.$row['prezzo'].'</td>' : '<td><i class="material-icons">clear</i></td>';
                echo $row['spese_trasporto'] ? '<td>'.$row['spese_trasporto'].'</td>' : '<td><i class="material-icons">clear</i></td>';
                echo '<td><button onClick=\'editMode("'.$row["id_articolo"].'")\'><i class="material-icons">mode_edit</i></button></td>';
                echo '<td><button onClick=\'deleteForever("'.$row["id_articolo"].'")\'><i class="material-icons">delete_forever</i></button></td>';
                echo '<td><button onClick=\'showComponentes("'.$row["id_articolo"].'")\'><i class="material-icons">preview</i></button></td>';
                echo '<td><button onClick=\'showOrders("'.$row["id_articolo"].'")\'><i class="material-icons">preview</i></button></td>';
                echo '</tr>';
            }
            echo '</table>';
        }

        $sql_db -> close();
    ?>

    <script>
        //jquery ?

        function editMode(id){
            window.alert(id)
        }
        function deleteForever(id){
            var xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    window.alert('Risultato: \n' + this.responseText);
                }
            };
            xmlhttp.open("GET", "delete_article.php?id=" + id, true);
            xmlhttp.send();
        }
        function showComponentes(id){
            var xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    window.alert('Codici componenti: \n' + this.responseText);
                }
            };
            xmlhttp.open("GET", "get_components.php?id=" + id, true);
            xmlhttp.send();
        }
        function showOrders(id){
            var xmlhttp = new XMLHttpRequest();
            xmlhttp.onreadystatechange = function() {
                if (this.readyState == 4 && this.status == 200) {
                    window.alert('Codici ordini: \n' + this.responseText);
                }
            };
            xmlhttp.open("GET", "get_orders.php?id=" + id, true);
            xmlhttp.send();
        }
    </script>
</body>
</html>
