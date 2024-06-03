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
    const char* patten = "wbwbwwbwbwbwwbwbwwbwbwbw";
    int len = 24;
    int n = read();
    while (n--)
    {
        int w_input = read(), b_input = read();

        // patten: wbwbwwbwbwbw 12, w: 7, b: 5
        int cycle_w = w_input / 7;
        int cycle_b = b_input / 5;
        int cycle = std::min(cycle_w, cycle_b);

        w_input -= cycle * 7;
        b_input -= cycle * 5;

        bool flag = 0;
        for (int i = 0; i < len; ++i)
        {
            if (flag)
                break;
            int w = w_input, b = b_input;
            for (int j = i; j < len; ++j)
            {
                if (patten[j] == 'w')
                {
                    --w;
                    if (w < 0)
                        break;
                }
                else
                {
                    --b;
                    if (b < 0)
                        break;
                }
                if (w == 0 && b == 0)
                {
                    flag = 1;
                    std::cout << "Yes ";
                    break;
                }
            }
        }

        if (!flag)
            std::cout << "No ";
    }

    return 0;
}