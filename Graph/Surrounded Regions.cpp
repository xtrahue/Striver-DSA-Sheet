class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>&board, vector<vector<bool>>&vis,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m && board[i][j]=='O' && !vis[i][j]){
            vis[i][j]=1 ;
            dfs(i+1,j,board,vis,n,m) ;
            dfs(i-1,j,board,vis,n,m) ;
            dfs(i,j+1,board,vis,n,m) ;
            dfs(i,j-1,board,vis,n,m) ;
        }

        return ;
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size() ;
        int m=board[0].size() ;

        vector<vector<bool>>vis(n,vector<bool>(m,0)) ;

        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis,n,m) ;
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis,n,m) ;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis,n,m) ;
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis,n,m) ;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X' ;
                }
            }
        }
    }
};
