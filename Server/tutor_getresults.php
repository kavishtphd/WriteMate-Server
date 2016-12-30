<?php

$file = fopen("tutor_result.txt", "r") or die("Unable to open file!");
$contents = fread($file,filesize("tutor_result.txt"));
fclose($file);

echo $contents;

?>


