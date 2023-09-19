static bool cmp(vector<int>&a,vector<int>&b){
	return a[2]<b[2] ;
}
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

int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.
	sort(edges.begin(),edges.end(),cmp) ;
	Disjoint ds(n) ;
	int mst =0 ;

	for(auto it:edges){
		
		if(ds.findPar(it[0])!=ds.findPar(it[1])){
			mst+=it[2] ;
			ds.unionByRank(it[0], it[1]) ;
		}
	}

	return mst;
}
