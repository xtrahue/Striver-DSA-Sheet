//optimized
class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n=nums.size() ;
        int sum=0 ;
        for(int i=0;i<n;i++){
            sum+=nums[i] ;
        }
        int total=(sum-tar)/2 ;
        //cout<<total<<endl ;
        if((sum-tar)%2!=0 || sum-tar<0){//was missing sum-tar
            return 0;
        }       
        //vector<vector<int>>dp(n,vector<int>(total+1,0)) ;
        vector<int>prev(total+1,0) ;
        vector<int>curr(total+1,0) ;

        
        if(nums[0]!=0 && nums[0]<=total){
            prev[nums[0]]=1 ;
        }
        if(nums[0]==0){
            prev[0]=2 ;
        }
        else{
            prev[0]=1 ;
        }

        
        for(int i=1;i<n;i++){
            for(int target=0;target<=total;target++){

                int notTaken=prev[target] ;
                int taken=0 ;

                if(nums[i]<=target){
                    taken=prev[target-nums[i]] ;
                }

                curr[target]=taken+notTaken ;
            }
            prev=curr ;
        }
        return prev[total] ;
    }
};
