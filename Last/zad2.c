// Copyright: 2023 Jakub Korytko

#include <stdio.h>
#include <math.h>

int convertFrom(char ch[]) {
    int i = 0;
    int result = 0;
    while (ch[i] != '\0') {
        switch (ch[i]) {
        case 'I':
            result += 1;
            break;
        case 'V':
            if (i != 0 && ch[i - 1] == 'I') {
                result += 3;
                break;
            }
            result += 5;
            break;
        case 'X':
            if (i != 0 && ch[i - 1] == 'I') {
                result += 8;
                break;
            }
            result += 10;
            break;
        case 'L':
            if (i != 0 && ch[i - 1] == 'X') {
                result += 30;
                break;
            }
            result += 50;
            break;
        case 'C':
            if (i != 0 && ch[i - 1] == 'X') {
                result += 80;
                break;
            }
            result += 100;
            break;
        case 'D':
            if (i != 0 && ch[i - 1] == 'C') {
                result += 300;
                break;
            }
            result += 500;
            break;
        case 'M':
            if (i != 0 && ch[i - 1] == 'C') {
                result += 800;
                break;
            }
            result += 1000;
            break;
        default:
            return -1;
        }
        i++;
    }
    return result;
}

void convertToRoman(char *ch, int num) {
    char roman[1001];
    roman[1] = 'I';
    roman[5] = 'V';
    roman[10] = 'X';
    roman[50] = 'L';
    roman[100] = 'C';
    roman[500] = 'D';
    roman[1000] = 'M';

    int test = num;
    int i = 6, j = 0;

    int symbols[7] = {1, 5, 10, 50, 100, 500, 1000};

    while (test > 0) {
        int n = test;
        int k = 0;
        int p = symbols[i];
        while (p >= 10) {
            p = p / 10;
            k++;
        }
        while (n >= 10) {
            n = n / 10;
        }
        int first = n;

        if (test >= symbols[i]) {
            test -= symbols[i];
            ch[j++] = roman[symbols[i]];
        } else if (i > 0 && i % 2 == 0 && test >= 9 * pow(10, k-1)) {
            test -= symbols[i] - symbols[i - 2];
            ch[j++] = roman[symbols[i - 2]];

            ch[j++] = roman[symbols[i]];

            i--;
        } else if (i % 2 == 1 && first == 4 && test >= 4 * pow(10, k)) {
            test -= symbols[i] - symbols[i - 1];
            ch[j++] = roman[symbols[i - 1]];
            ch[j++] = roman[symbols[i]];
            i--;
        } else {
            i--;
        }
    }
}

int isValid(char *ch) {
    int i = 0;
    int arr[7] = {0, 0, 0, 0, 0, 0, 0};
    while (ch[i] != '\0') {
            switch (ch[i]) {
                case 'I':
                    arr[0]++;
                    break;
                case 'V':
                    arr[1]++;
                    break;
                case 'X':
                    arr[2]++;
                    break;
                case 'L':
                    arr[3]++;
                    break;
                case 'C':
                    arr[4]++;
                    break;
                case 'D':
                    arr[5]++;
                    break;
                case 'M':
                    arr[6]++;
                    break;
                default:
                    return -1;
            }
            i++;
        for (int j = 0; j < 7; j++) {
            if (arr[j] > 3) {return -1;}
        }
    }
    return 0;
}

int main() {
    char a[100];
    char b[100];
    char ch[100] = {};

    printf("Podaj skladniki sumy oddzielone spacja w systemie rzymskim "
    "z przedzialu <1, 1000>: ");

    scanf("%s %s", &a, &b);

    if (isValid(a) == -1 || isValid(b) == -1) {
        printf("\nPodano liczbe w blednym formacie");
        return 1;
    }

    int a_num = convertFrom(a);
    int b_num = convertFrom(b);

    if (a_num < 1 || a_num > 1000 || b_num < 1 || b_num > 1000) {
        printf("\nPodano liczbe z blednego przedzial "
        "lub niepoprawny system rzymski");

        return 1;
    }

    int sum = a_num + b_num;

    convertToRoman(ch, sum);

    printf("Wynik dodawania %s + %s:\n", a, b);
    printf("%s", ch);

    return 1;
}
