#include <stdio.h>
#include <math.h>

double kwadrat()
{
    double a;

    printf("\nPodaj bok kwadratu: ");
    scanf("%lf", &a);

    return 4 * a;
}

double kolo()
{
    double r;

    printf("\nPodaj promien kola: ");
    scanf("%lf", &r);

    return M_PI * pow(r, 2);
}

double trojkat()
{
    double a;
    double h;

    printf("\nPodaj bok trojkata: ");
    scanf("%lf", &a);

    printf("\nPodaj wysokosc trojkata: ");
    scanf("%lf", &h);

    return (1.0 / 2) * a * h;
}

int main()
{

    int p = 0;

    while (p != 4)
    {
        printf("\nOblicz pole:\n1. Trojkata\n2. Kwadratu\n3. Kola\n4. Koniec\n\n(Wpisz odpowiedni numer oraz potwierdz enterem) Wybor: ");
        scanf("%d", &p);

        if (p == 1)
        {
            printf("\nPole trojkata wynosi %lf\n", trojkat());
        }
        else if (p == 2)
        {
            printf("\nPole kwadratu wynosi %lf\n", kwadrat());
        }
        else if (p == 3)
        {
            printf("\nPole kola wynosi %lf\n", kolo());
        }
        else
        {
            if (p != 4)
            {
                printf("\nWybrano zla opcje");
            }
        }
    }

    return 0;
}
