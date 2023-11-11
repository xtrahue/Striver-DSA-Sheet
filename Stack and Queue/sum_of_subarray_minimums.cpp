class Solution {
private:
    int MOD=1e9+7 ;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size() ;
        vector<int>nse(n,n) ;
        vector<int>pse(n,-1) ;

        stack<int>backward ;
        for(int i=n-1;i>=0;i--){
            while(!backward.empty() && arr[backward.top()]>=arr[i]){
                backward.pop() ;
            }
            if(!backward.empty()){
                nse[i]=backward.top() ;
            }
            backward.push(i) ;
        }

        stack<int>forward ;

        for(int i=0;i<n;i++){
            while(!forward.empty() && arr[forward.top()]>arr[i]){
                forward.pop() ;
            }
            if(!forward.empty()){
                pse[i]=forward.top() ;
                if(arr[i]==arr[forward.top()]){
                    forward.pop() ;
                }
            }
            forward.push(i) ;
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
            long long cnt = (abs(nse[i]-i)*1LL*abs(pse[i]-i))%MOD ;
            cnt=(cnt*arr[i])%MOD ;

            ans=(ans+cnt)%MOD ;
        }

        return (int)ans ;
    }
};
