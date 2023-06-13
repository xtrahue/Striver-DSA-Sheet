class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans ;
        if(k==1){
            return nums ;
        }

        deque<int>nse ;
        for(int i=0;i<nums.size();i++){
            if(!nse.empty() && nse.front()==i-k){
                nse.pop_front() ;
            }
            while(!nse.empty() && nums[nse.back()]<nums[i]){
                nse.pop_back() ;
            }
            nse.push_back(i) ;
            if(i>=k-1){
                ans.push_back(nums[nse.front()]) ;
            }
        }

        return ans ;
    }
};
