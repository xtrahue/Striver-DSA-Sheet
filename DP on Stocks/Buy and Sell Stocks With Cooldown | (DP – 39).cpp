//Memoization
int solveit(int ind,bool buy,vector<int>& prices,vector<vector<int>>&dp){
    if(ind>=prices.size()){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy] ;
    }
    if(buy){
        return dp[ind][buy]=max(-prices[ind]+solveit(ind+1,0,prices,dp),solveit(ind+1,buy,prices,dp)) ;
    }
    return dp[ind][buy]=max(prices[ind]+solveit(ind+2,1,prices,dp),solveit(ind+1,buy,prices,dp)) ;
}



//Itreation
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>>dp(n+2,vector<long long>(2,0)) ;
        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j>=0;j--){
                int profit = 0 ;
                if(j==1){
                    dp[ind][j]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][j]) ;
                }
                else{
                    dp[ind][j]=max(prices[ind]+dp[ind+2][1],dp[ind+1][j]) ;
                }

            }
            
        }
        return dp[0][1] ;
    }
};
