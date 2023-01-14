#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "account.h"
#include "post.h"
#define TRUE 1
#define FALSE 0
#define ASCII 48

void write_accounts(account *head_of_accs, post *head_of_posts, FILE *accounts)
{
    char *space = " ";
    int num_of_posts;
    account *current = head_of_accs->next_acc;
    while (current != NULL)
    {
        /*loop of accounts*/
        num_of_posts = 0;
        post *current_post = head_of_posts->next_post;
        while (current_post != NULL)
        {
            /*count number of posts of any user*/
            if (strcmp(current->name, current_post->user_name) == 0)
            {
                num_of_posts++;
            }
            current_post = current_post->next_post;
        }
        /*write on file*/
        fwrite(current->name, sizeof(char), strlen(current->name), accounts);
        fwrite(space, sizeof(char), 1, accounts);
        fwrite(current->pass, sizeof(char), strlen(current->pass), accounts);
        fprintf(accounts, " %d\n", num_of_posts);
        /*next user*/
        current = current->next_acc;
    }
}

void write_posts(post *head_of_posts, FILE *posts)
{
    char *space = " ";
    post *current = head_of_posts->next_post;
    while (current != NULL)
    {
        /*write post*/
        fwrite(current->txt, sizeof(char), strlen(current->txt), posts);
        fwrite(space, sizeof(char), 1, posts);
        fwrite(current->user_name, sizeof(char), strlen(current->user_name), posts);
        fwrite(space, sizeof(char), 1, posts);
        fprintf(posts, " %d\n", current->like);
        /*next post*/
        current = current->next_post;
    }
}
