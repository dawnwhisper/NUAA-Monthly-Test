<?php
    error_reporting(0);
    if(isset($_GET['code'])){
        $code=$_GET['code'];
        if(preg_match("/[A-Za-z0-9^~]+/",$code)){
            die("NO.");
        }
        @eval($code);
    }
    else{
        highlight_file(__FILE__);
    }

?>
