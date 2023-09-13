//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size() ;
	    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    matrix[i][j]=0 ;
                }
                if(matrix[i][j]==-1){
                    matrix[i][j]=1e9 ;
                }
            }
        }
        
        for(int vis=0;vis<n;vis++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][vis]==1e9 or matrix[vis][j]==1e9)  continue;
                    if (matrix[i][vis] + matrix[vis][j] < matrix[i][j]) {
                      matrix[i][j] =
                          min(matrix[i][j], matrix[i][vis] + matrix[vis][j]);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]>=1e9){
                    matrix[i][j]=-1 ;
                }
            }
        }
	}
};
