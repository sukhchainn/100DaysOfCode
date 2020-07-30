#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int n=9, j;
    char c='1';

    // Takin the Inphut
    printf("Enter the size of the pyramid bro: ");
    scanf(" %d", &n);
    if (n>9) {
        printf("You stupid bro, why you enter more than 9?");
    getch();
        printf(" Why?");
        exit(EXIT_FAILURE);
    }
    printf("\nNow enter either a, A, or 1 :- ");
    scanf(" %c", &c);
    if (c != 'a' &&
        c != 'A' &&
        c != '1')
    {
        printf("We don't do dat here...\n");
        exit(EXIT_FAILURE);
    }

    for (int i=1; i<=n; i++)
    {
        for (j=1; j<=n-i; j++)
            printf(" ");
        for (j=0; j<i; j++)
            printf("%c", c+j);
        for (--j; j>0; j--)
            printf("%c", c+j-1);
        printf("\n");
    }

    return 0;
}
