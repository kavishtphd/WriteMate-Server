<?php

$download_url = $_GET['url'];

$curl_out  = "curl -X POST --form \"url=" . $download_url;
$curl_out .=  "\" --form \"apikey=44d71cb8-4a95-4085-93ae-a77f8f9f234b\" https://api.havenondemand.com/1/api/sync/extractconcepts/v1"

$output = shell_exec($curl_out);

$jsondata = json_decode($output,true);
$text_0 =  $jsondata["concepts"][0]["concept"];
$text_1 =  $jsondata["concepts"][1]["concept"];
$text_2 =  $jsondata["concepts"][2]["concept"];
$text_3 =  $jsondata["concepts"][3]["concept"];
$text_4 =  $jsondata["concepts"][4]["concept"];

$f_file = fopen("/Library/WebServer/Documents/concepts.txt", "w");

fwrite($f_file, $text_0);
fwrite($f_file, $text_1);
fwrite($f_file, $text_2);
fwrite($f_file, $text_3);
fwrite($f_file, $text_4);
fclose($f_file);


?>
