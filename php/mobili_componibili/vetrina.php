<?php
    $sql_db = new mysqli("localhost", "root", "", "mobili_componibili");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Vetrina</title>
    <link rel="stylesheet" href="style.css">
    <style>
    </style>
</head>
<body>
    <div id="title">Sconti</div>
    <?php
        if ($sql_db->connect_errno) {
            echo "Failed to connect to MySQL: " . $sql_db->connect_error;
        }
        else{
            $res = $sql_db->query("SELECT id_articolo, descrizione, prezzo, discount FROM articoli WHERE discount IS NOT NULL;");
            echo '<table>';
            echo '<tr><th>Articolo</th><th>Descrizione</th><th>Prezzo</th><th>Prezzo Originale</th></tr>';
            foreach($res as $row){
                echo "<tr><td>" . $row['id_articolo'] . "</td><td>" . $row['descrizione'] . "</td><td>" . $row['prezzo'] * $row['discount']/100 . "</td><td><del>" . $row['prezzo'] . "</del></td></tr>";
            }
            echo '</table>';
        }
    ?>
</body>
</html>
<?php
    mysqli_close($sql_db)
?>