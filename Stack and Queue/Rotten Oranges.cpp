class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int fresh=0;
        int r=grid.size() ;
        int c=grid[0].size() ;
        queue<pair<int,int>>st ;
        int days=0 ;

        int x[4]={0,0,-1,1} ;
        int y[4]={1,-1,0,0} ;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    fresh++ ;
                }
                if(grid[i][j]==2){
                    //cout<<i<<" "<<j<<endl ;
                    st.push({i,j}) ;
                }
            }
        }

        while(!st.empty() ){
            int k=st.size() ;
            while(k--){
                pair<int,int>p = st.front() ;
                int x1=p.first ;
                int y1=p.second ;
                st.pop() ;
                for(int i=0;i<4;i++){
                    int nx=x1+x[i] ;
                    int ny=y1+y[i] ;
                    if(nx<0 || ny<0 || nx>=r || ny>=c || grid[nx][ny]!=1){
                        continue ;
                    }
                
                        fresh-- ;
                        grid[nx][ny]=2 ;
                        st.push({nx,ny}) ;
                    
                }
                
            }
            if(!st.empty()){
                days++ ;
            }
        }
        //cout<<days ;
        if(fresh==0){
            return days ;
        }
        else{
            return -1 ;
        }
    }
};
