#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* llink, *rlink;
};
struct node *root = NULL;

void insrear() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the page number\n");
    scanf("%d", &temp->info);
    temp->llink = NULL;
    temp->rlink = NULL;

    if (root == NULL)
        root = temp;
    else {
        struct node *p = root;
        while (p->rlink != NULL)
            p = p->rlink;
        p->rlink = temp;
        temp->llink = p;
    }
}

void display() {
    struct node *temp;
    if (root == NULL)
        printf("Cache is empty\n");
    else {
        temp = root;
        while (temp != NULL) {
            printf("Page: %d\t", temp->info);
            temp = temp->rlink;
        }
    }
}

void delrear() {
    struct node *temp1, *temp2;
    if (root == NULL)
        printf("Cache is empty\n");
    else {
        temp2 = root;
        if (temp2->rlink == NULL) {
            root = NULL;
            free(temp2);
        } else {
            while (temp2->rlink != NULL) {
                temp1 = temp2;
                temp2 = temp2->rlink;
            }
            temp2->llink = NULL;
            temp1->rlink = NULL;
            free(temp2);
        }
    }
}

int main() {
    int ch;
    for (;;) {
        printf("\n1. Insert Page\n2. Delete Last Visited Page\n3. Display Cache\n4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insrear(); break;
            case 2: delrear(); break;
            case 3: display(); break;
            default: exit(0);
        }
    }
}
