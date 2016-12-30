<?php

$file = fopen("concept.txt", "r") or die("Unable to open file!");
$contents = fread($file,filesize("concept.txt"));
fclose($file);

echo $contents;

?>
