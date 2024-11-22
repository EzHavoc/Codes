#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>

struct node {
    int info;
    struct node *link;
};

struct node *root = NULL;
int c;

void display() {
    struct node *temp;
    if(root == NULL)
        printf("List is empty\n");
    else {
        temp = root;
        while(temp != NULL) {
            printf("%d\t", temp->info);
            temp = temp->link;
        }
    }
}

void del_front() {
    struct node *temp;
    if(root == NULL)
        printf("List is empty\n");
    else {
        temp = root;
        printf("Item deleted is %d\n", temp->info);
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
}

void inspos() {
    struct node *temp, *p;
    int i, loc;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the item\n");
    scanf("%d", &temp->info);
    temp->link = NULL;
    printf("Enter location to be inserted\n");
    scanf("%d", &loc);
    
    if(loc > length() || loc == 0)
        printf("Invalid position\n");
    else if(loc == 1) {
        temp->link = root;
        root = temp;
    } else {
        p = root;
        for(i = 1; i < loc - 1; i++)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
}

void main() {
    int ch;
    clrscr();
    while(1) {
        printf("1. Insert at position\n2. Delete front\n3. Display\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: inspos(); break;
            case 2: del_front(); break;
            case 3: display(); break;
            default: exit(0);
        }
    }
}
