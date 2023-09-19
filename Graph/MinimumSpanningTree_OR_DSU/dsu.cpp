#include <bits/stdc++.h>
using namespace std;
using ll = long long;


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

int main()
{
    Disjoint ds1(7) ;
    ds1.unionBySize(1,2) ;
    ds1.unionBySize(2,3) ;
    ds1.unionBySize(4,5) ;
    ds1.unionBySize(6,7) ;
    ds1.unionBySize(5,6) ;
    if(ds1.findPar(3)==ds1.findPar(7)){
        cout<<"Same Parent\n" ;
    }
    else{
        cout<<"Different Parent\n" ;
    }
    cout<<ds1.findPar(3)<<" "<<ds1.findPar(7)<<"\n" ;
    //cout<<ds1.parent[3]<<" "<<ds1.parent[7]<<endl ;

    ds1.unionBySize(3,7) ;

    if(ds1.findPar(3)==ds1.findPar(7)){
        cout<<"Same Parent\n" ;

    }
    else{
        cout<<"Different Parent\n" ;
    }
    cout<<ds1.findPar(3)<<" "<<ds1.findPar(7)<<"\n" ;
    //cout<<ds1.parent[3]<<" "<<ds1.parent[7]<<endl ;

}
