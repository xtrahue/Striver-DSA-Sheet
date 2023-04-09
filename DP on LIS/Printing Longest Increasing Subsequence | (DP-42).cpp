//Gfg question is wrongly framed...the ques wants only to print the longest subsequence...doesn't have to make it lexiographically smallest
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        vector<int>dp(n,1) ;
        vector<int>hash(n) ;
        int last_ind =0 ;
        int maxi=-1 ;
        for(int i=0;i<n;i++){
            hash[i]=i ;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j ;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i] ;
                last_ind=i ;
            }
        }
        vector<int>store ;
        store.push_back(nums[last_ind]) ;
        int ptr=hash[last_ind] ;
        for(int i=1;i<maxi;i++){
            store.push_back(nums[ptr]) ;
            ptr=hash[ptr] ;
        }
        
        reverse(store.begin(),store.end()) ;
        
        return store ;
    }
};
