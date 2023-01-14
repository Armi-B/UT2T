#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*structs' dec*/
#include "account.h"
#include "post.h"
#include "m_acc.h"
/*functions' dec*/
#include "input.h"
#include "add.h"
#include "search.h"
#include "creat_list.h"
#include "delete.h"
#include "str_to_int.h"
#include "write.h"
/*const def*/
#define TRUE 1
#define FALSE 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define ASCII 48

void main()
{
    printf("wellcome to UT2T ^_^\n");
    char state[4] = "out";
    char *_1st = NULL, *_2nd = NULL, *_3ed = NULL;
    account *head_of_accs = creat_accs_list();
    post *head_of_posts = creat_posts_list();
    my_account my_acc;

    /*the main loop of program*/
    while (TRUE)
    {
        /*input first part of command and choose appropriate action*/
        _1st = input(_1st);
        if (strcmp(_1st, "exit") == 0)
        {
            /*with command "exist" write posts and accounts on two diffrent file and break the loop.*/
            free(_1st);
            FILE *accounts = fopen("accounts.txt", "w");
            write_accounts(head_of_accs, head_of_posts, accounts);
            fclose(accounts);
            FILE *posts = fopen("posts.txt", "w");
            write_posts(head_of_posts, posts);
            fclose(posts);
            break;
        }
        if (strcmp(state, "out") == 0)
        {
            if (strcmp(_1st, "login") == 0)
            {
                free(_1st);
                _2nd = input(_2nd);
                _3ed = input(_3ed);
                account *pre_acc = search_acc(head_of_accs, _2nd);
                /* chek! if username and password is true change state into "ent".*/
                if (pre_acc == NULL)
                {
                    printf("this user name is'nt valid!\n");
                }
                else
                {
                    if (strcmp(pre_acc->next_acc->pass, _3ed) == 0)
                    {
                        strcpy(state, "ent");
                        /*save information of account in my_acc*/
                        my_acc.my_name = (char *)malloc((strlen(_2nd) + ONE) * sizeof(char));
                        my_acc.my_pass = (char *)malloc((strlen(_3ed) + ONE) * sizeof(char));
                        strcpy(my_acc.my_name, _2nd);
                        strcpy(my_acc.my_pass, _3ed);
                        my_acc.ID = pre_acc->next_acc->acc_ID;
                        printf("you have logged in.\n");
                    }
                    else
                    {
                        printf("The password is wrong.\n");
                    }
                }
                /*dont forget to free commands after use them*/
                free(_2nd);
                free(_3ed);
            }
            else if (strcmp(_1st, "signup") == 0)
            {
                free(_1st);
                _2nd = input(_2nd);
                _3ed = input(_3ed);
                /* search in linked list if there is no account with same name creat a new node*/
                account *status = search_acc(head_of_accs, _2nd);
                if (status == NULL)
                {
                    account *new_acc = (account *)malloc(sizeof(account));
                    if (head_of_accs->next_acc == NULL)
                    {
                        new_acc->acc_ID = ONE;
                    }
                    else
                    {
                        new_acc->acc_ID = (head_of_accs->next_acc->acc_ID) + 1;
                    }
                    /*save username and password in new node*/
                    new_acc->name = (char *)malloc((strlen(_2nd) + 1) * sizeof(char));
                    new_acc->pass = (char *)malloc((strlen(_3ed) + 1) * sizeof(char));
                    strcpy(new_acc->name, _2nd);
                    strcpy(new_acc->pass, _3ed);
                    add_acc(head_of_accs, new_acc);
                    printf("you have created an account.\n");
                }
                else
                {
                    printf("this user name already exists.\n");
                }
                free(_2nd);
                free(_3ed);
            }
            else
            {
                /*you cannot take any another action until you login*/
                free(_1st);
                printf("this command is not invalid!\nenter another command!\n");
            }
        }
        else if (strcmp(state, "ent") == 0)
        {
            if (strcmp(_1st, "post") == 0)
            {
                free(_1st);
                _2nd = input_post(_2nd);
                /*creat a new node*/
                post *new_post = (post *)malloc(sizeof(post));
                new_post->like = 0;
                new_post->next_post = NULL;
                /*assign a post_ID*/
                if (head_of_posts->next_post == NULL)
                {
                    new_post->post_ID = 1;
                }
                else
                {
                    int last_post_ID = head_of_posts->next_post->post_ID;
                    new_post->post_ID = last_post_ID + 1;
                }
                new_post->user_like = NULL;
                /*save its txt*/
                new_post->user_name = (char *)malloc(sizeof(*(my_acc.my_name)));
                strcpy(new_post->user_name, my_acc.my_name);
                new_post->txt = (char *)malloc(sizeof(*(_2nd)));
                strcpy(new_post->txt, _2nd);
                add_post(head_of_posts, new_post);
                /*free memory*/
                free(_2nd);
                printf("new post saved!\n");
            }
            else if (strcmp(_1st, "like") == 0)
            {
                free(_1st);
                _2nd = input(_2nd);
                _3ed = input(_3ed);
                int len = strlen(_3ed);
                post *pre = search_post(head_of_posts, str_to_int(_3ed, len));
                if (pre == NULL)
                {
                    printf("we cuold not find this post_ID.\n");
                }
                else
                {
                    post *our_post = pre->next_post;
                    if (strcmp(our_post->user_name, _2nd) == 0)
                    {
                        if (our_post->like == 0)
                        {
                            our_post->user_like = (int *)malloc(sizeof(int));
                            our_post->user_like[0] = my_acc.ID;
                            our_post->like = our_post->like + 1;
                            printf("you liked this post!\n");
                        }
                        else
                        {
                            /*check if the user has not liked this podt befor add one to the likes.*/
                            int flage = TRUE;
                            for (int i = 0; i < our_post->like; i++)
                            {
                                if (our_post->user_like[i] == my_acc.ID)
                                {
                                    flage = FALSE;
                                    printf("you liked this post befor.\n");
                                }
                            }
                            if (flage)
                            {
                                our_post->like = our_post->like + 1;
                                our_post->user_like = (int *)realloc(our_post->user_like, (our_post->like) * sizeof(int));
                                /*write user's ID in the list of likers*/
                                our_post->user_like[(our_post->like) - 1] = my_acc.ID;
                                printf("you liked this post!\n");
                            }
                        }
                    }
                    else
                    {
                        printf("user name and post_ID do not match. try agin!\n");
                    }
                }
                free(_2nd);
                free(_3ed);
            }
            else if (strcmp(_1st, "logout") == 0)
            {
                /*change state and free memory*/
                free(_1st);
                strcpy(state, "out");
                free(my_acc.my_name);
                free(my_acc.my_pass);
                printf("you hane successfully logged out.\n");
            }
            else if (strcmp(_1st, "delete") == 0)
            {
                free(_1st);
                _2nd = input(_2nd);
                int len = strlen(_2nd);
                /*find the post*/
                post *pre_post = search_post(head_of_posts, str_to_int(_2nd, len));
                /* delete the post if it was possible*/
                int status=delete (pre_post, my_acc.my_name);
                free(_2nd);
                if(status==0)
                {
                printf("post was deleted.\n");
                }
            }
            else if (strcmp(_1st, "info") == 0)
            {
                free(_1st);
                /*prints account's data*/
                printf("name: %s\npass:%s\n", my_acc.my_name, my_acc.my_pass);
                post *curr = head_of_posts->next_post;
                /* fid posts that belong to the account*/
                while ((curr != NULL))
                {
                    if (strcmp(my_acc.my_name, curr->user_name) == 0)
                    {
                        /*print posts*/
                        printf("%s\npost_ID:%d\nlike:%d\n", curr->txt, curr->post_ID, curr->like);
                    }
                    curr = curr->next_post;
                }
            }
            else if (strcmp(_1st, "find_user") == 0)
            {
                free(_1st);
                _2nd = input(_2nd);
                /*find the user*/
                account *pre = search_acc(head_of_accs, _2nd);
                if (pre == NULL)
                {
                    printf("search failed.\n");
                }
                /* if you find it prints its data and posts*/
                else
                {
                    char *username = pre->next_acc->name;
                    printf("name: %s\n", username);
                    post *curr = head_of_posts->next_post;
                    while ((curr != NULL))
                    {
                        if (strcmp(username, curr->user_name) == 0)
                        {
                            printf("%s\npost_ID:%d\nlike:%d\n", curr->txt, curr->post_ID, curr->like);
                        }
                        curr = curr->next_post;
                    }
                }
                free(_2nd);
            }
            else
            {
                free(_1st);
                printf("this command is not invalid!\nenter another command!\n");
            }
        }
        else
        {
            printf("some thing trrible has happend");
            free(_1st);
            FILE *accounts = fopen("accounts.txt", "w");
            write_accounts(head_of_accs, head_of_posts, accounts);
            fclose(accounts);
            FILE *posts = fopen("posts.txt", "w");
            write_posts(head_of_posts, posts);
            fclose(posts);
            break;
        }
    }
    /*compile it with gcc main.c input.c add.c creat_list.c delete.c search.c str_to_int.c write.c -o main */
}