class Solution {

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> performance(n);

        for(int i = 0; i < n; i++) {

            performance[i] = {efficiency[i],speed[i]};
        }
        
        sort(rbegin(performance), rend(performance));
        
        priority_queue<int, vector<int>, greater<int>> prior;
        long long int sum = 0;
        long long int res = 0;

        for(auto [eff, speed] : performance) {

            sum += speed;
            prior.push(speed);

            if(prior.size()>k) {
                
                sum -= prior.top();
                prior.pop();
            }

            res = max(res, sum * eff);
        }

        return res % (int)(1e9+7);
    }
};