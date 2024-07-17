#include <stdio.h>
#include <stdlib.h>
#define n 5
int front = -1;
int rear = -1;
int queue[n];
void enqueue();
void dequeue();
void disp();

void main()
{
    int choice = 0;

    printf("1.insert\n 2.delete\n 3. display\n");
    while (choice < 4)
    {
        printf("\nenter choice\n");

        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            disp();
            break;
        }
    }
}
void enqueue()
{
    int ele;
    printf("enter element\n");
    scanf("%d", &ele);
    if (rear == n - 1)
    {
        printf("overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = ele;
    }
    else
    {
        rear++;
    }
    queue[rear] = ele;
}
void dequeue()
{

    if (front == -1)
    {
        printf("underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("element %d is deleted\n", queue[front]);
        front++;
    }
}
void disp()
{
    if (front == -1)
    {
        printf("empty\n");
    }
    else
        printf("elements present in the queue\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}
