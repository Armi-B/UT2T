#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "post.h"
#define TRUE 1
#define FALSE 0

int add_acc(account *head_of_list, account *new_acc)
{
    /*add new node after dummy node newst accout shall be first one*/
    if (new_acc == NULL || head_of_list == NULL)
        return 0;
    new_acc->next_acc = head_of_list->next_acc;
    head_of_list->next_acc = new_acc;
    return 1;
}

int add_post(post *head_of_list, post *new_post)
{
    /*add new node after dummy node newst post shall be first one*/
    if (new_post == NULL || head_of_list == NULL)
        return 0;
    new_post->next_post = head_of_list->next_post;
    head_of_list->next_post = new_post;
    return 1;
}