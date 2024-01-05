#include <bits/stdc++.h>
using namespace std;
using ll=long long ;

ll solveit(ll i, ll j,vector<ll> &arr, vector<vector<ll>> &dp)
{
    if(i>j){
        return 0 ;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    ll from_1st=arr[i]+min(solveit(i+2,j,arr,dp),solveit(i+1,j-1,arr,dp)) ;
    ll from_last=arr[j]+min(solveit(i+1,j-1,arr,dp),solveit(i,j-2,arr,dp)) ;

    return dp[i][j]=max(from_1st,from_last) ;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<ll>>dp(n,vector<ll>(n,-1)) ;

    cout<<solveit(0,n-1,arr,dp)<<endl ;
}
