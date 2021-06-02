class Solution {
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.length();
        int m = s2.length();
        int o = s3.length();
        
        if(n + m != o) {
            return 0;
        }
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 0; i <= n; i++) {

            for(int j = 0; j <= m; j++) {
                
                int k = i + j;
                
                if(i == 0) {
                    if(j == 0) {
                        
                        dp[i][j] = 1;
                        
                    } else {
                        
                        dp[i][j] = s2[j - 1] == s3[k - 1] && dp[i][j - 1];
                        
                    }
                    
                } else if(j == 0) {
                    
                    dp[i][j] = s1[i - 1] == s3[k - 1] && dp[i - 1][j];
                    
                } else {
                    
                    dp[i][j] = (s1[i - 1] == s3[k - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[k - 1] && dp[i][j - 1]);
                    
                }
            }    
        }
        
        return dp[n][m];
    }
};