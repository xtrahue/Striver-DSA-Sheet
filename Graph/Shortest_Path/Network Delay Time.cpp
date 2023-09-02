class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1) ;
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]}) ;
        }

        set<pair<int,int>>st ;
        st.insert({0,k}) ;
        vector<int>dur(n+1,INT_MAX) ;
        dur[k]=0 ;


        while(!st.empty()){
            auto it=*(st.begin()) ;
            int time=it.first ;
            int src=it.second ;
            st.erase(it) ;

            for(auto node:adj[src]){
                int dst=node.first ;
                int dt=node.second ;

                if(dt+time<dur[dst]){
                    dur[dst]=dt+time ;
                    st.insert({dur[dst],dst}) ;
                }
            }
        }

        int mini=INT_MIN ;

        for(int i=1;i<=n;i++){
            if(dur[i]==INT_MAX){
                return -1 ;
            }
            mini=max(mini,dur[i]) ;
        }

        return mini;
    }
};
