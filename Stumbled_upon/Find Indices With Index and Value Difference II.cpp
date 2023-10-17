class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n=nums.size() ;
        vector<pair<int,int>>min_till(n) ; //{minimum value,index of that value}

        min_till[n-1].first=nums[n-1] ;
        min_till[n-1].second=n-1 ;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<min_till[i+1].first){
                min_till[i]={nums[i],i} ;
            }
            else{
                min_till[i]=min_till[i+1] ;
            }
        }

        for(int i=0;i<n-indexDifference;i++){
            int val=abs(nums[i]-min_till[i+indexDifference].first) ;
            if(val>=valueDifference){
                vector<int>temp ;
                temp.push_back(i) ;
                temp.push_back(min_till[i+indexDifference].second) ;

                return temp ;
            }
        }

        return {-1,-1} ;
    }
};
