#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "post.h"
#include "m_acc.h"
#define TRUE 1
#define FALSE 0

int delete (post *pre_post, char *my_name)
{
    if(pre_post!=NULL)
    {
    /*you cant delete the post isnt your own. so check the name*/
    int comp = strcmp(my_name, pre_post->next_post->user_name);
    if (comp == 0)
    {
        post *our_post = pre_post->next_post;
        pre_post->next_post = our_post->next_post;
        /*dont forget to free allocated mmemory, or you know!*/
        free(our_post);
        return 0;
    }
    printf("you cant delete the post isnt your own.\n");
    return 1;
    }
    else
    {
        printf("you cant delete the post which dosnt exist ever\n");
        return 1;
    }
}