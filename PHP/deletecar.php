
<form  method="post">
    <fieldset><legend align="center"> Enter car info below</legend>
        <p align="center"><input type="text" name="carModel" placeholder="Car model"></p>
        <p align="center"><input type="submit" name="submit" value="Delete"></p>
    </fieldset>
</form>

<?php
/*         <p align="center"><input type="text" name="carModel" placeholder="Car model"></p>
*/
require('creds.php');
$dsn = "mysql:host=$DBHOST;dbname=$DBNAME;charset=$DBCHARSET";
$opt =
    [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION, PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_EMULATE_PREPARES => false,
    ];
$pdo = new PDO($dsn, $DBNAME, $DBPASS, $opt);

 if( isset($_REQUEST['submit']) ) {
     if (empty($_POST["carModel"])) {
         echo "<script type= 'text/javascript'>alert('atleast enter in the car make...!');</script>";
     } else {
         $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
         $carModelPost = $_POST['carModel'];
         $sql = "DELETE FROM midterm WHERE carModel='$carModelPost'";
         if ($pdo->query($sql)) {
             echo "<script type= 'text/javascript'>alert('Car was deleted!');</script>";
         } else {
             echo "<script type= 'text/javascript'>alert('Car was not deleted!');</script>";
         }
     }
 }
 ?>



<form action="index.php" method="post">
    <input type='submit' name='submit' value='Go back' class='Go back' />
</form>
