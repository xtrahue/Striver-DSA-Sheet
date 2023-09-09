class Solution {
private:
    int solveit(int i,vector<int>&days, vector<int>&costs,vector<int>&dp){
        int n=days.size() ;
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i] ;
        }

        int day=costs[0]+solveit(i+1,days,costs,dp) ;

        int j;
        for(j=i;j<n && days[j]<days[i]+7 ;j++) ;
        int week = costs[1]+solveit(j,days,costs,dp) ;

        for(j=i;j<n && days[j]<days[i]+30 ;j++) ;
        int month =costs[2]+solveit(j,days,costs,dp); 

        return dp[i]=min({day,month,week}) ;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366,-1) ;
        return solveit(0,days,costs,dp) ;
    }
};
