//memoization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solveit(int W, int wt[], int val[], int ind,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=W){
                return val[0] ;
            }
            return 0 ;
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W] ;
        }
        
        int notTake=solveit(W,wt,val,ind-1,dp) ;
        int take=INT_MIN ;
        if(wt[ind]<=W){
            take=val[ind]+solveit(W-wt[ind],wt,val,ind-1,dp) ;
        }
        
        return dp[ind][W]=max(take,notTake) ;
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1)) ;
       return solveit(W,wt,val,n-1,dp) ;
    }
};


//tabulization
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<vector<int>>dp(n,vector<int>(W+1,0)) ;

   for(int weight=wt[0];weight<=W;weight++){
       if(wt[0]<=weight){
           dp[0][weight]=val[0] ;
       }
   }

   for(int i=1;i<n;i++){
       for(int weight=0;weight<=W;weight++){

           int notTake=dp[i-1][weight] ;
            int take=INT_MIN ;

            if(wt[i]<=weight){
                take=val[i]+dp[i-1][weight-wt[i]] ;
            }

            dp[i][weight]=max(take,notTake) ;
       }
   }
   return dp[n-1][W] ;

}


//space optimization
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<int>prev(W+1,0) ;

   for(int weight=wt[0];weight<=W;weight++){
       if(wt[0]<=weight){
           prev[weight]=val[0] ;
       }
   }

   for(int i=1;i<n;i++){
       vector<int>curr(W+1,0) ;
       for(int weight=0;weight<=W;weight++){

           int notTake=prev[weight] ;
            int take=INT_MIN ;

            if(wt[i]<=weight){
                take=val[i]+prev[weight-wt[i]] ;
            }

            curr[weight]=max(take,notTake) ;
       }
       prev=curr ;
   }
   return prev[W] ;

}



//without the curr vector..only using the prev
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<int>prev(W+1,0) ;

   for(int weight=wt[0];weight<=W;weight++){
       if(wt[0]<=weight){
           prev[weight]=val[0] ;
       }
   }

   for(int i=1;i<n;i++){
       //vector<int>curr(W+1,0) ;
       for(int weight=W;weight>=0;weight--){

           int notTake=prev[weight] ;
            int take=INT_MIN ;

            if(wt[i]<=weight){
                take=val[i]+prev[weight-wt[i]] ;
            }

            prev[weight]=max(take,notTake) ;
       }
   }
   return prev[W] ;

}
