//using DFS
class Solution
{
    private:
    void dfs(int node,vector<int>adj[],vector<int>&st,vector<bool>&vis){
        vis[node]=1 ;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,st,vis) ;
            }
        }
        st.push_back(node) ;
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>vis(V,0) ;
	    vector<int>st ;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,st,vis) ;
	        }
	    }
	    
	    reverse(st.begin(),st.end()) ;
	    
	    return st ;
	}
};


//Using BFS --> Khan's algorithm
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> grid[]) 
	{
	    // code here
	    vector<int>indeg(V,0) ;
	    
	    for(int i=0;i<V;i++){
	        for(auto it:grid[i]){
	            indeg[it]++ ;
	        }
	    }
	    
	    queue<int>qu ;
	    
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                qu.push(i) ;
            }
        }
    
        vector<int>ans ;
        
        while(!qu.empty()){
            int n1=qu.front() ;
            qu.pop() ;
            ans.push_back(n1) ;
    
            for(auto it:grid[n1]){
                indeg[it]-- ;
                if(indeg[it]==0){
                    qu.push(it) ;
                }
            }
        }
    
        return ans ;
	}
};
