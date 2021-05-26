<?php

/**
 * No need of dealing with arrays or calculating all necessary numbers to
 * total the sum. The only thing you need to do is to analyze the digits
 * individually. The largest single digit (let's say, an 8) indicates the
 * minimum number of "deci-binaries" to reach the number.
 * 
 * Having that in mind, PHP offers a good support for solving the problem.
 * With str_split() we rapidly convert the string in an array of digits.
 * Then, with max(), we find the largest digit in the newly created array.
 */

class Solution {

    /**
     * @param String $n
     * @return Integer
     */
    function minPartitions($n) {

        $a = str_split($n);
        $m = max($a);
        return $m;
    }
}