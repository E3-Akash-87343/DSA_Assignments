#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} snode;

snode *head = NULL;

snode* create_node();
void add_first(int data);
void forward_display();
void backward_display();
void add_last(int data);
void add_at_pos(int pos, int data);
int count();
void delete_first();
void delete_last();
void delete_at_pos(int pos);
snode* linear_search();

int main()
{
    add_first(25);
    add_first(20);
    add_first(10);
    add_last(40);
    add_at_pos(1,5);
    delete_at_pos(3);
    forward_display();
    backward_display();
    linear_search();
}

snode* create_node()
{
    snode *new_node = (snode*)malloc(sizeof(snode));
    new_node->data = 0;
    return new_node;
}

void add_first(int data)
{
    snode *new_node = create_node();
    new_node->data = data;
    if(head == NULL)
    {
        head = new_node;
        head->prev = head;
        head->next = head;
    }
    else
    {
        head->prev->next = new_node;
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void forward_display()
{
    snode *trav = head;
    printf("Head");
    do
    {
        printf("->%d",trav->data);
        trav = trav->next; 
    } while (trav != head);
    printf("\n");
}

void backward_display()
{
    snode *trav = head->prev;
    printf("Tail");
    do
    {
        printf("->%d",trav->data);
        trav = trav->prev;
    } while (trav->next != head);
    printf("\n");
    
}

void add_last(int data)
{
    snode *new_node = create_node();
    new_node->data = data;
    if(head == NULL)
    {
        head = new_node;
        head->prev = head;
        head->next = head;
    }
    else
    {
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

void add_at_pos(int pos, int data)
{
    if(head == NULL)
    {
        if(pos == 1)
        {
            snode *new_node = create_node();
            new_node->data = data;
            head = new_node;
            head->prev = head;
            head->next = head;
        }
        else
            printf("Invalid\n");
    }

    else
    {
        int c = count();

        if(pos == 1)
        {
            add_first(data);
        }

        else if(pos == c+1)
        {
            add_last(data);
        }

        else if(pos < 1 || pos > c+1)
        {
            printf("Invalid\n");
        }

        else
        {
            
        }

    }
}

int count()
{
    int c = 1;
    snode *trav = head;
    while(trav->next != head)
    {
        c++;
        trav = trav->next;
    }
    return c;
}

void delete_first()
{
    if(head == NULL)
    {
        printf("The List is Empty\n");
    }

    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }

    else
    {
        snode *temp = head;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        free(temp);
        temp = NULL;
    }


}

void delete_last()
{
    if(head == NULL)
    {
        printf("The List is Empty\n");
    }

    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }

    else
    {
       head->prev = head->prev->prev;
       free(head->prev->next);
       head->prev->next = head;
    }
}

void delete_at_pos(int pos)
{
    int c = count();
    
    if(head == NULL)
    {
        printf("The List is Empty\n");
    }

    else if(head->next == head)
    {
        if(pos == 1)
        {
            free(head);
            head = NULL;
        }

        else
        {
            printf("Invalid!\n");
        }
    }

    else if(pos == 1)
    {
        delete_first();
    }

    else if(pos == c)
    {
        delete_last();
    }

    else if(pos < 1 || pos > c)
    {
        printf("Invalid\n");
    }

    else
    {
        snode *trav = head;
        for(int i = 1; i < pos-1; i++)
        {
            trav = trav->next;
        }
       trav->next = trav->next->next;
       free(trav->next->prev);
       trav->next->prev = trav;
    }
}

snode* linear_search()
{
    int key = 25;
    snode *trav = head;
    do
    {
        if(trav->data == key)
        {
            printf("Key(%d) Found!!\n",trav->data);
            return trav;
        }
        trav = trav->next;
    }
    while(trav != head);
    printf("The key is not found\n");
} 
