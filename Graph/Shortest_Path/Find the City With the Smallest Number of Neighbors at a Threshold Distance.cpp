// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int d) {
        int matrix[n][n] ;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    matrix[i][j]=0 ;
                }
                else{
                    matrix[i][j]=1e9 ;
                }
            }
        }

        for(auto it:edges){
            int src = it[0] ;
            int dst = it[1] ;
            int w= it[2] ;

            matrix[src][dst]=w ;
            matrix[dst][src]=w ;
        }

        for(int vis=0;vis<n;vis++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][vis]==1e9 or matrix[vis][j]==1e9)  continue;
                    if (matrix[i][vis] + matrix[vis][j] < matrix[i][j]) {
                      matrix[i][j] = matrix[i][vis] + matrix[vis][j] ;
                    }
                }
            }
        }

        int cnt=INT_MAX;
        int node=0 ;

        for(int i=0;i<n;i++){
          int temp=0 ;
          //cout<<i<<" " ;
          for(int j=0;j<n;j++){
            //cout<<j<<"->"<<matrix[i][j]<<" " ;
            if(matrix[i][j]<=d){
              temp++ ;
            }
          }
          //cout<<endl ;

          if(temp<=cnt){
            //cout<<temp<<" "<<i<<endl ;
            node=i ;
            cnt=temp ;
          }
        }

        return node ;
    }
};
