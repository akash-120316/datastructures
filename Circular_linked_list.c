#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;

    struct node *next, *prev;
};
struct node *last = NULL;
struct node *prev, *head;
void insertatBEG(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = val;
    if (last == NULL)
    {
        newnode->next = newnode;
        last = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }
    printf("inserted %d at begg", val);
}
void display()
{
    if (last == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = last->next; // startingg node
    printf("Elements in the list are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
}
void insertatSpePos(int pos, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    struct node *ptr;
    ptr = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}
void deleteatpos(int pos)
{
    int i;
    struct node *ptr = head;

    struct node *prev;
    if (ptr == NULL)
    {
        printf("list is empty");
        return;
    }
    if (pos == 0)
    {
        ptr = head;
        head = head->next;
        printf("Deleted %d", ptr->data);

        free(ptr);
        return;
    }
    for (i = 1; i <= pos; i++)
    {
        prev = ptr;      ////prev ptr rendum initial position..
        ptr = ptr->next; ////ptr mattum next
    }
    if (ptr == NULL)
    {
        printf("invalid position");
        return;
    }
    prev->next = ptr->next;
    printf("%d", ptr->data);
    free(ptr);
}
void deletatBEG()
{
    struct node *ptr;
    ptr = last->next;
    last->next = ptr->next;
    printf("%d", ptr->data);
    free(ptr);
}
void deleteatend()
{
    struct node *prev, *ptr;
    ptr = last->prev;
    ptr->next = last->next;
    last = ptr;
    printf("%d", last->data);
    free(last);

    prev->next = NULL;
    free(ptr);
}

void insertatend()
{
    int val;
    printf("enter val");
    scanf("%d", &val);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = val;
    if (last == NULL)
    {
        newnode->next = newnode;
        last = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }
    printf("inserted %d at begg", val);
}
void dispatpos()
{
    int pos;
    printf("enter pos");
    scanf("%d", &pos);
    struct node *ptr;
    ptr = head;
    for (int i = 1; i <= pos; i++)
    {
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}
void length()
{

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;

    int len;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    printf("%d", len);
}
int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("\n -------- Linked List Menu -----------\n");
        printf("1.Insert at Beginning\n");
        printf("2.Display the list\n");
        printf("3.Insert at specified position \n");
        printf("4.Delete from specified position\n");
        printf("5.deletatBEG\n");
        printf("6.insertatend\n");
        printf("7.deleteatend\n");
        printf("8.dispatpos\n");
        printf("9.length\n");
        printf("10.Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter data");
            scanf("%d", &val);

            insertatBEG(val);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("enter pos,val");
            scanf("%d", &pos);
            scanf("%d", &val);
            if (pos == 0)
            {
                insertatBEG(val);
            }
            else
            {
                insertatSpePos(pos, val);
            }
            break;
        case 4:
            printf("enter pos");
            scanf("%d", &pos);
            deleteatpos(pos);
            break;

        case 5:
            deletatBEG();
            break;
        case 6:
            insertatend();
            break;
        case 7:
            deleteatend();
            break;
        case 8:
            dispatpos();
            break;
        case 9:
            length();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("enter crct choice");
        }
    }
    return 0;
}
