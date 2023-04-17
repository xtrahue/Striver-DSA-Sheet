//Memoization
class Solution {
public:
    int solveit(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }

        int mini=1e9 ;
        if(dp[i][j]!=-1){
            return dp[i][j] ;
        }

        for(int k=i;k<=j;k++){
            int ans=cuts[j+1]-cuts[i-1]+solveit(i,k-1,cuts,dp)+solveit(k+1,j,cuts,dp) ;
            cout<<ans<<endl ;
            mini=min(mini,ans) ;
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {        
        int p=cuts.size() ;

        cuts.push_back(n) ;
        cuts.push_back(0) ;
        sort(cuts.begin(),cuts.end()) ;

        vector<vector<int>>dp(p+2,vector<int>(p+2,-1)) ;

        return solveit(1,p,cuts,dp) ;
    }
};


//Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {        
        int p=cuts.size() ;

        cuts.push_back(n) ;
        cuts.push_back(0) ;
        sort(cuts.begin(),cuts.end()) ;

        vector<vector<int>>dp(p+2,vector<int>(p+2,0)) ;

        for(int i=p;i>=1;i--){
            for(int j=i;j<=p;j++){
                int mini=INT_MAX ;
                for(int k=i;k<=j;k++){
                    int ans=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j] ;
                    mini=min(mini,ans) ;
                }
                dp[i][j]=mini ;
            }
        }

        return dp[1][p] ;
    }
};
