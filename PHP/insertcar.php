<!DOCTYPE html>
<html lang="en">
<head>
    <title>CSS Template</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

<form  method="post">
    <fieldset><legend align="center"> Enter car info below</legend>
        <p align="center"><input type="text" name="carMake" placeholder="Car make"></p>
        <p align="center"><input type="text" name="carModel" placeholder="Car model"></p>
        <p align="center"><input type="int" name="carYear" placeholder="Car year"></p>
        <p align="center"><input type="float" name="carPrice" placeholder="Car price"></p>
        <p align="center"><input type="submit" name="submit" value="submit"></p>
    </fieldset>
</form>


<?php
require('creds.php');
$dsn = "mysql:host=$DBHOST;dbname=$DBNAME;charset=$DBCHARSET";
$opt =
    [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION, PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_EMULATE_PREPARES => false,
    ];
$pdo = new PDO($dsn, $DBNAME, $DBPASS, $opt);
/* (isset($_POST['submit']) && $_POST['submit'] == 'true') */
if(isset($_POST['submit'])) {
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            if (empty($_POST["carMake"])) {
                echo "<script type= 'text/javascript'>alert('atleast enter in the car make...!');</script>"; /* looked everywhere but couldnt find the solution, it just ignores my if statment... i will need help on this */
            }
            else {
                $sql = "INSERT INTO midterm (carMake, carModel,carPrice,carYear)
                 VALUES ('".$_POST["carMake"]."','".$_POST["carModel"]."','".$_POST["carPrice"]."','".$_POST["carYear"]."')";
                 if ($pdo->query($sql)) {
                        echo "<script type= 'text/javascript'>alert('New Record Inserted Successfully');</script>";
                 } else {
                     echo "<script type= 'text/javascript'>alert('Data not successfully Inserted.');</script>";
                 }
        }
}

?>

<form action="index.php" method="post">
    <input type='submit' name='submit' value='Go back' class='Go back' />
</form>



