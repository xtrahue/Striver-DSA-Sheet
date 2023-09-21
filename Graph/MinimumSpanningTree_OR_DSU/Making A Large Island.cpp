class Disjoint{     
    public: 
        vector<int>rank,parent,size ;     
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
    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size() ;
        int c=grid[0].size() ;

        Disjoint ds(r*c) ;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    continue ;
                }
                int k=i*c+j ;
                if(i+1<r){  
                    if( grid[i+1][j]){
                        ds.unionBySize(k,k+c) ;
                    }
                }

                if(j+1<c){  
                    if(  grid[i][j+1]){
                        ds.unionBySize(k,k+1) ;
                    }
                }

                if(i-1>=0){
                    if( grid[i-1][j]){
                        ds.unionBySize(k,k-c) ;
                    }
                }

                if(j-1>=0){  
                    if(  grid[i][j-1]){
                        ds.unionBySize(k,k-1) ;
                    }
                }
            }
        }

        int maxi=0 ;
        for(auto it:ds.size){
            maxi=max(maxi,it) ;
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int temp=1;
                int p1=-1,p2=-1,p3=-1,p4=-1 ;
                if(grid[i][j]==0){
                    if(i+1<r){  
                        if( grid[i+1][j]){
                            int x=ds.findPar((i+1)*c+j) ;
                            p1=x ;
                            temp+=ds.size[x] ;
                        }
                    }

                    if(j+1<c){  
                        if( grid[i][j+1]){
                        
                            int x=ds.findPar((i)*c+j+1) ;
                            if(p1!=x){
                                temp+=ds.size[x] ;
                                p2=x ;
                            }
                            
                        }
                    }

                    if(i-1>=0){
                        if(grid[i-1][j]){
                            int x=ds.findPar((i-1)*c+j) ;
                            if(x!=p1 && x!=p2){
                                temp+=ds.size[x] ;
                                p3=x ;
                            }
                            
                        }
                    }

                    if(j-1>=0){  
                        if(grid[i][j-1]){
                            int x=ds.findPar((i)*c+j-1) ;
                            if(x!=p1 && x!=p2 && x!=p3){
                                temp+=ds.size[x] ;
                            }
                            
                        }
                    }
                }
                maxi=max(maxi,temp) ;
            }

            
        }


        return maxi ;
    }
};
