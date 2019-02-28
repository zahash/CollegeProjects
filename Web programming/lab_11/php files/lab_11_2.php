<!DOCTYPE html>
<html>
<head>
	<title> zahash </title>
</head>

<body>
	<form name="f" action="lab_11_2_response.php" method="post">
		<input type="text" name="city">
		<input type="text" name="month">
		<input type="text" name="year"> <br>
		
		<input type="checkbox" name="weather[]" value="snow"> snow <br>
		<input type="checkbox" name="weather[]" value="wind"> wind <br>
		<input type="checkbox" name="weather[]" value="sunshine"> sunshine <br>
		<input type="checkbox" name="weather[]" value="cloud"> cloud <br>
		<input type="checkbox" name="weather[]" value="rain"> rain <br>
		<input type="checkbox" name="weather[]" value="hail"> hail <br>
		<input type="checkbox" name="weather[]" value="sleet"> sleet <br>
		
		<input type="submit" name="subbtn">
	</form>


	<form name="f2" action="palin.php" method="post">
		<input type="text" name="num"> 
		<input type="submit" name="subbtn2" value="palindrome">
	</form>

</body>
</html>
