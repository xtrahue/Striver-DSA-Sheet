void solveit(int i,vector<vector<int>> &adj,vector<bool>&vis,vector<int> &ans){
    vis[i]=1 ;
    ans.push_back(i) ;
    
    for(auto it:adj[i]){
        if(!vis[it]){
            solveit(it,adj,vis,ans) ;
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>adj(V) ;
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]) ;
        adj[edges[i][1]].push_back(edges[i][0]) ;
    }
    vector<bool>vis(V,0) ;
    
    vector<vector<int>>res;

    for(int i=0;i<V;i++){
        vector<int>ans ;
        if(!vis[i]){
            solveit(i,adj,vis,ans);
            res.push_back(ans) ;
        }
        
    }
    
    
    return res ;
}
