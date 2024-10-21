#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};


struct node *head = NULL;
struct node* create_node();
void add_start(int data);
void display();
void add_last(int data);
void add_at_pos(int pos,int data);
int count();
void delete_first();
void delete_last();
void delete_at_pos(int pos);
void reverse();


int main()
{
    add_start(10);
    add_start(5);
    //display();
    add_last(100);
    //display();
    add_at_pos(3,20);
    // display();
    // delete_first();// 10,20,100
    // display();
    // //delete_last();// 10,20
    // delete_at_pos(-1); // 10,100
    display();
    reverse();
    display();
}

struct node* create_node()
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

void add_start(int data)
{
    struct node *new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        head->next = head;
    }

    else
    {
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        new_node->next = head;
        trav->next = new_node;
        head = new_node;
    }
}

void display()
{
    struct node *trav = head;
    printf("Head");
    do
    {
        printf("->%d",trav->data);
        trav = trav->next;
    }
    while(trav != head);
    printf("\n");
}

void add_last(int data)
{
    struct node *new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        head->next = head;
    }

    else
    {
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next = head;
    }
}

void add_at_pos(int pos,int data)
{
    int c = count();
    
    
    if(head == NULL)
    {
        if(pos == 1)
        {
            struct node *new_node = create_node();
            new_node->data = data;
            head = new_node;
            head->next = head;
        }
        else
            printf("Invalid!\n");
    }

    else
    {

        if(pos == 1)
        {
            add_start(data);
        }

        else if(pos == c+1)
        {
            add_last(data);
        }

        else if (pos < 1 || pos > c+1)
        {
            printf("Invalid!\n");
        }

        else
        {
            struct node *new_node = create_node();
            new_node->data = data;
            struct node *trav = head;
            for(int i = 1; i < (pos-1); i++)
            {
                trav = trav->next;
            }
            new_node->next = trav->next;
            trav->next = new_node;
        }
    }

}

int count()
{
    struct node *trav = head;
    int count = 1;
    while(trav->next != head)
    {
        count++;
        trav = trav->next;
    }
    return count;
}

void delete_first()
{
    if(head == NULL)
    {
        printf("The Linked List is Empty\n");
    }

    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }

    else
    {
        struct node *temp = head;
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = temp->next;
        head = temp->next;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
    {
        printf("The Linked List is Empty\n");
    }
    

    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }

    else
    {
        struct node *trav = head;
        while(trav->next->next != head)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head;
    }
}

void delete_at_pos(int pos)
{
    int c = count();

    if(head == NULL)
    {
        printf("The Linked List is Empty\n");
    }
    else
    {
        if(pos == 1)
        {
            delete_first();
        }

        else if (pos == c)
        {
            delete_last();
        }

        else if (pos < 1 || pos > c+1)
        {
            printf("Invalid!\n");
        }

        else
        {
            struct node *trav = head;
            for(int i = 1; i < pos-1; i++)
            {
                trav = trav->next;
            }
            struct node *temp = trav->next;
            trav->next = temp->next;
            free(temp);
            temp = NULL;
        }
    }
}

void reverse()
{
    struct node *n1 = head;
    struct node *n2 = head->next;
    while(n2 != head)
    {
        struct node *n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    } 
    head = n1;
    n2->next = head;
    
    printf("Reversed\n");
}