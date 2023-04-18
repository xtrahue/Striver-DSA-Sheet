//Memoization
class Solution {
public:
    int solveit(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        int maxi=INT_MIN ;

        if(dp[i][j]!=-1){
            return dp[i][j] ;
        }

        for(int k=i;k<=j;k++){
            int ans=nums[i-1]*nums[k]*nums[j+1]+solveit(i,k-1,nums,dp)+solveit(k+1,j,nums,dp) ;
            maxi=max(maxi,ans) ;
        }
        return dp[i][j]=maxi ;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size() ;
        nums.insert(nums.begin(),1) ;
        nums.push_back(1) ;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;

        return solveit(1,n,nums,dp) ;
    }
};


//Tabulation
int maxCoins(vector<int>& nums) {
    int n=nums.size() ;
    nums.insert(nums.begin(),1) ;
    nums.push_back(1) ;
    vector<vector<int>>dp(n+2,vector<int>(n+2,0)) ;

    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            int maxi=INT_MIN ;
            for(int k=i;k<=j;k++){
                int ans=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j] ;
                maxi=max(maxi,ans) ;
            }
            dp[i][j]=maxi ;
        }
    }

    return dp[1][n] ;
}
