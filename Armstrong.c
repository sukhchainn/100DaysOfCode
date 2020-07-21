#include <stdio.h>
#include <conio.h>
#include <math.h>

int armstrong(int num) {
    int i=0, temp, sum=0;
    temp = num;
    while(temp != 0)
    {
        i++;
        temp = temp/10;
    }
    temp = num;
    while(temp != 0)
    {
        sum += pow(temp%10, i);
        temp = temp/10;
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("\n%d\n", armstrong(n));
    return 0;
}
