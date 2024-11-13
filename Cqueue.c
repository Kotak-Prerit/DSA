//#include <cinttypes>
#include <stdio.h>
#define MAX 5
int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void insert()
{
    int item;
    if((front == 0 && rear == MAX -1) || (front == rear + 1))
    {
        printf("\nQueue Overflow");
        return;
    }
    else
    {
        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if(rear == MAX -1)
            {
                rear = 0;
            }
            else
            {
                rear += 1;
            }
        }
        printf("\nEnter the elements to be inserted\n");
        scanf("%d", &item);
        cqueue_arr[rear] = item;
        printf("\nElement inserted successfully\n");       
    }
}

void deletion()
{
    if(front == -1)
    {
        printf("\nQueue Underflow");
        return;
    }
    printf("\nElement deleted from the queue is: %d\n", cqueue_arr[front]);
    cqueue_arr[front] = 0;
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(front == MAX -1)
         front = 0;
        else
         front += 1;
    }
}

void display()
{
    if(rear == -1)
    {
        printf("\t\t|");
        for(int i=0; i<MAX; i++)
        {
            printf("|");
        }
        printf("\n\n");
    }
    else
    {
        printf("\t\t|");
        for(int i=0;i<MAX;i++)
        {
            printf("%d|", cqueue_arr[i]);
        }
        printf("\n\n");
    }
}

int main()
{
    int choice, item;
    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Quit");
        printf("\nEnter you choice:");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: insert(); break;
            case 2: deletion(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("\nWrong Choice!\n");
        }
    }
    while(choice != 4);
    return 0;
}
