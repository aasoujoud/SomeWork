<?php
/**
 * Midterm
 * 
 * Grade: 75 / 100
 * I could not find the live project on the cis linux server, be sure to put links in your comments.
 */
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>CSS Template</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <?php
require( 'creds.php');

$dsn = "mysql:host=$DBHOST;dbname=$DBNAME;charset=$DBCHARSET";
$opt =
    [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION, PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_EMULATE_PREPARES => false,
    ];

$pdo = new PDO($dsn, $DBNAME, $DBPASS, $opt);

$qry = 'SELECT * FROM midterm';
$stmt = $pdo->query( $qry );
while($row = $stmt->fetch()) {
    echo '<a   style="text-decoration: none" href="updatecar.php?id='.$row['cid'].'"> '."<p>" . $row['cid'] ." | " . $row['carMake'] ." | " .$row['carModel'] ." | ". $row['carYear'] ." | ".$row['carPrice'] ."</p>".'</a>';
    echo '<p>-------------------------------------------</p>';
}
$averagePrice = $averagePrice / $carNumbers;
echo '<br>';
echo "Cars number: " . $carNumbers;
echo '<br>';
echo "Cars price average: " . $averagePrice;
echo '<br>';
echo "--------------------------------------";
?>
<form action="insertcar.php" method="post">
     <input type='submit' name='submit' value='Insert car' class='InsertCar' />
</form>

<form action="deletecar.php" method="post">
    <input type='submit' name='submit' value='Delete car' class='DeleteCar' />
</form>

