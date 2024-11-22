#include<stdio.h>

void heapify(int [], int, int);

int main() {
    int a[10], n, i;
    printf("Enter the number of incoming packets\n");
    scanf("%d", &n);
    printf("Enter the priority of the arriving packets\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        heapify(a, n, i);
    }
    printf("The order of outgoing traffic\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

void heapify(int a[], int n, int i) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    
    if (left < n && a[left] > a[root])
        root = left;
    if (right < n && a[right] > a[root])
        root = right;
    if (root != i) {
        temp = a[i];
        a[i] = a[root];
        a[root] = temp;
        heapify(a, n, root);
    }
}
