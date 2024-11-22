#include<stdio.h>
#define SIZE 15

int a[SIZE], c, p, n = 0;

void bst(int ele) {
    if (a[0] == NULL) {
        a[0] = ele;
        return;
    }
    c = 0;
    p = -1;
    while (a[c] != NULL) {
        p = c;
        if (ele < a[c])
            c = 2 * c + 1;
        else
            c = 2 * c + 2;
    }
    if (ele < a[p])
        c = 2 * p + 1;
    else
        c = 2 * p + 2;
    a[c] = ele;
}

void display() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (a[i] == NULL)
            continue;
        printf("a[%d] = %d\n", i, a[i]);
    }
}

int main() {
    int ch, i, j, ele;
    for (i = 0; i < SIZE; i++)
        a[i] = NULL;
    
    printf("\n1. Insert Element into BST\n2. Display BST\n");
    for (;;) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number of elements to insert: ");
                scanf("%d", &j);
                printf("\nEnter the elements:\n");
                for (i = 0; i < j; i++) {
                    scanf("%d", &ele);
                    bst(ele);
                }
                break;
            case 2: display(); break;
            default: exit(0);
        }
    }
}
