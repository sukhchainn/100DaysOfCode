#include <stdio.h>
#include <conio.h>

int prime(int num) 
{
    if (num <= 1) {
        return 0;
    } else if (num == 2 || num == 5) {
        return 1;
    } else { 
        int possibility = num%10;
        if (possibility != 1 &&
            possibility != 3 &&
            possibility != 7 &&
            possibility != 9 )
            return 0;
    }

    int n = num/2;
    for (int i=3; i<n; i++)
    {
        if (num%i == 0)
            return 0;
        else
            return 1;
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", prime(n));
    return 0;
}


// int prime(int num) 
// {
//     if (num <= 1) {
//         printf("Less than 1!\n");
//         return 0;
//     } else if (num == 2 || num == 5) {
//         printf("Equlas to 2 or 5");
//         return 1;
//     } else { 
//         printf("Else condition!");
//         int possibility = num%10;
//         if (possibility == 0 ||
//             possibility == 2 ||
//             possibility == 4 ||
//             possibility == 5 ||
//             possibility == 6 ||
//             possibility == 8 )
//             return 0;
//     }

//     int n = num/2;
//     for (int i=2; i<n; i++)
//     {
//         if (num%i == 0)
//             return 0;
//         else
//             return 1;
//     }
        
// }
