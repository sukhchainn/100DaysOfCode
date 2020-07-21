#include <stdio.h>
#include <conio.h>

void swap(int* num1, int* num2) {
    if(num1 == num2) return;
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

int main()
{
    int n1, n2;
    scanf(" %d %d", &n1, &n2);
    printf("Reverse of %d and %d is ", n1, n2);
    swap(&n1, &n2);
    printf("%d and %d\n", n1, n2);
    return 0;
}
