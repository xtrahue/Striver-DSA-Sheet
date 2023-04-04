//solved by me
class Solution {
public:
    int solveit(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0 ;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2] ;
        }
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2]=solveit(ind1-1,ind2,s,t,dp)+solveit(ind1-1,ind2-1,s,t,dp) ;
        }
        else{
            return dp[ind1][ind2]=solveit(ind1-1,ind2,s,t,dp) ;
        }
    }
    int numDistinct(string s, string t) {
        int n1=s.size() ;
        int n2=t.size() ;

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1)) ;

        return solveit(n1-1,n2-1,s,t,dp) ;
    }
};


//tabulation-->also by me
int numDistinct(string s, string t) {
    int n1=s.size() ;
    int n2=t.size() ;

    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0)) ;
    for(int i=0;i<=n1;i++){
        dp[i][0]=1 ;
    }

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1] ;
            }
            else{
                dp[i][j]=dp[i-1][j] ;
            }
        }
    }

    return dp[n1][n2] ;
}


