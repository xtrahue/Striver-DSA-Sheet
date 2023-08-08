class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>&grid ,vector<vector<bool>>&vis,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && grid[i][j]==1){
            vis[i][j]=1 ;
            dfs(i+1,j,grid,vis,n,m) ;
            dfs(i,j+1,grid,vis,n,m) ;
            dfs(i-1,j,grid,vis,n,m) ;
            dfs(i,j-1,grid,vis,n,m) ;
        }

        return ;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size() ;
        int m=grid[0].size() ;

        vector<vector<bool>>vis(n,vector<bool>(m,0)) ;

        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,grid,vis,n,m) ;
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,grid,vis,n,m) ;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]){
                dfs(i,0,grid,vis,n,m) ;
            }
            if(!vis[i][m-1] && grid[i][m-1]){
                dfs(i,m-1,grid,vis,n,m) ;
            }
        }

        int cnt=0 ;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    cnt++ ;
                }
            }
        }

        return cnt ;
    }
};
