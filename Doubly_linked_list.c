#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertatBEG(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = val;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = NULL;
        head = newnode;
    }
    printf("inserted %d at begg", val);
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;

    printf("Elements in the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void displayrev()
{
    if (tail == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = tail;
    printf("Elements in the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
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

    if (ptr->next == NULL)
    {
        tail = newnode;
        ptr->next = newnode;
        newnode->next = NULL;
        newnode->prev = ptr;
    }
    else
    {
        newnode->next = ptr->next;
        ptr->next->prev = newnode;

        ptr->next = newnode;
        newnode->prev = ptr;
    }
}
void deleteatpos(int pos)
{
    int i;
    struct node *ptr = head;

    struct node *pre;
    if (ptr == NULL)
    {
        printf("list is empty");
        return;
    }
    if (pos == 0)
    {
        ptr = head;
        head = ptr->next;
        head->prev = NULL;
        printf("%d", ptr->data);
        free(ptr);
    }
    for (i = 1; i <= pos; i++)
    {
        pre = ptr;       ////prev ptr rendum initial position..
        ptr = ptr->next; ////ptr mattum next
    }

    pre->next = ptr->next;
    ptr->next->prev = pre;
    printf("%d", ptr->data);
    free(ptr);
}
void deletatBEG()
{
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    head->prev = NULL;
    printf("%d", ptr->data);
    free(ptr);
}
void deleteatend()
{
    struct node *ptr;
    ptr = tail;
    struct node *before = tail->prev;
    before->next = NULL;
    tail = before;
    printf("%d", ptr->data);

    free(ptr);
}
void insertatend()
{
    int val;
    printf("enter val");
    scanf("%d", &val);
    struct node *ptr, *prev;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    tail->next = newnode;
    newnode->next = NULL;
    newnode->prev = tail;
    tail = newnode;

    printf("%d", newnode->data);
}
void dispatpos()
{

    struct node *temp = head;

    int len;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    printf("choose between length =%d\n", len);

    printf("enter pos");
    int pos;
    scanf("%d", &pos);
    if (pos > len)
    {
        printf("enter crct positio");
    }
    else
    {
        struct node *ptr;
        ptr = head;
        for (int i = 1; i <= pos; i++)
        {
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
    }
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
void revoflist()
{
    struct node *current = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev; // reversall
        prev = current;
        current = next;
    }
    head = prev;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    struct node *temp = head;

    printf("Elements in the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("\n -------- Linked List Menu -----------\n");
        printf("1.Insert at Beginning\n");

        printf("2.Insert at specified position \n");
        printf("3.insertatend\n");
        printf("4.Display the list\n");
        printf("5.display rev\n");
        printf("6.deletatBEG\n");
        printf("7.Delete from specified position\n");
        printf("8.deleteatend\n");
        printf("9.dispatpos\n");
        printf("10.length\n");
        printf("11.exit\n");
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
        case 3:
            insertatend();
            break;
        case 4:
            display();
            break;
        case 5:
            displayrev();
            break;
        case 6:
            deletatBEG();
            break;

        case 7:
            printf("enter pos");
            scanf("%d", &pos);
            deleteatpos(pos);
            break;

        case 8:
            deleteatend();
            break;
        case 9:
            dispatpos();
            break;
        case 10:
            length();
            break;

        case 11:
            exit(0);
            break;

        default:
            printf("enter crct choice");
        }
    }
    return 0;
}
