#include <iostream>
#include <string>

inline int read()
{
    int r, s = 0, c;
    for (; !isdigit(c = getchar()); s = c);
    for (r = c ^ 48; isdigit(c = getchar()); (r *= 10) += c ^ 48);
    return s ^ 45 ? r : -r;
}

int main()
{
    int n = read(), m = read();
    std::string s, t;
    std::cin >> s >> t;


    puts("Yes");
    puts("No");

    return 0;
}