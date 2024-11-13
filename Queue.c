#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX];
int front = -1, rear = -1;

void addqueue(int item)  // changed char to int for consistency
{
    // adds an element to the queue.
    if (rear == MAX - 1)
    {
        printf("\nQueue is full\n");
        return;
    }
    arr[++rear] = item;

    if (front == -1)
    {
        front = 0;
    }
}

int delqueue()  // changed char to int for consistency
{
    // removes an element from the queue
    int data;

    if (front == -1)
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    data = arr[front];
    arr[front] = 0;

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return data;
}

void display()
{
    // view data of queue.
    printf("\n\t\tInformation in Queue\n\n");
    if (front == -1 && rear == -1)
    {
        printf("\t\tQueue is empty\n");
    }
    else
    {
        printf("\t\t| ");
        for (int i = 0; i < MAX; i++)
        {
            if (i >= front && i <= rear)
                printf("%d | ", arr[i]);
            else
                printf("  | ");  // empty slot indicator
        }
        printf("\n\n");
    }
}

int main()
{
    int item;
    int ch;

    do
    {
        printf("\n\t\tPress 1 for insert item into queue");
        printf("\n\t\tPress 2 for delete item from queue");
        printf("\n\t\tPress 3 for display data of queue");
        printf("\n\t\tPress 4 for exit");
        printf("\n\t\tEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter item to insert: ");
            scanf("%d", &item);
            addqueue(item);
            break;
        case 2:
            item = delqueue();
            if (item != -1)
                printf("\nItem %d is deleted.\n", item);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice! Please enter 1-4.");
        }
    } while (ch != 4);

    return 0;
}