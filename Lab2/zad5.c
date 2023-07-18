#include <stdio.h>
#include <math.h>

short biggestShort()
{
    short x = 0;
    int k;

    for (k = 0; k == x; k++)
    {
        x++;
    }

    return (k - 1);
}

int biggestInt()
{

    int l = 0;
    int m = 0;
    int p = 0;
    double n = 0;
    int final = 0;
    int y = 0;
    double k = 0;

    for (k = 0; k == y; l++)
    {
        k = ceil(pow(10, l));
        y = k;
    }

    for (l = l - 2; l >= 0; l--)
    {
        n = 0;
        m = 0;
        p = 0;
        while (m == n)
        {
            p++;
            n = final + p * ceil(pow(10, l));
            m = n;
        }

        final += (p - 1) * ceil(pow(10, l));

    }

    return final;
}

float smallestFloat() {
       float fl, last, last_b, power;
    double db, lastdb, lastdb_b, power_b;
    fl = 0;
    power = 1;
    while (fl != last) {
        last_b = last;
        last = fl;
        fl = fl + (power / 2);
        power = power / 2;
    }
    while (last != last_b) {
        last = last * 0.5;
        last_b = last_b * 0.5;
    }

    return last_b;
}

int main()
{

    printf("Max short: %d, max int: %d, max float: %.10e, min float: %.10e", 
    biggestShort(), biggestInt(), nextafterf(INFINITY,0), smallestFloat());
    return 0;
}


