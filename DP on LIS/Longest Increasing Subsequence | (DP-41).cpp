//Memoization
int solveit(int ind,vector<int>&nums,int last_ind,vector<vector<int>>&dp){
    if(ind>=nums.size()){
        return 0;
    }
    if(dp[ind][last_ind+1]!=-1){
        return dp[ind][last_ind+1];
    }
    int nt=solveit(ind+1,nums,last_ind,dp) ;
    int t=0 ;
    if(last_ind==-1|| nums[ind]>nums[last_ind] ){
        t=1+solveit(ind+1,nums,ind,dp) ;
    }
    return dp[ind][last_ind+1]=max(t,nt) ;
}



//Itreation
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size() ;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0)) ;
    for(int ind=n-1;ind>=0;ind--){
        for(int last_ind=ind-1;last_ind>=-1;last_ind--){

            int nt=dp[ind+1][last_ind+1] ;
            int t=0 ;
            if(last_ind==-1|| nums[ind]>nums[last_ind] ){
                t=1+dp[ind+1][ind+1];
            }
            dp[ind][last_ind+1]=max(t,nt) ;
        }
    }
    return dp[0][0];
}

//Itreation --> A different approach
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size() ;
    vector<int>dp(n,1) ;
    int maxi=1 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],1+dp[j]) ;
                maxi=max(maxi,dp[i]) ;
            }
        }
    }

    return maxi ;
}
