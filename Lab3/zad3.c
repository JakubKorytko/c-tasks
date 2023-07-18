#include <stdio.h>

int main() {

	int x;
	int y=0;

	printf("Podaj liczbe ktorej dzielniki znalezc: ");
	scanf("%d", &x);

	printf("\nDzielnikami liczby %d sa: ", x);
	
	for (int i=1; i<=x; i++) {
		if (x%i==0) {
			if (y==0) {
				y++;
			} else {
				printf(", ");
			}
			printf("%d", i);
		}
	}	

	return 0;
}
