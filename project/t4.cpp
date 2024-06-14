#include <iostream>
#include <algorithm>

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

int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i].l = read(), a[i].r = read();

    std::sort(a + 1, a + n + 1, [](const node &x, const node &y) { return x.r < y.r; });


    for (int k = 1; k <= n; ++k)
    {



    }

    return 0;
}