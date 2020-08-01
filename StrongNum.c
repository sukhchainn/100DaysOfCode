#include <stdio.h>
#include <conio.h>

int factorial(int num) {
    int product=1;
    for (int i=1; i<=num; i++)
        product *= i;
    return product;
}

int strongNum(int num) {
    int sum=0, temp=num;
    while (temp != 0)
    {
        sum += factorial(temp%10);
        temp/=10;
    } 

    if (sum == num)
        return 1;
    else
        return 0;
}

int main()
{
    int num;
    printf("Enter a number : ");
    scanf(" %d", &num);

    if (strongNum(num))
        printf("\nThe number is a strong number.");
    else
        printf("\nThe number is not strong.");

    return 0;
}
