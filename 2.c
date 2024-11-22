#include<stdio.h>
#define maxsize 4

int q[maxsize], front = -1, rear = -1;

void main() {
    int ch;
    while(1) {
        clrscr();
        puts("\n.....Queue Operations.....\n");
        puts("1. Add\n2. Delete\n3. Display\n4. Exit\n");
        puts("Enter your choice ->");
        scanf("%d", &ch);
        switch(ch) {
            case 1: add(); break;
            case 2: del(); break;
            case 3: display(); break;
            default: return;
        }
        getch();
    }
}

void del() {
    if(front == -1) {
        puts("\n...Queue is empty...\n");
        return;
    }
    printf("\nElement deleted is %d\n", q[front]);
    front++;
    if(front > rear)
        front = rear = -1;
}

void add() {
    int x;
    if(rear == maxsize - 1) {
        puts("\n..Queue is full..\n");
        return;
    }
    puts("Enter element");
    scanf("%d", &x);
    q[++rear] = x;
    if(front == -1)
        front++;
}

void display() {
    int i;
    printf(" \nQueue status...\n");
    if(front == -1)
        puts("\nQueue is empty\n");
    else
        for(i = front; i <= rear; i++)
            printf("%d \t", q[i]);
}
