#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// takes two operands and operator function pointer
double operation(double a, double b, double (*func) (double, double));

double (*get_op_func()) (double, double);
// A simple function pointer    > double (*fp) (double, double)
// Now a function get_op_func() which returns a function pointer like above
// is represented as            > double (*get_op_func()) (double, double)

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);


int main(int argc, char **argv) {
    double result = operation(12, 13, get_op_func());
    printf("result: %f\n", result);
    return EXIT_SUCCESS;
}

double operation(double a, double b, double (*func) (double, double)) {
    if (func == NULL)
        return 0;
    return func(a, b);
}

double (*get_op_func()) (double, double) {
    printf("1. Add\n");
    printf("2. Sub\n");
    printf("3. Mul\n");
    printf("4. Div\n");
    printf("Choose an operation: ");

    int choice = 0;
    scanf("%d", &choice);

    switch(choice) {
        case 1: return add;
        case 2: return subtract;
        case 3: return multiply;
        case 4: return divide;
        default:
            return NULL;
    }
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {   
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

