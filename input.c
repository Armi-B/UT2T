#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

char *input(char *command)
{
    int c;
    command = (char *)malloc(sizeof(char));
    command[0] = '\0';
    /*input a command,take care about the spaces*/
    for (int i = 0; (c = getchar()) != '\n' && c != ' '; i++)
    {
        command = (char *)realloc(command, (i + 2) * sizeof(char));
        command[i] = (char)c;
        command[i + 1] = '\0';
    }
    return command;
}

char *input_post(char *txt)
{
    int c;
    txt = (char *)malloc(sizeof(char));
    txt[0] = '\0';
    /*input a post,ignore the spaces*/
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        txt = (char *)realloc(txt, (i + 2) * sizeof(char));
        txt[i] = (char)c;
        txt[i + 1] = '\0';
    }
    return txt;
}