#include <stdlib.h>
#include <stdio.h>

typedef struct tnode {
    int data;
    struct tnode *right, *left;
} TNODE;

TNODE *CreateBST(TNODE *, int);
void Preorder(TNODE *);

int main() {
    TNODE *root = NULL;
    int opn, elem, n, i;

    do {
        printf("\n Binary Search Tree Operations \n");
        printf("\n 1. Create BST");
        printf("\n 2. Traverse in Preorder");
        printf("\n 3. Exit");
        printf("\n Your option? ");
        scanf("%d", &opn);

        switch (opn) {
            case 1:
                root = NULL;
                printf("\nHow many nodes do you want to add to the BST? ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("\nEnter data for node %d: ", i);
                    scanf("%d", &elem);
                    root = CreateBST(root, elem);
                }
                printf("\nBST is ready!\n");
                break;
            case 2:
                printf("\nBST Preorder Traversal: \n");
                Preorder(root);
                break;
            default:
                printf("\nInvalid Option! Try Again.\n");
                break;
        }
        printf("\nPress any key to continue...");
        getchar(); // To consume the newline character
        getchar();
    } while (opn != 3);

    return 0;
}

TNODE *CreateBST(TNODE *root, int elem) {
    if (root == NULL) {
        root = (TNODE *)malloc(sizeof(TNODE));
        root->left = root->right = NULL;
        root->data = elem;
        return root;
    } else {
        if (elem < root->data)
            root->left = CreateBST(root->left, elem);
        else if (elem > root->data)
            root->right = CreateBST(root->right, elem);
        else
            printf("Duplicate Element! Not Allowed!\n");

        return root;
    }
}

void Preorder(TNODE *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
