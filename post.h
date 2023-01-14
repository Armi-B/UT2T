#ifndef POST
#define POST
typedef struct post
{
    char *user_name;
    char *txt;
    int like;
    /*person liked before*/
    int *user_like;
    int post_ID;
    struct post *next_post;
} post;
#endif