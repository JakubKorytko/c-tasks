// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

// C++ specific warning, but it's a C file
// NOLINTNEXTLINE(runtime/int)
#define LL long long int

LL power(LL base, LL exp, LL mod) {
    LL res = 1;
    LL x = base % mod;

    for (LL i = 1; i <= exp; i <<= 1) {
        x %= mod;
        if ((exp & i) != 0) {
            res = res * x % mod;
        }
        x *= x;
    }

    return res;
}

int main() {
    unsigned int seed = time(NULL);

    LL k, n;
    printf("Podaj dokladnosc testu: ");
    scanf("%lld", &k);
    printf("Podaj liczbe (nieparzysta) do sprawdzenia: ");
    scanf("%lld", &n);

    if ((n % 2 == 0 && n != 2) || n == 1) {
        printf("Liczba nie jest pierwsza");
        return 1;
    } else if (n == 2) {
        printf("Liczba jest pierwsza");
        return 1;
    }

    LL p = n - 1;
    LL s = 0;

    while (p != 0 && p % 2 == 0) {
        p = p / 2;
        s++;
    }

    if (s > 64) {
        printf("Liczba jest zbyt duza");
        return 1;
    }

    LL pw = floor(pow(2, s));
    LL d = n / pw;

    for (LL i = 0; i < k; i++) {
        LL a = (rand_r(&seed) % (n - 2)) + 2;
        LL x = power(a, d, n);

        if (x != 1) {
            LL z = 0;
            for (LL r = 0; r <= s - 1; r++) {
                LL test = power(a, d * pow(2, r), n);
                if (test == n - 1) {
                    z = 1;
                    break;
                }
            }
            if (z == 0) {
                printf("Liczba nie jest pierwsza");
                return 1;
            }
        }
    }

    printf("Liczba jest prawdopodobnie pierwsza");

    return 1;
}
