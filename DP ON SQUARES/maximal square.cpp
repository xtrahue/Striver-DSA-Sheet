class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size() ;
        int m=matrix[0].size() ;

        int dp[n+1][m+1] ;
        for(int i=0;i<n;i++){
            dp[i][0]=0 ;
        }
        for(int j=0;j<m;j++){
            dp[0][j]=0 ;
        }

        int ans=0 ;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=1+min({ dp[i-1][j], dp[i][j-1] ,dp[i-1][j-1] }) ;
                    //cout<<i-1<<" "<<j-1<<" "<<dp[i][j]<<endl ;
                    ans=max(ans,dp[i][j]) ;
                }
                else{
                    dp[i][j]=0 ;
                }
            }
        }

        return ans*ans;
    }
};
