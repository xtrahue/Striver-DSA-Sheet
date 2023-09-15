class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> graph[])
    {
        // code here
       priority_queue<pair<int, int>, vector<pair<int, int>>, 
       greater<pair<int, int>>> st ;
      //weight,src,dst 
      st.push({0,0}) ;
    
      vector<bool>vis(n,0) ;
      
      int sum=0 ;
    
      while(!st.empty()){
        //auto it=*(st.begin()) ;
        auto it=st.top() ;   
        int wgt=it.first ;
        int node = it.second ;
        st.pop() ;
    
        //st.erase(it) ;
        if (vis[node] == 1)
          continue;
    
        vis[node]=1 ;
        sum+=wgt ;
        for (auto it : graph[node]) {
          int newnode = it[0] ;
          int w2 = it[1] ;
    
          if(!vis[newnode]){
            st.push({w2,newnode}) ;
          }
        }
        
      }
    
      return sum ;
    }
};
