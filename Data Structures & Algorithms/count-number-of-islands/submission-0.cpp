class Solution {
public:
    int n,m;
    vector<vector<bool>>vis;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool valid(int x, int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(int x, int y,vector<vector<char>>& grid){
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(valid(nx, ny)&&!vis[nx][ny]&&grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
