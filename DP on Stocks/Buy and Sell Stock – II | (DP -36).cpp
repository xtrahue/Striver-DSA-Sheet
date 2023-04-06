//memoization
class Solution {
public:
    int solveit(int ind,int n,vector<int>&prices,bool ready_to_buy,vector<vector<int>>&dp){
        if(ind>=n){
            return 0;
        }
        int profit = 0 ;
        if(ready_to_buy){
            if(dp[ind][1]!=-1){
                return dp[ind][1] ;
            }
            int buy=(-prices[ind])+solveit(ind+1,n,prices,0,dp);
            int notBuy=solveit(ind+1,n,prices,1,dp) ;

            profit=max(buy,notBuy) ;
        }
        else{
            if(dp[ind][0]!=-1){
                return dp[ind][0] ;
            }
            int sold=prices[ind]+solveit(ind+1,n,prices,1,dp) ;
            int notSold=solveit(ind+1,n,prices,0,dp) ;

            profit=max(sold,notSold) ;
        }
        int ko=0 ;
        if(ready_to_buy){
            ko=1 ;
        }

        return dp[ind][ko]=profit ;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;
        vector<vector<int>>dp(n,vector<int>(2,-1)) ;
        return solveit(0,n,prices,1,dp) ;
    }
};



//itreation
int maxProfit(vector<int>& prices) {
    int n=prices.size() ;
    vector<vector<int>>dp(n+1,vector<int>(2,0)) ;
    int maxi=0 ;

    for(int ind=n-1;ind>=0;ind--){
        for(int j=1;j>=0;j--){
            int profit = 0 ;
            if(j==1){
                int buy=(-prices[ind])+dp[ind+1][0];
                int notBuy=dp[ind+1][1] ;

                profit=max(buy,notBuy) ;
            }
            else{
                int sold=prices[ind]+dp[ind+1][1];
                int notSold=dp[ind+1][0] ;

                profit=max(sold,notSold) ;
            }

            dp[ind][j]=profit ;

        }
    }


    return dp[0][1] ;
}




//space optimization
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<int>fut(2,0) ;
        vector<int>curr(2,0) ;
        int maxi=0 ;

        for(int ind=n-1;ind>=0;ind--){
            for(int j=1;j>=0;j--){
                int profit = 0 ;
                if(j==1){
                    int buy=(-prices[ind])+fut[0];
                    int notBuy=fut[1] ;

                    profit=max(buy,notBuy) ;
                }
                else{
                    int sold=prices[ind]+fut[1];
                    int notSold=fut[0] ;

                    profit=max(sold,notSold) ;
                }

                curr[j]=profit ;

            }
            fut=curr ;
        }


        return fut[1] ;
    }
};
