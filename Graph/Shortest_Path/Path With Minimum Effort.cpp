class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size() ;
        int m=heights[0].size() ;

        vector<vector<int>>maxdiff(n,vector<int>(m,INT_MAX)) ;

        int dx[]={-1,1,0,0} ;
        int dy[]={0,0,-1,1} ;

        //{max_diff_till_now,{x,y}}
        set<pair<int,pair<int,int>>>st ;
        st.insert({0,{0,0}}) ;

        while(!st.empty()){
            auto it=*(st.begin()) ;
            int diff=it.first ;
            int x=it.second.first ;
            int y=it.second.second ;
            st.erase(it) ;

            if(x==n-1 && y==m-1){
                return diff ;
            }
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i] ;
                int ny=y+dy[i] ;

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int eff=max(abs(heights[nx][ny]-heights[x][y]),diff) ;
                    if(eff<maxdiff[nx][ny]){
                        maxdiff[nx][ny]=eff ;
                        st.insert({eff,{nx,ny}}) ;
                    }
                }
            }

        }

        return 0;
    }
};
