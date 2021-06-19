class Solution {

public:
    
    bool ispal(string& str, int left, int right) {
        
        while (left < right) {            
            if (str[left++] != str[right--]) { return false; }
        }

        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> r;
        unordered_map<string, int> palmap;
        set<int> palset;
        
        int n = words.size();

        for (int i = 0; i < n; i++) {            
            palmap[words[i]] = i;
            palset.insert(words[i].size());
        }
        
        for (int i = 0; i < n; i++) {

            string str = words[i];
            int len = str.size();
            reverse(s.begin(), str.end());
        
            if (palmap.count(s) and palmap[str] != i) {                
                r.push_back({i, palmap[str]});
            }
        
            auto a = palset.find(len);
            
            for (auto j = palset.begin(); it != a; j++) {
        
                int d = *j;

                if (ispal(str, 0, len - d - 1) and palmap.count(str.substr(len - d))) {
                    r.push_back({i, palmap[str.substr(len - d)]});
                }
                if (ispal(str, d, len - 1) and palmap.count(str.substr(0, d))) {
                    r.push_back({palmap[str.substr(0, d)], i});
                }
            }
        }
        
        return r;
        
    }
};