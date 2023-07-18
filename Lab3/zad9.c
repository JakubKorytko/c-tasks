#include <stdio.h>

int main() {
	
	int a, b;

	printf("Podaj a prostokata: ");
	scanf("%d", &a);

	printf("Podaj b prostokata: ");
	scanf("%d", &b);

	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;

}
