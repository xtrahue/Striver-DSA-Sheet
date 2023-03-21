
//memoization

class Solution{
public:
    int solveit(int ind,int W,int val[], int wt[],vector<vector<int>>&dp){
        if(ind<=-1 || W==0){
            return 0 ;
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W] ;
        }
        int nt=solveit(ind-1,W,val,wt,dp) ;
        int t=INT_MIN ;
        if(wt[ind]<=W){
            t=val[ind]+solveit(ind,W-wt[ind],val,wt,dp) ;
        }
        
        return dp[ind][W]=max(t,nt) ;
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1)) ;
        return solveit(N-1,W,val,wt,dp) ;
    }
};



//space optimized
int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        //vector<vector<int>>dp(N,vector<int>(W+1,0)) ;
        vector<int>prev(W+1);
        vector<int>curr(W+1,0) ;
        
        for(int i=0;i<=W;i++){
            prev[i]=(int)(i/wt[0])*val[0] ;
        }
        for(int i=1;i<N;i++){
            for(int weight=0;weight<=W;weight++){
                int nt=prev[weight] ;
                int t=INT_MIN ;
                if(wt[i]<=weight){
                    t=val[i]+curr[weight-wt[i]] ;
                }
                
                curr[weight]=max(t,nt) ;
            }
            prev=curr ;
        }
        return prev[W] ;
    }


//space optimized using only prev
int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        //vector<vector<int>>dp(N,vector<int>(W+1,0)) ;
        vector<int>prev(W+1);
        vector<int>curr(W+1,0) ;
        
        for(int i=0;i<=W;i++){
            prev[i]=(int)(i/wt[0])*val[0] ;
        }
        for(int i=1;i<N;i++){
            for(int weight=0;weight<=W;weight++){
                int nt=prev[weight] ;
                int t=INT_MIN ;
                if(wt[i]<=weight){
                    t=val[i]+prev[weight-wt[i]] ;
                }
                
                prev[weight]=max(t,nt) ;
            }
            
        }
        return prev[W] ;
    }
