class Solution {
private:
    //binary Search function
    bool isPossible(vector<vector<int>>&nearest,int key,int n,int m){
        if(nearest[0][0]<key){
            return 0;
        }
        queue<pair<int,int>> qu ;
        qu.push({0,0}) ;
        
        vector<vector<bool>>vis(n,vector<bool>(m,0)) ;
        vis[0][0]=1 ;
        
        while(!qu.empty()){
            int x=qu.front().first ;
            int y=qu.front().second ;
            qu.pop() ;
            
            if(x==n-1 && y==m-1){
                return 1 ;
            }
            
            //immediate right
            if(x+1<n){
                if(!vis[x+1][y] && nearest[x+1][y]>=key){
                    vis[x+1][y]=1 ;
                    qu.push({x+1,y}) ;
                }
            }
            
            //immediate left
            if(x-1>=0){
                if(!vis[x-1][y] && nearest[x-1][y]>=key){
                    vis[x-1][y]=1 ;
                    qu.push({x-1,y}) ;
                }
            }
            
            //immediate up
            if(y+1<n){
                if(!vis[x][y+1] && nearest[x][y+1]>=key){
                    vis[x][y+1]=1 ;
                    qu.push({x,y+1}) ;
                }
            }
            
            //immediate down
            if(y-1>=0){
                if(!vis[x][y-1] && nearest[x][y-1]>=key){
                    vis[x][y-1]=1 ;
                    qu.push({x,y-1}) ;
                }
            }
        }
        
        return 0 ;
        
    }
    //This Function is used to generate any grid[i][j] element's nearest 1. 
    //Same as the gfg Problem "Distance of nearest cell having 1"
    vector<vector<int>>nearest(vector<vector<int>>&grid)
	{
        // No need to use two varriable n and m.Only one would do the job
	    int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue <pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[row][col]=steps;
            for(int i=0;i<4;i++){
                int nrow=row + drow[i];
                int ncol=col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dis;
	}
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size() ;
        int m= grid[0].size() ;
        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return 0;
        }
        
        vector<vector<int>>nearest_one =nearest(grid) ;
        
        int l=0,h=n,ans=0 ;
        while(l<=h){
            int mid =(l+h)/2 ;
            if(isPossible(nearest_one,mid,n,m)){
                ans=max(ans,mid) ;
                l=mid+1 ;
            }
            else{
                h=mid-1 ;
            }
        }
        
        
        return ans ;
    }
};
