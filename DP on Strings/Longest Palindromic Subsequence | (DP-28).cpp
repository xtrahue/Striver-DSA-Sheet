//Memoization
class Solution {
public:
    int solveit(int ind1,int ind2,string s,int n,vector<vector<int>>&dp){
        if(ind1<0 || ind2>n-1){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2] ;
        }
        if(s[ind1]==s[ind2]){
            return dp[ind1][ind2]=1+solveit(ind1-1,ind2+1,s,n,dp) ;
        }
        else{
            int m1=solveit(ind1-1,ind2,s,n,dp);
            int m2=solveit(ind1,ind2+1,s,n,dp) ;

            return dp[ind1][ind2]=max(m1,m2) ;
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size() ;
        vector<vector<int>>dp(n+1,vector<int>(n,-1)) ;
        return solveit(n-1,0,s,n,dp) ;
    }
};


//itreation

class Solution{
  public:
    int longestPalinSubseq(string s) {
        //code here
        int n=s.size() ;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;

        string s2=s ;
        reverse(s2.begin(),s2.end()) ;
        
        int maxi=1 ;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1] ;
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]) ;
                }
            }
        }

        return (dp[n][n]) ;
    }
};
