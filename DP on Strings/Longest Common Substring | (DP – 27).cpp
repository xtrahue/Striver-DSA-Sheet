class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ;
        
        int maxi=0 ;
        for(int i=0;i<n;i++){
            if(S1[i]==S2[0]){
                dp[i][0]=1 ;
                maxi=max(maxi,dp[i][0]) ;
            }
        }
        for(int j=0;j<m;j++){
            if(S1[0]==S2[j]){
                dp[0][j]=1 ;
                maxi=max(maxi,dp[0][j]) ;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(S1[i]==S2[j]){
                    dp[i][j]=1+dp[i-1][j-1] ;
                    maxi=max(maxi,dp[i][j]) ;
                }
            }
        }
        
        return maxi ;
    }
};
