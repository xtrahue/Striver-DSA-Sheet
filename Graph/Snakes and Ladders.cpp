class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size() ;
        queue<pair<int,int>>qu ;

        vector<bool>visited((n*n)+1,0) ;

        qu.push({1,0}) ;
        visited[1]=1 ;

        while(!qu.empty()){
            int siz=qu.size() ;

            for(int i=0;i<siz; i++){
                int pos=qu.front().first ;
                int steps=qu.front().second ;
                qu.pop() ;

                if(pos==n*n){
                    return steps ;
                }

                for(int i=pos;i<=pos+6 && i<=n*n ;i++){
                    int row=(i-1)/n ; //by consider the starting cell [0][0]
                    int col=(i-1)%n ;
                    
                    if(row&1){
                        col=n-1-col ;
                    }
                    row=n-1-row ; //changing the staring cell to [n-1][0] ;
                    //first used [0][0] to establish that in even cells numbers are written in forward direction, in odd cell number are written in backword direction.

                    if(visited[i]){
                        continue ;
                    }
                    //cout<<pos<<"->"<<i<<"->"<<board[row][col]<<endl ;
                    visited[i]=1 ;
                    if(board[row][col]!=-1){
                        qu.push({board[row][col],steps+1}) ;
                    }
                    else{
                        qu.push({i,steps+1}) ;
                    }
                }
            }
        }

        return -1;
    }
};
