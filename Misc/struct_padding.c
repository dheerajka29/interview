#include <stdio.h>

struct st {
    char c;
    double d;
    int s;
};
int main (void) {
    printf("%d\n",sizeof(struct st));
}

