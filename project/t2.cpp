#include <iostream>
#include <string>

inline int read()
{
    int r, s = 0, c;
    for (; !isdigit(c = getchar()); s = c);
    for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48);
    return s ^ 45 ? r : -r;
}

const int N = 200010;
const int M = 10;
bool dp[N][M]; // dp[i][j]: whether s[1: i] could be generated, pos[i] is the last position of t[1: j]

int main()
{
    int n = read(), m = read();
    std::string s, t;
    std::cin >> s >> t;

    dp[0][0] = (s[0] == t[0]);
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == t[0]) // right covers left
        {
            for (int j = 0; j < m; ++j)
                dp[i][0] |= dp[i - 1][j];
        }

        for (int j = 0; j < m; ++j)
        {
            if (s[i] == t[j])
            {
                if (j != 0) // continue the previous coverage
                    dp[i][j] |= dp[i - 1][j - 1];

                dp[i][j] |= dp[i - 1][m - 1]; // left covers right
            }
        }
    }

    puts(dp[n - 1][m - 1] ? "Yes" : "No");

    return 0;
}