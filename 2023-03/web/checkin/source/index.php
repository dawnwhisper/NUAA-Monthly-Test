<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Check in</title>
</head>
 
<style>
    body {
        text-align: center;
        left: 50%;
    }
 
    #container {
        
        margin: 0 auto;
        width: 900px;
        height: 900px;
        border: 1px solid black;
    }
    
    #uploads {
        
        margin: 0 auto;
        width: 1500px;
        border: 1px solid black;
    }
</style>
<body>
	

    <h1>Find your treasure😤</h1>
	
	
</body>
</html>

<?php
//highlight_file(__FILE__);
error_reporting(0);
$flag = "flag{y0u_g4t_the_Check_1n_treasure}";
$val1 = $_GET['val1'];
$val2 = $_GET['val2'];
$val3 = $_GET['val3'];
$val4 = $_GET['val4'];
$val5 = $_GET['val5'];
if (isset($_GET['val1']) && isset($_GET['val2']) && isset($_GET['val3']) && isset($_GET['val4']) && isset($_GET['val5']))
{   
	if ($val1 = md5($val1))
	{
		if ($val2 != $val3 && md5($val2) == md5($val3)){
			if($val4 !== $val5 && md5($val4) === md5($val5)){
				echo $flag;
			}
			else
				die("try again"); 
		}
		else
			die("you can't get flag");
	}
}
?>
