<?php

$file = fopen("output.txt", "r") or die("Unable to open file!");
$contents = fread($file,filesize("output.txt"));
fclose($file);

echo $contents;

?>
