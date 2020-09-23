#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Stack {
    Data * a;
    unsigned int size;
    unsigned int n;
};

void stack_init(struct Stack * s) {
    s->n = 0;
    s->size += 1;
    s->a = malloc(s->size * sizeof(Data));
}

void stack_push(struct Stack * s, Data data) {

    if (s->n == s->size) {
        s->size += 1;
        s->a = realloc(s->a, s->size * sizeof(Data));
    }
    s->a[s->n] = data;
    s->n ++;
}
struct Stack stack_new() {
   struct Stack * s;
   s = malloc(sizeof(struct Stack));
   stack_init(s);
   return *s;
}
void stack_print(struct Stack * s) {
    int i;
    for(i = 0; i < s->n; i++) {
        printf("%d ", s->a[i]);
    printf("\n");
    }
}

void pop_back(struct Stack * s) {
    if (s->n == 0){
        return 0;
    }
    s->size -= 1;
    s->a = realloc(s->a, s->size * sizeof(Data));
    s->n--;
}

int main(void){
    struct Stack s = stack_new();
    char ans[80];
    int numb;
    while (1){
        scanf("%s", &ans);
        if (strcmp(ans, "push") == 0){
            scanf("%d", &numb);
            stack_push(&s, numb);
        }
        if (strcmp(ans, "print") == 0){
            stack_print(&s);
        }
        if (strcmp(ans, "pop") == 0){
            pop_back(&s);
        }
    }

}
