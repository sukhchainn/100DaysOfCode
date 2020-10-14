// Exclusively for windows

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menu(int no_of_options, char* options[]);

int main()
{
    printf("Welcome to the Todo App");
    FILE* todo = fopen("todo.txt", "r");

    if (todo == NULL)
    {
        char inp[200];
        printf("No database yet, do you wanna create a todo entry?\n"\
                "Type Yes/No to proceed!\n");
        scanf("%s", inp);
        if (strcmp("yes", inp))
            todo = fopen("todo.txt", "w");
        else if (strcmp("no", inp))
            exit(EXIT_SUCCESS);
        else 
        {
            printf("You enterd wrong input\n Exiting!!!");
            exit(EXIT_FAILURE);
        }
    }

    char buffer[500];

    char* options[4];
    options[0] = "Create an entry!";
    options[1] = "Edit an entry!";
    options[2] = "Delete an entry!";
    options[3] = "Exit!";

    int o=-1;
    while(o != 3)
    {
        o = menu(4, options);
        
        if (o == 0)
        {
            todo = freopen("todo.txt", "a+", todo);
            system("clear");
            printf("Todo Items:-\n\n");
            while (fgets(buffer, 499, todo))
                puts(buffer);
            char inp[501];
            printf("The character limit is 500.\n\n");
            fgets(inp, 500, stdin);
            fputs(inp, todo);
        } else if (o == 1)
        {
            todo = freopen("todo.txt", "r+", todo);
        } else if (o == 2)
        {

        } else printf("\nBye!\n");
    }

    fclose(todo);
    getch();
    return 0;
}

int menu(int no_of_options, char* options[]) 
{
    // two charachers to read arrow keys
    char menu_ch1, menu_ch2;

    // "a H" for KEY_UP
    // "a P" for KEY_DOWN
    // "a K" for KEY_LEFT
    // "a M" for KEY_RIGHT
    // lookup on Grey codes for more info
    int option=1;
    system("clear");
    while(1)
    {
        for (int i=0; i<no_of_options; i++)
        {
            if (i == option)
                printf("* ");
            else printf("  ");
            printf("%s\n", options[i]);
        }

        menu_ch1 = getch();
        if (menu_ch1 == -32) 
        {
            menu_ch2 = getch();
            switch(menu_ch2)
            {
                case 'H': // UP
                    option--;
                    break;
                case 'P': // DOWN
                    option++;
                    break;
                case 'K': // LEFT
                    option--;
                    break;
                case 'M': // RIGHT
                    option++;
                    break;
            }
            option%=no_of_options;
        }

        if (menu_ch1 == 'q')
            exit(EXIT_SUCCESS);
        else if (menu_ch1 == 13)
            return option;

        //printf("\e[1;1H\e[2J");
        system("clear");
    }
}
