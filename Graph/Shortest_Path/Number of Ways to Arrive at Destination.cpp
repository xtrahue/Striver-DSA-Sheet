class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        
        vector<vector<pair<int,int>>>adj(n) ;

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]}) ;
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long>dist(n,LONG_MAX) ;
        vector<long long>ways(n,0) ;

        set<pair<long long,int>>st;
        st.insert({0,0}) ;
        dist[0]=0;
        ways[0]=1 ;

        while(!st.empty()){
            auto ptr=*(st.begin()) ;
            int node =ptr.second ;
            long long dis=ptr.first ;
            st.erase(ptr) ;

            for(auto it:adj[node]){
                int n1=it.first ;
                int d=it.second ;

                if(d+dis<dist[n1]){
                    dist[n1]=(d+dis);
                    ways[n1]=ways[node] ;
                    st.insert({dist[n1],n1}) ;
                }
                else if(d+dis==dist[n1]){
                    ways[n1]=(ways[n1]+ways[node])%mod ;
                }
            }
        }

        return ways[n-1] ;
    }
};
