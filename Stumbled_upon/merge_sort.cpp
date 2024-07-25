class Solution {
public:
    void merge(vector<int>&nums,int i,int mid,int n){
        int siz=nums.size() ;
        vector<int>b(siz,0) ;
        int k=i ;
        int l=i ;
        int r=mid+1 ;

        while(l<=mid && r<=n && k<=n){
            if(nums[l]>nums[r]){
                b[k]=nums[r] ;
                r++ ;
            }
            else{
                b[k]=nums[l] ;
                l++ ;
            }
            k++ ;
        }
        while(l<=mid){
            b[k++]=nums[l++] ;
        }
        while(r<=n){
            b[k++] = nums[r++] ;
        }

        for(int x=i;x<=n;x++){
            nums[x]=b[x] ;
        }
    }
    void mergeSort(vector<int>&nums,int i,int j){
        if(i<j){
            int mid=(i+j)/2 ;
            mergeSort(nums,i,mid) ;
            mergeSort(nums,mid+1,j) ;
            merge(nums,i,mid,j );
        }
        return ;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1); 
        return nums ;
    }
};
