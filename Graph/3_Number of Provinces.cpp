class Solution {
private:
    void solveit(int i,vector<vector<int>>&adj,vector<bool>&vis){
        vis[i]=1 ;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                solveit(it,adj,vis) ;
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size()+1 ;

        vector<vector<int>>adj(n) ;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1) ;
                }
            }
        }

        vector<bool>vis(n,0) ;
        int cnt=0 ;

        for(int i=1;i<n;i++){
            if(!vis[i]){
                cnt++ ;
                solveit(i,adj,vis) ;
            }
        }

        return cnt ;
    }
};
