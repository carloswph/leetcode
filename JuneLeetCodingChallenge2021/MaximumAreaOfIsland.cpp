class Solution {

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size(), m = grid[0].size(), res = 0;
        m_checked.assign(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, checkdfs(grid, i, j));
            }
        }

        return res;
    }
    
    vector<vector<int>> m_checked;
    vector<int> x_points = {-1, 1, 0, 0}, y_points = {0, 0, 1, -1};
    int n, m, res;
    
    int checkdfs(vector<vector<int>>& grid, int x, int y) {

        if (!validpos(x, y) || m_checked[x][y] || !grid[x][y]) 
            return 0;
        
        m_checked[x][y] = true;
        int res = 1;
        
        for (int i = 0; i < 4; i++)
            res += checkdfs(grid, x + x_points[i], y + y_points[i]);

        return res;
    }
    
    bool validpos(int x, int y) {
        
        return !(x < 0 || x >= n || y < 0 || y >= m);
    }
};