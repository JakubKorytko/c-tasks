#include <stdio.h>
#include <math.h>

int main() {

	int x;

	printf("Podaj liczbe do sprawdzenia: ");
	scanf("%d", &x);

	int y=1;

	for (int i=2; i<sqrt(x); i++) {
		if (x%i==0) {
			y=0;
		}
	}

	if (y==1 && x>1) {
		printf("Liczba %d jest liczba pierwsza", x);
	} else {
		printf("Liczba %d nie jest liczba pierwsza", x);
	}

	return 0;
}
