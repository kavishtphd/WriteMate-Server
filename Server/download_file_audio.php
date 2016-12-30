<?php

$download_url = $_GET['url'];

$curl_out  = "curl -X POST --form \"url=" . $download_url;
$curl_out .=  "\" --form \"apikey=44d71cb8-4a95-4085-93ae-a77f8f9f234b\" https://api.havenondemand.com/1/api/async/recognizespeech/v1";

$output = shell_exec($curl_out);

$jsondata = json_decode($output,true);
$text =  $jsondata["actions"][0]["result"][0]["content"];

$f_file = fopen("/Library/WebServer/Documents/test.txt", "w");

fwrite($f_file, $text);
fclose($f_file);

shell_exec("sudo ./a.out");

?>
