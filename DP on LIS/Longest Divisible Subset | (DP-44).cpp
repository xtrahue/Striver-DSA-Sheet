//My solution
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size() ;
        vector<int>dp(n,1) ;
        vector<int>hash(n) ;
        hash[0]=0 ;

        int maxi=1 ;
        int indi=0 ;

        sort(nums.begin(),nums.end()) ;

        for(int i=1;i<n;i++){
            hash[i]=i ;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j] ;
                    hash[i]=j ;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i] ;
                indi=i ;
            }
            //cout<<hash[i]<<" ";
        }
        //cout<<maxi<<endl ;

        vector<int>ans ;
        ans.push_back(nums[indi]) ;
        int ptr=hash[indi] ;
        for(int i=1;i<maxi;i++){
            ans.push_back(nums[ptr]);
            ptr=hash[ptr] ;
            //cout<<ptr<<" ";
        }

        return ans;
    }
};




//
