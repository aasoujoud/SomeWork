<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/html">
<head>
    <title>CSS Template</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
<?php
require('creds.php');
$dsn = "mysql:host=$DBHOST;dbname=$DBNAME;charset=$DBCHARSET";
$opt =
    [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION, PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_EMULATE_PREPARES => false,
    ];
$pdo = new PDO($dsn, $DBNAME, $DBPASS, $opt);
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$CarID = $_GET['id'];
$stmt = $pdo->prepare("SELECT * FROM midterm WHERE cid=?");
$stmt->execute([$CarID]);
$user = $stmt->fetch();
$carMake = $user['carMake'];
$carModel = $user['carModel'];
$carYear = $user['carYear'];
$carPrice = $user['carPrice'];

echo '<form  method="post">';
echo '<fieldset><legend align="center"> Edit car Info</legend>';
echo '<p align="center"><input type="text" name="carMake" placeholder="Car make" value='." $carMake ".' ></p>';
echo '<p align="center"><input type="text" name="carModel" placeholder="Car model" value='." $carModel ".' ></p>';
echo '<p align="center"><input type="int" name="carYear" placeholder="Car year"  value='." $carYear ".' ></p>';
echo '<p align="center"><input type="float" name="carPrice" placeholder="Car price"  value='." $carPrice ".' ></p>';
echo '<p align="center"><input type="submit" name="submit" value="Update"></p>';
echo '</fieldset>';
echo '</form>';


    if(isset($_POST['submit'])) { /* Don't have enough time to fix it but it is changing you have to go back to index though */
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        if (empty($_POST["carMake"])) {
            echo "<script type= 'text/javascript'>alert('atleast have a car make!');</script>"; /* looked everywhere but couldnt find the solution, it just ignores my if statment... i will need help on this */
        }
        else {
            $sql = "UPDATE `midterm` SET `carMake` = '".$_POST["carMake"]."' , `carModel` =  '".$_POST["carModel"]."', `carPrice` = '".$_POST["carPrice"]."', `carYear` ='".$_POST["carYear"]."' WHERE `cid` = $CarID";
            if ($pdo->query($sql)) {
                echo "<script type= 'text/javascript'>alert('Car Updated succesfully!');</script>";
            }
            else {
                echo "<script type= 'text/javascript'>alert('Car was not updated succesfully!');</script>";
            }
        }
    }

    ?>

    <form action="index.php" method="post">
        <input type='submit' name='submit' value='Go back' class='Go back' />
    </form>

