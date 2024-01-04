#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    vector<vector<int>>dp(a+1,vector<int>(b+1,1e9)) ;
    //dp[i][j] -> min number of cuts to make i*j all squares

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0 ;
                continue ;
            }
            for(int ver=1;ver<j;ver++){
                dp[i][j]=min(dp[i][j],1+dp[i][ver]+dp[i][j-ver]) ;
            }

            for(int hor=1;hor<i;hor++){
                dp[i][j]=min(dp[i][j],1+dp[hor][j]+dp[i-hor][j]) ;
            }
        }
    }

    cout<<dp[a][b]<<"\n" ;
}
