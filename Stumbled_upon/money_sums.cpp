#include <bits/stdc++.h>
using namespace std;

int solveit(int i, int sum, vector<int> &arr, vector<vector<int>> &dp, set<int> &st)
{
    if (i < 0)
    {

        if (st.find(sum) == st.end() && sum != 0)
        {
            // cout<<sum<<" " ;
            st.insert(sum);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    int nt = solveit(i - 1, sum, arr, dp, st);
    int t = solveit(i - 1, sum + arr[i], arr, dp, st);

    return dp[i][sum] = nt + t;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    set<int> st;
    int k = solveit(n - 1, 0, arr, dp, st);
    // cout << k << endl;

    cout << st.size() << "\n";
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}
