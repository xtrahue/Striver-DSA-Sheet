// User function Template for C++

class Solution{
public:
    int solveit(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>>&dp){
        int mod=1003 ;
        if(i>j){
            return 0;
        }
        
        if(i==j){
            if(isTrue){
                return s[i]=='T' ;
            }
            else{
                return s[i]=='F' ;
            }
        }
        
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue] ;
        }
        
        int cnt=0 ;
        for(int k=i+1;k<=j-1;k+=2){
            int lT=solveit(i,k-1,1,s,dp) ;
            int lF=solveit(i,k-1,0,s,dp) ;
            int rT=solveit(k+1,j,1,s,dp) ;
            int rF=solveit(k+1,j,0,s,dp) ;
            //cout<<lT<<endl ;
            
            if(s[k]=='|'){
                if(isTrue){
                    cnt=(cnt+(lF*rT)%mod + (lT*rF)%mod + (lT*rT)%mod )%mod;
                }
                else{
                    cnt=(cnt+(lF*rF)%mod)%mod;
                }
            }
            if(s[k]=='&'){
                if(isTrue){
                    cnt=(cnt+(lT*rT)%mod )%mod;
                }
                else{
                    cnt=(cnt+(lF*rF)%mod+(lF*rT)%mod+(lT*rF)%mod)%mod ;
                }
            }
            if(s[k]=='^'){
                if(isTrue){
                    cnt=(cnt+(lF*rT)%mod+(rF*lT )%mod)%mod;
                }
                else{
                    cnt=(cnt+(lT*rT)%mod+(rF*lF)%mod)%mod ;
                }
            }
            //cout<<cnt<<" " ;
            
        }
        
        return dp[i][j][isTrue]=cnt ;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1))) ;
        return solveit(0,N-1,1,S,dp) ;
    }
};
