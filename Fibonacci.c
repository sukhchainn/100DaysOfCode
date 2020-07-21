#include <stdio.h>
#include <conio.h>

// Fibonacci sequence through recursion
int fib_rec(int num) {
    static int sum;
    sum += num;
    if (num != 0)
        fib_rec(--num);
    // return sum;
}

// Fibonacci sequence through iteration
int fib_itr(int num) {
    int sum=0;
    for (int i=1; i<=num; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n, sum=0;

    scanf("%d", &n);
    printf("Fibonacci number upto %dth sequence is %d\n", n, fib_rec(n));
    printf("Same here... %d\n", fib_itr(n));    

    return 0;
}
