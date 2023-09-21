class Disjoint{
    private:
        vector<int>rank,parent,size ;
    public:      
        Disjoint(int n){
            rank.resize(n+1,0) ;
            parent.resize(n+1) ;
            size.resize(n+1) ;

            for(int i=0;i<=n;i++){
                parent[i]=i ;
                size[i]=1 ;
            }
        }

        int findPar(int node){
            if(parent[node]==node){
                return node ;
            }
            return parent[node]=findPar(parent[node]) ;
        }

        void unionByRank(int a,int b){
            int pa=findPar(a) ;
            int pb=findPar(b) ;

            if(pa==pb){
                return ;
            }

            int ra=rank[pa] ;
            int rb=rank[pb] ;

            if(ra<rb){
                parent[pa]=pb ;

            }
            else if(rb<ra){
                parent[pb]=pa ;
            }
            else{
                parent[pb]=pa ;
                rank[pa]++ ;
            }
        }


        void unionBySize(int a,int b){
            int pa=findPar(a) ;
            int pb=findPar(b) ;

            if(pa==pb){
                return ;
            }

            int sa=size[pa] ;
            int sb=size[pb] ;

            if(sa<sb){
                parent[pa]=pb ;
                size[pb]+=size[pa] ;
            }
            else{
                parent[pb]=pa ;
                size[pa]+=size[pb] ;
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size() ;
        unordered_map<string,int>mp ;
        Disjoint ds(n) ;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j] ;

                if(mp.find(s)!=mp.end()){
                    ds.unionByRank(i,mp[s]) ;
                }
                else{
                    mp[s]=i ;
                }
            }
        }

        vector<vector<string>>ans ;
        vector<string>temp[n] ;

        for(auto it:mp){
            int x=ds.findPar(it.second) ;
            temp[x].push_back(it.first) ;
        }

        for(int i=0;i<n;i++){
            if(temp[i].size()==0){
                continue ;
            }
            sort(temp[i].begin(),temp[i].end()) ;

            vector<string>t ;
            t.push_back(accounts[i][0]) ;
            for(auto it:temp[i]){
                t.push_back(it) ;
            }

            ans.push_back(t) ;
        }

        return ans ; 
    }

};
