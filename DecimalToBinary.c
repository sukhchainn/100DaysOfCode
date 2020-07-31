#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

// This program was made using mobile device and only passes certain test cases like [28.125]
char* decToBin(double num)
{
//    Initialization
    double frc = num - floor(num), check;
    int dec = floor(num);
    int temp = dec, count=0, count2=0;
    check = dec;
    double temp2 = frc;

// counting the size of array to be allocated for decimal part
    while((temp /= 2) != 1)
        count++;
    count+=2;

// counting the size of array to be allocated for fractional part
    while((temp2 *= 2) != 1)
        count2++;
    count2+=2+count;

// Allocating array
    char* arr = malloc(count2+1);

// Converting the decimal part into binary
    for (int k=0; k<count; k++)
    {
        check /=2;
        arr[count-k-1] = ((check - floor(check)) > 0) ? '1' : '0';
        check = floor(check);
    }
        
// Convert the fractional part
    for (int j=1+count; j<count2; j++) {
        arr[j] = '0';
    }
    arr[count] = '.';
    arr[count2-1] = '1';
    arr[count2] = '\0';

    return arr;
}

void main(){
    double dec;
    char radix[10];

    printf("Enter the Number you want to convert : ");
    scanf(" %lf", &dec);

    char* bin = decToBin(dec);
    printf("\nBinary value is %s ", bin);

    free(bin);
}
