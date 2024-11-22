#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node NODE;
NODE *first, *temp, *cur, *prev, *next;

void main() {
    int ch;
    clrscr();
    while(1) {
        printf("..... Doubly Linked List ......\n");
        printf("1. Insert Front \t 2. Delete based on Key \t 3. Display\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: add_front(); break;
            case 2: del(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}

void add_front() {
    temp = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the item: ");
    scanf("%d", &temp->info);
    temp->llink = NULL;
    temp->rlink = NULL;
    if(first == NULL) {
        first = temp;
        return;
    }
    temp->rlink = first;
    first->llink = temp;
    first = temp;
}

void display() {
    if(first == NULL) {
        printf("\nList is empty");
        return;
    }
    temp = first;
    printf("\n.... List status...\n");
    while(temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->rlink;
    }
}

void del() {
    int item;
    if(first == NULL) {
        printf("\nList is empty");
        return;
    }
    printf("Enter the item to delete: ");
    scanf("%d", &item);
    cur = first;
    while(cur != NULL) {
        if(cur->info == item) {
            if(cur == first) {
                first = first->rlink;
                first->llink = NULL;
                free(cur);
                return;
            } else if(cur->rlink == NULL) {
                cur->llink->rlink = NULL;
                free(cur);
                return;
            } else {
                cur->llink->rlink = cur->rlink;
                cur->rlink->llink = cur->llink;
                free(cur);
                return;
            }
        }
        cur = cur->rlink;
    }
    printf("Item not found");
}
