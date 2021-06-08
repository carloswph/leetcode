class Solution {

    // Sets a constant for modulo 10^9 + 7
    const int mod = 1e9 + 7;

private:
    // Helper function to return results as modulo 10^9 + 7
    long long int multi(long long int x, long long int y){

      return ((x % mod) * (y % mod)) % mod;
   }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.push_back(h);
        
        sort(verticalCuts.begin(), verticalCuts.end());
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.push_back(w);
        
        int x = 0;
        int y = 0;
        
        for (int i = 1; i < horizontalCuts.size(); i++) {
        
            x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        
        for (int i = 1; i < verticalCuts.size(); i++) {
            
            y = max(y, verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        return multi(x, y);
    }
};