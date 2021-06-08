class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        int n = nums.size();
        int c = 1;
        
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        
        for(int i = 0; i < n; i++) {
            
            if(!s.count(nums[i] - 1)) {
                
                int th = nums[i];
                int cc = 0;
                
                while(s.find(th) != s.end()) {
                    
                    cc++;
                    th++;
                }
                
                c = max(c, cc);
            }
        }
        
        if(nums.size() == 0) { return 0;}
        
        return c;
    }
};