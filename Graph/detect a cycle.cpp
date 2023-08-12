//my code --> gives a tle.
class Solution {
  private:
    bool solveit(int curr_node,int prev_node,int node,int cnt,vector<int>adj[]){
        if(curr_node==node && cnt>2){
            return 1 ;
        }
        
        if(adj[curr_node].size()==1){
            return 0;
        }
        
        bool a=0 ;
        
        for(int i=0;i<adj[curr_node].size();i++){
            if(adj[curr_node][i]!=prev_node){
               a=a|| solveit(adj[curr_node][i],curr_node,node,cnt+1,adj) ;
               if(a){
                   return 1;
               }
            }
        }
        return a;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        for(int i=0;i<V;i++){
            if(solveit(i,i,i,0,adj)){
                return 1;
                break ;
            }
        }
        return 0;
    }
};




//striver's approach by BFS
class Solution {
  private:
    bool solveit(int src,vector<int>adj[],vector<bool>&vis){
        
        queue<pair<int,int>>qu ;
        qu.push({src,-1}) ;
        vis[src]=1 ;
        
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();
            
            for(int i=0;i<adj[node.first].size();i++){
                
                int k=adj[node.first][i] ;
                
                if(k!=node.second){
                    if(!vis[k]){
                        qu.push({k,node.first}) ;
                        vis[k]=1 ;
                    }
                    else{
                        return 1;
                    }
                }
            }
            
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool>vis(V,0) ;
        
        for(int i=0;i<V;i++){
            if(!vis[i] && solveit(i,adj,vis)){
                return 1;
            }
        }
        return 0;
    }
};
