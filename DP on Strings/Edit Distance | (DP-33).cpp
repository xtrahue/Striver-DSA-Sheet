//memo-->by me
class Solution {
public:
    int solveit(int ind1,int ind2,string word1,string word2,vector<vector<int>>&dp){
        if(ind1<0){
            return ind2+1 ;
        }
        if(ind2<0){
            return ind1+1 ;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2] ;
        }
        if(word1[ind1]==word2[ind2]){
            return dp[ind1][ind2]=solveit(ind1-1,ind2-1,word1,word2,dp) ;
        }
        
        int replace=1+solveit(ind1-1,ind2-1,word1,word2,dp) ;
        int del= 1+solveit(ind1-1,ind2,word1,word2,dp) ;
        int ins=1+solveit(ind1,ind2-1,word1,word2,dp) ;

        return dp[ind1][ind2]=min(replace,min(del,ins)) ;
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size() ;
        int n2=word2.size() ;

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1)) ;

        return solveit(n1-1,n2-1,word1,word2,dp) ;
    }
};


//it --> also by me
class Solution {
  public:
    int editDistance(string word1, string word2) {
        // Code here
        int n1=word1.size() ;
        int n2=word2.size() ;

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0)) ;
        for(int i=0;i<=n1;i++){
            dp[i][0]=i ;
        }
        for(int j=0;j<=n2;j++){
            dp[0][j]=j ;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1] ;
                }
                else{
                    int replace=1+dp[i-1][j-1] ;
                    int del=1+dp[i-1][j] ;
                    int ins=1+dp[i][j-1] ;

                    dp[i][j]=min(replace,min(del,ins)) ;
                }
            }
        }

        return dp[n1][n2] ;
    }
};



//space optimized
int minDistance(string word1, string word2) {
    int n1=word1.size() ;
    int n2=word2.size() ;

    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0)) ;
    vector<int>prev(n2+1,0) ;
    vector<int>curr(n2+1,0) ;

    for(int j=0;j<=n2;j++){
        prev[j]=j ;
    }

    for(int i=1;i<=n1;i++){
        curr[0]=i ;
        for(int j=1;j<=n2;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j]=prev[j-1] ;
            }
            else{
                int replace=1+prev[j-1] ;
                int del=1+prev[j] ;
                int ins=1+curr[j-1] ;

                curr[j]=min(replace,min(del,ins)) ;
            }
        }
        prev=curr ;
    }

    return prev[n2] ;
}
