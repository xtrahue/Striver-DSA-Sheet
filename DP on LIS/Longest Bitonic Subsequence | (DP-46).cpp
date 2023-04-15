class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size() ;
	    vector<int>front(n,1) ;
	    vector<int>back(n,1) ;
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i] && front[j]+1>front[i]){
	                front[i]=1+front[j] ;
	            }
	        }
	    }
	    
	    for(int i=n-2;i>=0;i--){
	        for(int j=i+1;j<n;j++){
	            if(nums[j]<nums[i] && 1+back[j]>back[i]){
	                back[i]=1+back[j] ;
	            }
	        }
	    }
	    int maxi=1 ;
	    
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,front[i]+back[i]-1) ;
	    }
	    
	    return maxi ;
	}
};
