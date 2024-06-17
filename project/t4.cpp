#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

inline int read()
{
    int r, s = 0, c;
    for (; !isdigit(c = getchar()); s = c);
    for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48);
    return s ^ 45 ? r : -r;
}

const int N = 10010;
struct node
{
    int l, r;
}a[N];

int ans[N];

int main()
{
    int n = read();
    int lmin = N << 1, rmax = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i].l = read(), a[i].r = read();
        lmin = std::min(lmin, a[i].l);
        rmax = std::max(rmax, a[i].r);
    }

    std::sort(a + 1, a + 1 + n, [](const node &a, const node &b) { return a.l < b.l; });

    for (int i = lmin; i <= rmax; ++i) // conference start time
    {
        int k = 1; // lecturer
        std::priority_queue<int, std::vector<int>, std::greater<int>> q{}; // min heap

        for (int j = i; (j <= rmax) && (j - i + 1 <= n); ++j) // conference end time
        {
            while(k <= n && a[k].l <= j)
                q.push(a[k++].r);

            while(!q.empty() && q.top() < j)
                q.pop();

            if (q.empty())
                break;

            // std::cout << "Current q.top() = " << q.top() << std::endl;
            // std::cout << i << ' ' << j << std::endl;
            ++ans[j - i + 1];
            q.pop();
        }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);

    return 0;
}