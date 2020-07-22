// For some reason the correct answer is only upto lacks.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int countDigits(long num)
{
    int i=0;
    while(num != 0)
    {
        i++;
        num /= 10;
    } return i;
}

int* numToArr(long num)
{
    int digits = countDigits(num);
    int *arr = (int*) malloc(digits*sizeof(int));

    for(int i=0; i<digits; i++)
    {
        arr[(digits-i)-1] = num%10;
        num /= 10;
    }
    return arr;
}

// function declairation
char* iToWord(unsigned long num);

char* numToWords(long num)
{
    char* str = (char*) malloc(1024);
    char* word;
    int* temp = numToArr(num);
    int digits = countDigits(num);

    for(int i=0; i<digits; i++)
    {
        if(digits-i >= 13 && temp[i] != 0)
        {
            if(digits-i == 14)
                if(temp[i] == 1) {
                    word = iToWord(10+temp[++i]);
                    strcat(word, "kharab ");
                } else
                    word = iToWord(10*temp[i]);
            else {
                word = iToWord(temp[i]);
                strcat(word, "kharab ");
            }
        } else if(digits-i >= 10 && temp[i] != 0)
        {
            if(digits-i == 11)
                if(temp[i] == 1) {
                    word = iToWord(10+temp[++i]);
                    strcat(word, "arab ");
                } else
                    word = iToWord(10*temp[i]);
            else {
                word = iToWord(temp[i]);
                strcat(word, "arab ");
            }
        } else if(digits-i >= 8 && temp[i] != 0)
        {
            if(digits-i == 9)
                if(temp[i] == 1) {
                    word = iToWord(10+temp[++i]);
                    strcat(word, "crore ");
                } else
                    word = iToWord(10*temp[i]);
            else {
                word = iToWord(temp[i]);
                strcat(word, "crore ");
            }
        } else if(digits-i >= 6 && temp[i] != 0)
        {
            if(digits-i == 7)
                if(temp[i] == 1) {
                    word = iToWord(10+temp[++i]);
                    strcat(word, "lack ");
                } else
                    word = iToWord(10*temp[i]);
            else {
                word = iToWord(temp[i]);
                strcat(word, "lack ");
            }
        } else if(digits-i >= 4 && temp[i] != 0)
        {
            if(digits-i == 5)
                if(temp[i] == 1) {
                    word = iToWord(10+temp[++i]);
                    strcat(word, "thousand ");
                } else
                    word = iToWord(10*temp[i]);
            else {
                word = iToWord(temp[i]);
                strcat(word, "thousand ");
            }
        } else if(digits-i == 3 && temp[i] != 0)
        {
            word = iToWord(temp[i]);
            strcat(word, "hundred ");
        } else if(temp[i] == 1 && digits-i > 1)
        {
            word = iToWord(10+temp[++i]);
        } else if(digits-i > 1) {
            word = iToWord(10*temp[i]);
        } else 
            word = iToWord(temp[i]);

        strcat(str, word);
        free(word);
    }

    free(temp);
    return str;
}

int main(){
    int n;

    printf("Enter the number: \n");
    scanf("%d", &n);
    char* a = numToWords(n);
    printf("%s", a);
    free(a);

    return 0;
}

// function definition
char* iToWord(unsigned long num)
{
    char* str = malloc(20);
    strcpy(str, "");

    switch(num)
    {
        // once
        case 1:
            strcat(str, "one ");
            break;
        case 2:
            strcat(str, "two ");
            break;
        case 3:
            strcat(str, "three ");
            break;
        case 4:
            strcat(str, "four ");
            break;
        case 5:
            strcat(str, "five ");
            break;
        case 6:
            strcat(str, "six ");
            break;
        case 7:
            strcat(str, "seven ");
            break;
        case 8:
            strcat(str, "eight ");
            break;
        case 9:
            strcat(str, "nine ");
            break;
        case 10:
            strcat(str, "ten ");
            break;
        case 11:
            strcat(str, "eleven ");
            break;
        case 12:
            strcat(str, "twelve ");
            break;
        case 13:
            strcat(str, "thirteen ");
            break;
        case 14:
            strcat(str, "fourteen ");
            break;
        case 15:
            strcat(str, "fifteen ");
            break;
        case 16:
            strcat(str, "sixteen ");
            break;
        case 17:
            strcat(str, "seventeen ");
            break;
        case 18:
            strcat(str, "eighteen ");
            break;
        case 19:
            strcat(str, "ninteen ");
            break;
            // tens
        case 20:
            strcat(str, "twenty ");
            break;
        case 30:
            strcat(str, "thirty ");
            break;
        case 40:
            strcat(str, "fourty ");
            break;
        case 50:
            strcat(str, "fifty ");
            break;
        case 60:
            strcat(str, "sixty ");
            break;
        case 70:
            strcat(str, "seventy ");
            break;
        case 80:
            strcat(str, "eighty ");
            break;
        case 90:
            strcat(str, "ninety ");
            break;
        // place
        case 100:
            strcat(str, "hundred ");
        //     break;
        // case 1000:
        //     strcat(str, "thousand ");
        //     break;
        // case 100000:
        //     strcat(str, "lack ");
        //     break;
        // case 10000000:
        //     strcat(str, "crore ");
        //     break;
        // case 1000000000:
        //     strcat(str, "arab ");
        //     break;
        // case 1000000000000:
        //     strcat(str, "kharab ");
        //     break;
    }
    return str;
}
