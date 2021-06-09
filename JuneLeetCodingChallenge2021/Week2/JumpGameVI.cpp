class Solution {
    
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        int a = 0, b = 0;        
        int jump[n];
        
        jump[0] = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            
            if (jump[a] - i > k) { 
                a++;
            }
            
            nums[i] += nums[jump[a]];
            
            while (b >= a and nums[jump[b]] <= nums[i]) {
                b--;
            }
            
            jump[++b] = i;
        }
        
        return nums[0];
    }
};