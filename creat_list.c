#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "post.h"
#define TRUE 1
#define FALSE 0

account *creat_accs_list(void)
{
    /*creat a dummy node for accounts' linked list*/
    account *head_of_accs = (account *)malloc(sizeof(account));
    head_of_accs->next_acc = NULL;
    return head_of_accs;
}

post *creat_posts_list(void)
{
    /*creat a dummy node for posts' linked list*/
    post *head_of_posts = (post *)malloc(sizeof(post));
    head_of_posts->next_post = NULL;
    return head_of_posts;
}