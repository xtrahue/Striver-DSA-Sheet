class Solution {
private:
    bool solveit(int node,vector<int>&color,int cell_clr,vector<vector<int>>&graph){
        color[node]=cell_clr ;

        for(auto it:graph[node]){
            if(color[it]==-1 && !solveit(it,color,!cell_clr,graph)){
                return false ;
            }
            else if(color[it]==cell_clr){
                return false ;
            }
        }
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size() ;
        vector<int>color(n,-1) ;

        for(int i=0;i<n;i++){
            if(color[i]==-1 && !solveit(i,color,1,graph)){
                return false ;
            }
        }
        return true ;
    }
};
