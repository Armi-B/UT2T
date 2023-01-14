#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "post.h"
#define TRUE 1
#define FALSE 0

account *search_acc(account *head_of_accs, char *our_name)
{
    /*serch for a spescial user name in accounts*/
    account *pre = head_of_accs;
    while ((pre != NULL) && (pre->next_acc != NULL))
    {
        int comp = strcmp(our_name, pre->next_acc->name);
        if (comp == 0)
        {
            /*return a pointer to previus node, for delete account easier*/
            return pre;
        }
        pre = pre->next_acc;
    }
    return NULL;
}

post *search_post(post *head_of_posts, int our_post_ID)
{
    /*search for a spescial post_ID in posts*/
    post *pre = head_of_posts;
    while ((pre != NULL) && (pre->next_post != NULL))
    {
        if (our_post_ID == pre->next_post->post_ID)
        {
            /*return a pointer to previus node, for delete post easier*/
            return pre;
        }
        pre = pre->next_post;
    }
    printf("this post_ID is'nt valid!\n");
    return NULL;
}