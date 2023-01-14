#ifndef ACC
#define ACC
typedef struct account
{
    char *name;
    char *pass;
    /* for check likes easier*/
    int acc_ID;
    struct account *next_acc;
} account;
#endif
