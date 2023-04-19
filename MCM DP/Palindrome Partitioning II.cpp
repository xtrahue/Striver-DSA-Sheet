class Solution {
public:
    bool isPallindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]==s[j]){
                i++ ;
                j-- ;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    int solveit(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j] ;
        }

        int mini=INT_MAX ;
        for(int k=i;k<j;k++){
            if(isPallindrome(i,k,s)){
                int ans=1+solveit(k+1,j,s,dp) ;
                mini=min(mini,ans) ;
            }
            
        }

        return dp[i][j]=mini ;
    }
    int minCut(string s) {
        int n=s.size() ;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;
        return solveit(0,n,s,dp)-1 ;
    }
};
