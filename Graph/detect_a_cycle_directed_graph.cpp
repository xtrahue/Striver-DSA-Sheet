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


//using khan's algorithm
bool isCyclic(int n, vector<int> adj[]) {
    vector<int> inDegree(n, 0); // Store in-degrees of nodes
    queue<int> q;

    // Calculate in-degrees
    for (int i = 0; i < n; i++) {
        for (int u : adj[i]) {
            inDegree[u]++;
        }
    }

    // Add nodes with in-degree 0 to the queue
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0; // Count of visited nodes

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;

        // Reduce in-degrees of neighbors
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If count of visited nodes is less than total nodes, cycle exists
    return cnt != n;
}
