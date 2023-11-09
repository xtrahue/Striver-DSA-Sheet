class Solution {
private:
    int MOD = 1e9+7 ;
    int solveit(int x,int y,vector<vector<int>>&dp){
        if(x==0 && y==0){
            return 1;
        }
        if(x<0 || y<0){
            return 0;
        }
        if(dp[x][y]!=-1){
            return (dp[x][y]%MOD) ;
        }
        long long ans=0;
        if(x==y){
            ans+=(solveit(x-2,y-1,dp)%MOD)  ;
            ans+=((solveit(x-1,y-2,dp) )%MOD) ;
            ans+=((solveit(x-2,y-2,dp) )%MOD) ;
            ans+=(solveit(x-1,y-1,dp)%MOD)%MOD;
        }
        else if(x>y){
            ans+=(solveit(x-2,y,dp)%MOD) ;
            ans+= (solveit(x-2,y-1,dp)%MOD) ;
        }
        else{
            ans=((solveit(x,y-2,dp)%MOD) + (solveit(x-1,y-2,dp)%MOD))%MOD ;
        }

        return dp[x][y]=(ans%MOD) ;
    }
public:
    int numTilings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ;
        return solveit(n,n,dp) ;
    }
};
