<?php

$conn = mysqli_connect("localhost", "root", "", "business");

if (!$conn){
	echo "connection failed!!!<br>";
}
else{
	echo "Successfully connected <br>";
}

mysqli_query($conn, "INSERT INTO `vegetables` VALUES ('tomatoes', 50)");

mysqli_query($conn, "INSERT INTO `vegetables` VALUES ('brinjal', 10)");

mysqli_query($conn, "INSERT INTO `vegetables` VALUES ('potato', 40)");

$vegname = $_POST["vegname"];
$cost = $_POST["cost"];

if (isset($_POST["update"])){
	$check = mysqli_query($conn, "UPDATE `vegetables` SET cost = '$cost' WHERE vegname = '$vegname'");
}

if (isset($_POST["delete"])){
	$check = mysqli_query($conn, "DELETE FROM `vegetables` WHERE vegname='$vegname'");
}


if (isset($_POST["display"])){

	$vendorname = $_POST["vegname"];

	$check = mysqli_query($conn, "SELECT * FROM `vegetables` INNER JOIN `vendors` on vegetables.vegname = vendors.vegname and vendors.vendorname = '$vendorname'");

	print_r(mysqli_fetch_array($check));

	
	
}



mysqli_close($conn);

if ($check){
echo "Done!!";
}
?>