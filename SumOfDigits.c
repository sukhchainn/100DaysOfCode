#include <stdio.h>
#include <conio.h>

// To Get sum of all digits of the number num
int digitTotal(int num) {
    int sum=0;
    while (num != 0)
    {
        sum += num%10;
        num = num/10;        
    } return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("Addition of all digits of %d is %d", n, digitTotal(n));
    return 0;
}
