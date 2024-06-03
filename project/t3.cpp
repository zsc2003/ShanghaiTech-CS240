#include <iostream>
#include <string>

const int N = 60, M = 20;
long long dp[N][M]; // dp[i][j]: the number of g at i-th digit, and the i-th digit is j

int main()
{
    std::string f;
    std::cin >> f;
    int len = f.size();

    for (int i = 0; i <= 9; ++i)
        dp[0][i] = 1;
    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            int sum = (f[i] - '0') + j;
            int mid = sum / 2;

            dp[i][mid] += dp[i - 1][j];

            if (sum & 1)
                dp[i][mid + 1] += dp[i - 1][j];
        }
    }

    // Based on this number f, generate a new number g
    // check whether f could be generated
    int flag = 1;
    for (int i = 0; i < len - 1; ++i)
    {
        bool check = 0;
        int sum = (f[i] - '0') + (f[i + 1] - '0');
        int mid = sum / 2;
        if (mid == (f[i + 1] - '0'))
            check = 1;
        if (sum & 1 && mid + 1 == (f[i + 1] - '0'))
            check = 1;
        if (!check)
        {
            flag = 0;
            break;
        }
    }

    long long ans = 0;
    for(int i = 0; i <= 9; ++i)
        ans += dp[len-1][i];
    ans -= flag;

    std::cout << ans;

    return 0;
}