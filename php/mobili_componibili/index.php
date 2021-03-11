<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Home</title>
    <link rel="stylesheet" href="style.css">
    <style>
    </style>
</head>
<body>
    <img src="https://assets-global.website-files.com/5f188f434782adfc099948a6/5f2b6b573a2108c3c48f1cb0_silkroad.jpeg" width = "150" height = "100">
    <form method="post" action="auth.php">
        <label>Username</label><input type="text" name="user">
        <br>
        <label>Password</label><input type="text" name="password">

        <input type="submit" value="Accedi" id="submit" onClick="redirect()">
        <br>
        <input type="radio" name="option" value="dati">
        <label>Consultazione dati</label>
        <input type="radio" name="option" value="vetrina">
        <label>Vetrina</label>
    </form>

    <script>
        /*function redirect(){
            let value = null;
            document.getElementsByName('option').forEach((option) => {
                if (option.checked) {
                    value = option.value
                }
            })
            document.getElementById("submit").formAction = value + ".php"
        }*/
    </script>
</body>

</html>
