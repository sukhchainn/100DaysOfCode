#include <stdio.h>
#include <conio.h>

int factorial(int num) {
    int product=1;
    for (int i=1; i<=num; i++)
        product *= i;
    return product;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}
