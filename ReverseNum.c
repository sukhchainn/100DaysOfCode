#include <stdio.h>
#include <conio.h>

// Reverse the number
int reverseNum(int num)
{
    int rev=0;
    while (num != 0)
    {
        rev += num%10;
        num /= 10;
        rev *= 10;
    } return rev/10;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("Reverse of %d is %d", n, reverseNum(n));
    return 0;
}
