// Singly Linear Linked List

#include<stdio.h>
#include<stdlib.h>

#define swap(a,b)  int temp = a; a = b; b = temp;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void selection_sort();

struct node* create_node()
{
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr;
}

void add_first(int data)
{
    struct node* ptr = create_node();
    ptr->data = data;
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void display()
{
    if(head == NULL)
    {
        printf("The Linked List is Empty\n");
    }
    else
    {
        struct node *trav;
        trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

void add_last(int data)
{
    struct node *ptr = create_node();
    ptr->data = data;
    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *trav = head;
        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("The Linked List is Empty\n");
    else
    {
        struct node *trav = head;
        while(trav != NULL)
        {
            trav = trav->next;
            count++;
        }
    }
    return count;
}


void add_at_specific_pos(int pos, int data)
{
    if(head == NULL)
    {
        if(pos ==  1)
        {
            add_first(data);
        }
        else    
            printf("Invalid\n");
    }

    else if(pos == 1)
    {
        add_first(data);
    }

    else if( pos == (count_nodes()+1))
    {
        add_last(data);
    }

    else if(pos < 1 || pos > count_nodes()+1)
    {
        printf("Invalid\n");
    }

    else
    {
        struct node *ptr = create_node();
        ptr->data = data;
        struct node *trav = head;
        for(int i=1; i<pos-1; i++)
        {
            trav = trav->next;
        }
        ptr->next = trav->next;
        trav->next = ptr;
    }
        
}

void delete_first()
{
    if(head == NULL)
    {
        printf("The Linked List is Empty\n");
    }

    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
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

    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    
    else
    {
        struct node *trav = head;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}

void delete_at_specific_pos(int pos)
{
    if(head == NULL)
    {
        printf("The Linked List is Empty\n");
    }

    else if (pos == 1)
    {
        delete_first();
    }

    else if (pos == count_nodes())
    {
        delete_last();
    }

    else if (pos < 1 || pos > count_nodes())
    {
        printf("Invalid\n");
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

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    add_last(15);
    display();
    selection_sort();
    display();
   
}

void selection_sort()
{
    struct node *trav = head;
    struct node *j;
    for(trav; trav->next != NULL; trav = trav->next)
    {
        for( j = trav->next; j != NULL; j = j->next)
        {
            if(j->data < trav->data)
            {
                swap(trav->data,j->data);
            }
        } 
    }
}
