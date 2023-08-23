// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        vector<vector<int>>graph(n) ;

        for(auto x:edges){
            graph[x[0]].push_back(x[1]) ;
            graph[x[1]].push_back(x[0]) ;
        }
    
        queue<pair<int,int>>qu ;
        qu.push({src,0}) ;
    
        vector<int>ans(n,INT_MAX) ;
    
        while(!qu.empty()){
            int node=qu.front().first ;
            int dist=qu.front().second ;
            qu.pop() ;
    
            ans[node]=min(dist,ans[node]) ;
    
            for(auto x:graph[node]){
                if(ans[x]>dist+1){
                    qu.push({x,dist+1}) ;
                }
            }
    
        }
    
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1 ;
            }
        }
    
        return ans ;
    }
};
