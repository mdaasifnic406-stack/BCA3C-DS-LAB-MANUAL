//1. Write a program to perform following operation on DOUBLY linked list:
//a. Create a linked list
//b. Display it

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start=NULL;

void create_ll();
void display();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_node();

int main()
{
    int option;

    do
    {
        printf("\n\n ****** MAIN MENU ******");
        printf("\n 1: create a list");
        printf("\n 2: display the list");
        printf("\n 3: add a node at the beginning");
        printf("\n 4: add a node at the end");
        printf("\n 5: add a node before a given node");
        printf("\n 6: add a node after a given node");
        printf("\n 7: delete a node from the beginning");
        printf("\n 8: delete a node from the end");
        printf("\n 9: delete a given node");
        printf("\n 10: EXIT");

        printf("\n\n enter your option : ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                create_ll();
                printf("\n linked list created");
                break;

            case 2:
                display();
                break;

            case 3:
                insert_beg();
                break;

            case 4:
                insert_end();
                break;

            case 5:
                insert_before();
                break;

            case 6:
                insert_after();
                break;

            case 7:
                delete_beg();
                break;

            case 8:
                delete_end();
                break;

            case 9:
                delete_node();
                break;

            case 10:
                printf("\n Exiting...");
                break;

            default:
                printf("\n Invalid option!");
        }

    }while(option !=10);

    return 0;
}

void create_ll()
{
    struct node *new_node, *ptr;
    int num;

    printf("\n enter -1 to end");
    printf("\n enter the data : ");
    scanf("%d",&num);

    while(num != -1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));

        if(new_node==NULL)
        {
            printf("\n Memory allocation failed!");
            return;
        }

        new_node->data=num;
        new_node->next=NULL;

        if(start==NULL)
        {
            new_node->prev=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;

            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }

            ptr->next=new_node;
            new_node->prev=ptr;
        }

        printf("\n enter the data : ");
        scanf("%d",&num);
    }
}

void display()
{
    struct node *ptr;

    if(start==NULL)
    {
        printf("\n linked list is empty");
        return;
    }

    ptr=start;

    printf("\n linked list : ");

    while(ptr!=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
}

void insert_beg()
{
    struct node *new_node;
    int num;

    printf("\n enter the data: ");
    scanf("%d",&num);

    new_node=(struct node*)malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        printf("\n Memory allocation failed!");
        return;
    }

    new_node->data=num;
    new_node->prev=NULL;
    new_node->next=start;

    if(start!=NULL)
    {
        start->prev=new_node;
    }

    start=new_node;

    printf("\n node inserted at beginning");
}

void insert_end()
{
    struct node *ptr, *new_node;
    int num;

    printf("\n enter the data: ");
    scanf("%d",&num);

    new_node=(struct node*)malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        printf("\n Memory allocation failed!");
        return;
    }

    new_node->data=num;
    new_node->next=NULL;

    if(start==NULL)
    {
        new_node->prev=NULL;
        start=new_node;
    }
    else
    {
        ptr=start;

        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }

        ptr->next=new_node;
        new_node->prev=ptr;
    }

    printf("\n node inserted at end");
}

void insert_before()
{
    struct node *new_node,*ptr;
    int num,val;

    if(start==NULL)
    {
        printf("\n linked list is empty");
        return;
    }

    printf("\n enter the data: ");
    scanf("%d",&num);

    printf("\n enter the value before which the data has to insert: ");
    scanf("%d",&val);

    ptr=start;

    while(ptr!=NULL && ptr->data!=val)
    {
        ptr=ptr->next;
    }

    if(ptr==NULL)
    {
        printf("\n given value not found");
        return;
    }

    new_node=(struct node*)malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        printf("\n Memory allocation failed!");
        return;
    }

    new_node->data=num;
    new_node->next=ptr;
    new_node->prev=ptr->prev;

    if(ptr->prev!=NULL)
    {
        ptr->prev->next=new_node;
    }
    else
    {
        start=new_node;
    }

    ptr->prev=new_node;

    printf("\n node inserted before given node");
}

void insert_after()
{
    struct node *new_node,*ptr;
    int num,val;

    if(start==NULL)
    {
        printf("\n linked list is empty");
        return;
    }

    printf("\n enter the data: ");
    scanf("%d",&num);

    printf("\n enter the value after which the data has to be inserted: ");
    scanf("%d",&val);

    ptr=start;

    while(ptr!=NULL && ptr->data!=val)
    {
        ptr=ptr->next;
    }

    if(ptr==NULL)
    {
        printf("\n given value not found");
        return;
    }

    new_node=(struct node*)malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        printf("\n Memory allocation failed!");
        return;
    }

    new_node->data=num;
    new_node->prev=ptr;
    new_node->next=ptr->next;

    if(ptr->next!=NULL)
    {
        ptr->next->prev=new_node;
    }

    ptr->next=new_node;

    printf("\n node inserted after given node");
}

void delete_beg()
{
    struct node *ptr;

    if(start==NULL)
    {
        printf("\n linked list is empty");
        return;
    }

    ptr=start;
    start=start->next;

    if(start!=NULL)
    {
        start->prev=NULL;
    }

    free(ptr);

    printf("\n node deleted from beginning");
}

void delete_end()
{
    struct node *ptr;

    if(start==NULL)
    {
        printf("\n linked list is empty");
        return;
    }

    ptr=start;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    if(ptr->prev!=NULL)
    {
        ptr->prev->next=NULL;
    }
    else
    {
        start=NULL;
    }

    free(ptr);

    printf("\n node deleted from end");
}

void delete_node()
{
    struct node *ptr;
    int val;

    if(start==NULL)
    {
        printf("\n linked list is empty");
        return;
    }

    printf("\n enter the value of the node to be deleted: ");
    scanf("%d",&val);

    ptr=start;

    while(ptr!=NULL && ptr->data!=val)
    {
        ptr=ptr->next;
    }

    if(ptr==NULL)
    {
        printf("\n given value not found");
        return;
    }

    if(ptr->prev!=NULL)
    {
        ptr->prev->next=ptr->next;
    }
    else
    {
        start=ptr->next;
    }

    if(ptr->next!=NULL)
    {
        ptr->next->prev=ptr->prev;
    }

    free(ptr);

    printf("\n node deleted successfully");
}
