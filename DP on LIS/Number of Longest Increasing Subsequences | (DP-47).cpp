// had to check the solution
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size() ;
        vector<int>dp(n) ;
        dp[0]=1 ;
        vector<int>cnt(n) ;
        cnt[0]=1 ;

        int maxi=1 ;
        

        for(int i=1;i<n;i++){
            dp[i]=1 ;
            cnt[i]=1 ;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j] ;
                    cnt[i]=cnt[j] ;
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i]){
                    cnt[i]+=cnt[j] ;
                }

            }
            maxi=max(maxi,dp[i]) ;
        }

        //cout<<maxi ;

        int ans=0 ;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                ans+=cnt[i] ;
            }
        }

        return ans;
    }
};
