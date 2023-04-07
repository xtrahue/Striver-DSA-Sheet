//Memoization
class Solution {
public:
    int solveit(int ind,bool buy,int tran,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(tran>=2){
            return 0;
        }
        if(dp[ind][buy][tran]!=-1){
            return dp[ind][buy][tran] ;
        }
        if(buy){
            return dp[ind][buy][tran]=max(-prices[ind]+solveit(ind+1,0,tran,prices,dp),solveit(ind+1,1,tran,prices,dp)) ;
        }
        else {
            return dp[ind][buy][tran]=max(prices[ind]+solveit(ind+1,1,tran+1,prices,dp),solveit(ind+1,buy,tran,prices,dp)) ;
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1))) ;
        return solveit(0,1,0,prices,dp) ;
    }
};


//itreation

int maxProfit(vector<int>&prices){
    //Write your code here..
    int n=prices.size() ;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0))) ;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                for(int tran=1;tran>=0;tran--){
                    if(buy==1){
                        dp[ind][buy][tran]=max(-prices[ind]+dp[ind+1][0][tran],dp[ind+1][buy][tran]) ;
                    }
                    else{
                        dp[ind][buy][tran]=max(prices[ind]+dp[ind+1][1][tran+1],dp[ind+1][buy][tran]) ;
                    }
                }
            }
        }
        return dp[0][1][0] ;
}
