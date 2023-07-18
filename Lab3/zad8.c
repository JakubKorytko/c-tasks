#include <stdio.h>
#include <math.h>


float geo_avg(int numbers[], int n) {
	
	int x = 1;

	for (int i=0; i<n; i++) {
		x*=numbers[i];
	}

	return pow(x, 1/(float)n);
}

float ar_avg(int numbers[], int n) {

	int x = 0;

	for (int i=0; i<n; i++) {
		x+=numbers[i];
	}

	return x/(float)n;
}

int main() {

	int n;
	int m=0;

	printf("Podaj ilosc liczb: ");
	scanf("%d", &n);

	int numbers[n];

	for (int i=0; i<n; i++) {
		printf("Podaj %d liczbe: ", i+1);
		scanf("%d", &m);
		numbers[i]=m;
	}
	
	printf("Srednia geometryczna: %f, arytmetyczna: %f", geo_avg(numbers, n), ar_avg(numbers, n));
	return 0;

}
