//striver's approach
int minInsertions(string s) {
      int n=s.size() ;
      string s2=s ;
      reverse(s2.begin(),s2.end()) ;

      vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;

      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              if(s[i-1]==s2[j-1]){
                  dp[i][j]=1+dp[i-1][j-1] ;
              }
              else{
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
              }
          }
      }
      return n-dp[n][n] ;

  }


//my approach
class Solution {
public:
    int solveit(int ind1,int ind2,string &s,vector<vector<int>>&dp){
        if(ind1>ind2){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2] ;
        }
        if(s[ind1]==s[ind2]){
            return dp[ind1][ind2]=solveit(ind1+1,ind2-1,s,dp) ;
        }
        int l1=1+solveit(ind1+1,ind2,s,dp) ;
        int l2=1+solveit(ind1,ind2-1,s,dp) ;

        return dp[ind1][ind2]=min(l1,l2) ;
    }
    
    int minInsertions(string s) {
        int n=s.size() ;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;

        return solveit(0,n-1,s,dp) ;
    }
};
