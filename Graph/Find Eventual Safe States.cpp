//BFS ...reverse the adjacency matrix ...then outdegree(indegree after reversing)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size() ;
        vector<vector<int>>rev(n) ;
        vector<int>indeg(n) ;

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                rev[it].push_back(i) ;
                indeg[i]++ ;
            }
        }

        queue<int>qu ;

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                qu.push(i) ;
            }
        }

        vector<int>ans ;

        while(!qu.empty()){
            int node=qu.front() ;
            qu.pop() ;
            ans.push_back(node) ;

            for(auto it:rev[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    qu.push(it) ;
                }
            }
        }

        sort(ans.begin(),ans.end()) ;

        return ans ;
    }
};

//
