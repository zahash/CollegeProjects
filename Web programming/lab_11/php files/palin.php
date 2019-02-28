<?php

$num = $_POST['num'];
echo "num : $num <br>";

$temp = $num;
$revnum = 0;  
while ($num > 1){
  	$rem = $num % 10;  
	$revnum = ($revnum * 10) + $rem;  
	$num = ($num / 10);   
}  

echo "revnum : $revnum <br>";

if ($temp == $revnum) {
	echo "Palindrome!!";
}

?>
