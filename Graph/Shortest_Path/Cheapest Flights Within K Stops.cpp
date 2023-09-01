class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n); 

        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]}) ;
        }

        queue<pair<int,pair<int,int>>>st;

        vector<int>cp(n,INT_MAX) ;
        cp[src]=0 ;
        //cost,{node,steps}
        st.push({0,{src,-1}}) ;

        while(!st.empty()){
            auto it=st.front();
            
            int cost=it.first ;
            int node = it.second.first ;
            int op=it.second.second ; 
            st.pop() ;
            //st.erase(it) ;

            if(op>k){
                continue ;
            }
            for(auto t:adj[node]){
                int c1=t.second;
                int n1=t.first ;

                if(cost+c1<cp[n1] && op+1<=k){
                    cp[n1]=cost+c1 ;
                    st.push({cost+c1,{n1,op+1}}) ;
                }
            }
        }

        if(cp[dst]!=INT_MAX){
            return cp[dst] ;
        }

        return -1;
    }
};
