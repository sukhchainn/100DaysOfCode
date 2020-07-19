#include <stdio.h>
#include <string.h>
#include <conio.h>

int palindrome(const char* str) {
    int len = strlen(str), n;

    n = len/2;
    for (int i=1; i<=n; i++)
    {
        if (str[i-1] != str[len-i])
            return 0;
    }

    return 1;
}

int main() 
{
    char* str;
    scanf("%s", str);
    printf("%d", palindrome(str));

    return 0;
}
