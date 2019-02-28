<?php

$city = $_POST['city'];
$month = $_POST['month'];
$year = $_POST['year'];

echo "$city <br>";
echo "$month <br>";
echo "$year <br>";


$weather = $_POST['weather'];



foreach($weather as $w){
  echo "$w <br>";  
}


?>
