//memoization-->behaves inconsistly in leetcode
class Solution {
public:
    bool solveit(int ind1,int ind2,string s,string p,vector<vector<int>>&dp){
        if(ind1<0 && ind2<0){
            return true ;
        }
        if(ind1<0){
            for(int ko=ind2;ko>=0;ko--){
                if(p[ko]!='*'){
                    return false ;
                }
            }
            return true ;
        }

        if(ind2<0){
            return false ;
        }
        if(dp[ind1][ind2]!=-1){
            if(dp[ind1][ind2]==1){
                return true ;
            }
            else{
                return false ;
            }
        }

        if(s[ind1]==p[ind2] || p[ind2]=='?'){
            return dp[ind1][ind2]= solveit(ind1-1,ind2-1,s,p,dp) ;
        }
        if(p[ind2]=='*'){
            return dp[ind1][ind2]=solveit(ind1,ind2-1,s,p,dp)|solveit(ind1-1,ind2,s,p,dp) ;
        }
        else{
            return dp[ind1][ind2]=false ;
        }
    }
    bool isMatch(string s, string p) {
        int n1=s.size() ;
        int n2=p.size() ;

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1)) ;

        return solveit(n1-1,n2-1,s,p,dp) ;
    }
};




//itreation....else if er jaigai if lekhar jonno 1ghonta legeche decode korte
bool isMatch(string s, string p) {
    int n1=s.size() ;
    int n2=p.size() ;

    vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,0)) ;
    for(int j=1;j<=n2;j++){
        if(p[j-1]=='*'){
            dp[0][j]=1 ;

        }
        else{
            break ;
        }
    }
    dp[0][0]=1 ;


    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1] ;
            }
            else if(p[j-1]=='*'){
                dp[i][j]=(dp[i][j-1] | dp[i-1][j]) ;
            }
            else{
                dp[i][j]=false ;
            }
        }
    }

    return dp[n1][n2];
}


//space optimized
bool isMatch(string s, string p) {
    int n1=s.size() ;
    int n2=p.size() ;

    vector<int>prev(n2+1,0) ;
    vector<int>curr(n2+1,0) ;
    for(int j=1;j<=n2;j++){
        if(p[j-1]=='*'){
            prev[j]=1 ;

        }
        else{
            break ;
        }
    }
    prev[0]=1 ;


    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                curr[j]=prev[j-1] ;
            }
            else if(p[j-1]=='*'){
                curr[j]=(curr[j-1] | prev[j]) ;
            }
        }
        prev=curr ;
    }

    return prev[n2];
    }
