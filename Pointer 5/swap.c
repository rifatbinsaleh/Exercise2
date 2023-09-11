#include <stdio.h>

int main() {
    int num1 = 5;
    int num2 = 7;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Declare pointer variables
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    // Swap the values using pointers
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
