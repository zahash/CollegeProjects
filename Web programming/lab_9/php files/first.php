<?php

// even or not
$num = (int)28;

echo "EVEN or not : ";
if ($num%2 == 0) {
    echo "Yes<br>";
}
else {
    echo "No<br>";
}


// prime checker
echo "Prime Checker (1|0) : ";

$n = 25;
$flag = 1;
for ($i=2; $i <= sqrt($n)+1; $i++) {
    if ($n%$i == 0) {
        $flag = 0;
        break;
    }
}
echo "$flag <br>";


// armstrong
$n = "372";
$sum = 0;

for ($i=0; $i < 3; $i++) {
    $sum = $sum + pow((int)substr($n, $i, 1), 3) ;
}

if ($sum == $n) {
    echo "Armstrong <br>" ;
}
else{
    echo "Not Armstrong <br>";
}


// simple interest
$n = 53;
$interest = 5;

$new = (1 + ($interest/100)) * $n;
echo "Simple interest : $new";


?>
