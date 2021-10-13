#ifndef BUTTERMILK_H
#define BUTTERMILK_H

/* MACROS */
#define LENGTH(X)               (sizeof X / sizeof X[0])

typedef struct {
    const char *id, *lname, *sname;
    int isflag, isset;
    char *description;
    char *value;
} Option;

#endif /* BUTTERMILK_H */
