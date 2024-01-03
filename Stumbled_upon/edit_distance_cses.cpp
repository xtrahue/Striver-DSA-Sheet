#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solveit(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = solveit(n - 1, m - 1, s1, s2, dp);
    }
    int ins = solveit(n, m - 1, s1, s2, dp);     // insert
    int del = solveit(n - 1, m, s1, s2, dp);     // delete ;
    int rep = solveit(n - 1, m - 1, s1, s2, dp); // replace

    dp[n][m] = 1 + min({ins, del, rep});

    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i=0;i<=n;i++){
        dp[i][0]=i ;
    }

    for(int j=0;j<=m;j++){
        dp[0][j]=j ;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1] ;
            }
            else{
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) ;
            }
        }
    }

    cout << dp[n][m] << "\n";
}
