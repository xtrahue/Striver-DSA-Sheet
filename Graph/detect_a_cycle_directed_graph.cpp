//using two vis vector...a collaboration of me and chatgpt
class Solution {
  private:
    bool dfs(int node,vector<bool>&res,vector<bool>&vis,vector<int> adj[]){
      if(res[node]){
        return 1;
      }
      if(vis[node]){
        return 0 ;
      }
      vis[node]=1 ;
      res[node]=1 ;
    
      
      for(auto it:adj[node]){
        //cout<<it<<" "<<vis[it]<<" " ; 
        if(dfs(it,res,vis,adj)){
          //cout<<it<<" " ;
          return true;
        }
      }
      res[node]=0 ;
      return 0 ;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<bool>vis(n,0) ;
      vector<bool>res(n,0) ;
    
      for(int i=0;i<n;i++){
        //cout<<i<<" ";
        if(!vis[i]){ 
          //cout<<i<<" " ;   
          bool x= dfs(i,res,vis,adj) ;
          //cout<<x<<endl ;
          if(x){
            //cout<<i<<" " ;
            return 1 ;
          }
        }
      }
      return 0 ;
    }
};
