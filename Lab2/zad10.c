#include <stdio.h>
#include <math.h>

double y1 (double x) {return log10(x)+10;}
double y2 (double x) {return pow(1.5, x);}
double y3 (double x) {return exp(x);}

int main() {

	double x;
	double y;

	printf("Podaj X punktu: ");
	scanf("%lf", &x);

	printf("Podaj Y punktu: ");
	scanf("%lf", &y);

	if (y>y2(x) && y<y3(x) && y<y1(x)) {
		printf("Punkt lezy pomiedzy funkcjami");
	} else {
		printf("Punkt nie lezy miedzy funkcjami");
	}

	return 0;
}
