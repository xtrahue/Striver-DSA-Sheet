class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0) ;
        queue<int>qu ;
        qu.push(0) ;
        
        vector<int>ans ;
        
        while(!qu.empty()){
            int x=qu.front() ;
            qu.pop() ;
            ans.push_back(x) ;
            
            for(int i=0;i<adj[x].size();i++){
                if(!vis[adj[x][i]]){
                    qu.push(adj[x][i]) ;
                    vis[adj[x][i]]=1 ;
                }
            }
        }
        
        return ans ;
    }
};
