//memoization
class Solution{
  public:
    int solveit(int price[],int ind,int siz,vector<vector<int>>&dp){
        if(ind==1){
            return (siz)*price[0] ;
        }
        if(dp[ind][siz]!=-1){
            return dp[ind][siz] ;
        }
        int nt=solveit(price,ind-1,siz,dp) ;
        int t=INT_MIN ;
        if(ind<=siz){
            t=price[ind-1]+solveit(price,ind,siz-ind,dp) ;
            //cout<<price[ind-1]<<endl ;
        }
        
        return dp[ind][siz]=max(nt,t) ;

    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;
        return solveit(price,n,n,dp) ;
    }
};
