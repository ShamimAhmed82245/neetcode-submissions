class Solution {
public:
    int n,m;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0||y<0 ||x>=n||y>=m || grid[x][y]==0){
            return 0;
        }
        grid[x][y] = 0;
        int area = 1;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            area+=dfs(grid, nx, ny);
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
