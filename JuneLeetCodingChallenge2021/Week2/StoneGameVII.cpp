class Solution {

public:
    
    int helper(int left, int right, vector<int>& stones, int sum, vector<vector<int>>& dp){
        
        if(left == right) {
            return 0;
        }
        
        if(right - left == 1) {
            return max(stones[left], stones[right]);
        }
        
        if(dp[left][right] != -1) {
            return dp[left][right];
        }
        
        int removeLeft = sum - stones[left] - helper(left + 1, right, stones, sum - stones[left], dp);
        int removeRight = sum - stones[right] - helper(left, right - 1, stones, sum - stones[right], dp);
        
        return dp[left][right] = max(removeLeft, removeRight);
    }
    
    int stoneGameVII(vector<int>& stones) {
        
        int n = stones.size();
        int sum = 0;
        
        vector<vector<int>> dp(n,vector<int>(n, -1));
        
        for(int i = 0; i < n; i++) {
            sum += stones[i];
        }
        
        return helper(0, n - 1, stones, sum, dp);
    }  
};