#include<stdio.h>
#include<process.h>
#define SIZE 5

void push();
int pop();
void display();

int s[SIZE], i, top = -1, ch, item, item_deleted;

void main() {
    while(1) {
        printf("1. push\n2. pop\n3. display\n4. exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: push(); break;
            case 2: 
                item_deleted = pop();
                if(item_deleted == -1)
                    printf("Stack empty\n");
                else
                    printf("Item deleted = %d\n", item_deleted); 
                break;
            case 3: display(); break;
            default: exit(0);
        }
    }
}

void push() {
    if(top == SIZE - 1)
        printf("Stack is Full\n");
    else {
        printf("Enter the element to insert\n");
        scanf("%d", &item);
        top = top + 1;
        s[top] = item;
    }
}

int pop() {
    if(top == -1) 
        return -1;
    return s[top--];
}

void display() {
    if(top == -1)
        printf("Stack is empty\n");
    else {
        printf("Contents of stack\n");
        for(i = 0; i <= top; i++)
            printf("%d\t", s[i]);
    }
}
