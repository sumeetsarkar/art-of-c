#include <stdio.h>

int add(int a, int b);

int main() {
    int num1, num2;

    printf("num1 = ");
    scanf("%d", &num1);

    printf("num2 = ");
    scanf("%d", &num2);

    printf("sum = %d", add(num1, num2));
    
    printf("\n");
    return 0;
}

int add(int a, int b) {
    return a + b;
}

