#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

long long power(long long base, long long exp, long long mod)
{

    long long res = 1;
    long long x = base % mod;

    for (long long i = 1; i <= exp; i <<= 1)
    {
        x %= mod;
        if ((exp & i) != 0)
        {
            res = res * x % mod;
        }
        x *= x;
    }

    return res;
}

int main()
{
    srand(time(NULL));

    long long k, n;
    printf("Podaj dokladnosc testu: ");
    scanf("%lld", &k);
    printf("Podaj liczbe (nieparzysta) do sprawdzenia: ");
    scanf("%lld", &n);

    if ((n % 2 == 0 && n != 2) || n == 1)
    {
        printf("Liczba nie jest pierwsza");
        return 1;
    }
    else if (n == 2)
    {
        printf("Liczba jest pierwsza");
        return 1;
    }

    long long p = n - 1;
    long long s = 0;

    while (p != 0 && p % 2 == 0)
    {
        p = p / 2;
        s++;
    }

    if (s > 64)
    {
        printf("Liczba jest zbyt duza");
        return 1;
    }

    long long pw = floor(pow(2, s));
    long long d = n / pw;

    for (long long i = 0; i < k; i++)
    {
        long long a = (rand() % (n - 2)) + 2;
        long long x = power(a, d, n);

        if (x != 1)
        {
            long long z = 0;
            for (long long r = 0; r <= s - 1; r++)
            {
                long long test = power(a, d * pow(2, r), n);
                if (test == n - 1)
                {
                    z = 1;
                    break;
                }
            }
            if (z == 0)
            {
                printf("Liczba nie jest pierwsza");
                return 1;
            }
        }
    }

    printf("Liczba jest prawdopodobnie pierwsza");

    return 1;
}