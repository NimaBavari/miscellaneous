<?php
/**
* @Author: Nima Bavari <nima.bavari@gmail.com>
* @date: June 17, 2017
**/

function mazeConverter($input) {
	$input = str_split($input);
	$output = '';
	$temp = array();
	$numChar = array();
	foreach ($input as $char) {
		if (!in_array($char, $temp)) {
			$temp[] = $char;
			$numChar[$char] = 0;
		}
		++$numChar[$char];
	}

	foreach ($numChar as $char => $value) {
		$output .= ($value == 1) ? $char : (string) $value . $char
	}

	return $output;
}

echo mazeConverter('aebeddaaadcjeejjbnmm');