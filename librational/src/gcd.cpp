#include "gcd.h"

namespace librational
{

int gcd(int a, int b)
{
    int r = (a%b);
    while (r < 0 || r > 0)
    {
        a = b;
        b = r;
        r = (a%b);
    }
    return b;
}

}
