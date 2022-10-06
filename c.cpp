
#include <bits/stdc++.h>
using namespace std;
string solve1(string str)
{
    int N = str.size();
    int m[256] = {0};
    for (int i = 0; i < N; i++)
        m[str[i]]++;
    string r1 = "";
    string r2 = "";
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < m[i] / 2; j++)
            r1.push_back(i);
        for (int j = (m[i] + 1) / 2; j < m[i]; j++)
            r2.push_back(i);
    }
    reverse(r2.begin(), r2.end());
    string r3;
    bool f = false;
    for (int i = 0; i < 256; i++)
    {
        if (m[i] % 2)
        {
            if (!f)
            {
                r1.push_back(i);
                f = true;
            }
            else  r3.push_back(i);
        }
    }
    return (r1 + r2 + r3);
}
int solve(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    for (int i = 0; i < s.size() + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < s.size() + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= s.size(); i++)
        for (int j = 1; j <= s.size(); j++)
            (s[i - 1] == s2[j - 1]) ? dp[i][j] = 1 + dp[i - 1][j - 1] : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[s.size()][s.size()];
}
// Driver Code
int main()
{
    string str;
    cin >> str;
    string new_str = solve1(str);
    int ans = solve(new_str);
    cout << ans << endl;
}
