//memoization....gives TLE in leetcode
class Solution {
public:
    int solveit(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp){
        if(ind1==0 && ind2==0){
            if(text1[ind1]==text2[ind2]){
                return 1;
            }
            return 0;
        }
        if(ind1<0 || ind2<0){
            return 0 ;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2] ;
        }

        int nm1=0,nm2=0,m=0 ;
        if(ind1-1>=0){
            nm1=solveit(ind1-1,ind2,text1,text2,dp) ;
        }
        if(ind2-1>=0){
            nm2=solveit(ind1,ind2-1,text1,text2,dp) ;
        }

        if(text1[ind1]==text2[ind2]){
            m=1+solveit(ind1-1,ind2-1,text1,text2,dp) ;
        }

        return dp[ind1][ind2]=max(m,max(nm1,nm2)) ;

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size() ;
        int n2=text2.size() ;
        vector<vector<int>>dp(n1,vector<int>(n2,-1)) ;
        return solveit(n1-1,n2-1,text1,text2,dp) ;
    }
};


//Tabulization
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size() ;
        int n2=text2.size() ;
        vector<vector<int>>dp(n1,vector<int>(n2,0)) ;
        

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(text1[i]==text2[j]){
                    if(i-1<0 || j-1<0){
                        dp[i][j]=1 ;
                    }
                    else{
                        dp[i][j]=1+dp[i-1][j-1] ;
                    }
                }
                else{
                    int nm1=0,nm2=0 ;
                    if(i-1>=0){
                        nm1=dp[i-1][j] ;
                    }
                    if(j-1>=0){
                        nm2=dp[i][j-1] ;
                    }      

                    dp[i][j]=max(nm1,nm2) ;
                }
            }
        }

        return dp[n1-1][n2-1] ;
    }
};



//Space optimized
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size() ;
        int n2=text2.size() ;
        vector<vector<int>>dp(n1,vector<int>(n2,0)) ;
        vector<int>prev(n2,0) ;
        vector<int>curr(n2,0) ;
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(text1[i]==text2[j]){
                    if(i-1<0 || j-1<0){
                        curr[j]=1 ;
                    }
                    else{
                        curr[j]=1+prev[j-1] ;
                    }
                }
                else{
                    int nm1=0,nm2=0 ;
                    if(i-1>=0){
                        nm1=prev[j] ;
                    }
                    if(j-1>=0){
                        nm2=curr[j-1] ;
                    }      

                    curr[j]=max(nm1,nm2) ;
                }
            }
            prev=curr ;
        }

        return prev[n2-1] ;
    }
};
