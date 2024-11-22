#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    char name[20];
    struct node *right, *left;
};

struct node *CreateBST(struct node *, int, char[]);
void Inorder(struct node *);

int main() {
    struct node *root = NULL;
    int opn, empid, n, i;
    char ename[20];

    do {
        printf("\nPress 1 - Create BST");
        printf("\nPress 2 - Generate Report");
        printf("\nPress 3 - Exit");
        printf("\nYour option? ");
        scanf("%d", &opn);

        switch (opn) {
            case 1:
                root = NULL;
                printf("\nHow many employees logged in today? ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter Employee ID and Name for employee %d: ", i);
                    scanf("%d%s", &empid, ename);
                    root = CreateBST(root, empid, ename);
                }
                break;
            case 2:
                printf("\nReport (Employee IDs in ascending order):\n");
                In
