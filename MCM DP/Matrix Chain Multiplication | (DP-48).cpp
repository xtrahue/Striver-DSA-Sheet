//Memoization
// User function Template for C++

class Solution{
public:
    int solveit(int i,int j,int arr[],vector<vector<int>>&dp){
        int mini=INT_MAX ;
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j] ;
        }
        for(int k=i;k<j;k++){
            int ans=arr[i-1]*arr[k]*arr[j]+solveit(i,k,arr,dp)+solveit(k+1,j,arr,dp) ;
            mini=min(mini,ans) ;
        }
        
        return dp[i][j]=mini ;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1)) ;
        return solveit(1,N-1,arr,dp);
    }
};




//tabulation
int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<int>>dp(N,vector<int>(N,0)) ;
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int mini=INT_MAX ;
            for(int k=i;k<j;k++){
                int ans=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j] ;
                mini=min(mini,ans) ;
            }
            dp[i][j]=mini ;
        }
    }
    return dp[1][N-1] ;
}
