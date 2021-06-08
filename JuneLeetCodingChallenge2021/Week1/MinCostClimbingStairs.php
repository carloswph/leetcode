<?php

class Solution {

    /**
     * @param Integer[] $cost
     * @return Integer
     */
    function minCostClimbingStairs($cost) {
        
        $n = count($cost);
        $s = $cost;
        
        for($i = 2; $i < $n; $i++) {
            $s[$i] += min($s[$i - 1], $s[$i - 2]);
    	}
        
        return min($s[$n - 1], $s[$n - 2]);
	}
}