#include <stdio.h>
#include <stdlib.h>
#define n 5
int top = -1;
int stack[n];
void push();
void pop();
void disp();
void main()
{
    int choice = 0;

    printf("1.push\n 2.pop\n 3. display\n");
    while (choice < 4)
    {
        printf("enter choice\n");

        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            disp();
            break;
        }
    }
}
void push()
{
    int ele;
    printf("enter element\n");
    scanf("%d", &ele);
    if (top == n - 1)
    {
        printf("overflow\n");
    }
    else
    {
        top++;
    }
    stack[top] = ele;
}
void pop()
{
    top--;
    printf("element %d is deleted\n", stack[top + 1]);
}
void disp()
{
    if (top == -1)
    {
        printf("empty");
    }
    else
        printf("elements present in the stack\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
