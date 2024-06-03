#include <iostream>

inline int read()
{
    int r, s = 0, c;
    for (; !isdigit(c = getchar()); s = c);
    for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48);
    return s ^ 45 ? r : -r;
}

int main()
{
    int n = read();
    while (n--)
    {
        int w = read(), b = read();

        std::cout << "Yes ";
        std::cout << "No ";
    }

    return 0;
}