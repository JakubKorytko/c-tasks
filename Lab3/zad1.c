#include <stdio.h>

int main() {
	
	int x, suma;

	printf("Oblicz sume do: ");
	scanf("%d", &x);

	for (int i=0; i<=x; i++) {
		suma+=i;
	}

	printf("\nSuma jest rowna: %d", suma);

	return 0;
}
