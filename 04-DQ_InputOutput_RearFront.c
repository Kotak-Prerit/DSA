#include <stdio.h>
#define Size 5
int DQ[Size];
int front = -1;
int rear = -1;
void insert_rear() /*Begin of insert_rear*/
{
    int added_item;
    if ((front == 0 && rear == Size - 1) || (front == rear + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) /* if queue is initially empty */
    {
        front = 0;
        rear = 0;
    }
    else if (rear == Size - 1) /*rear is at last position of queue */
        rear = 0;
    else
        rear = rear + 1;

    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    DQ[rear] = added_item;
} /*End of insert_rear*/
void insert_front() /*Begin of insert_front*/
{
    int added_item;
    if ((front == 0 && rear == Size - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1) /*If queue is initially empty*/
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = Size - 1;
    else
        front = front - 1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    DQ[front] = added_item;
} /*End of insert_front*/
/*Begin of delete_front*/
void delete_front()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from the front of queue is : %d\n", DQ[front]);
    DQ[front] = 0;
    if (front == rear) /*Queue has only one element */
    {
        front = -1;
        rear = -1;
    }
    else if (front == Size - 1)
        front = 0;
    else
        front = front + 1;
} /*End of delete_front*/
void delete_rear() /*Begin of delete_rear*/
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from the rear of queue is : %d\n", DQ[rear]);
    DQ[rear] = 0;
    if (front == rear) /*queue has only one element*/
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = Size - 1;
    else
        rear = rear - 1;
} /*End of delete_rear*/
void display_queue() /*Begin of input_que*/
{
    int i;
    printf("\n\t\t\tInformation in DQueue\n\n");
    if (rear == -1)
    {
        printf("\t\t| ");
        for (i = 0; i < Size; i++)
            printf(" | ");
        printf("\n\n");
    }
    else
    {
        printf("\t\t | ");
        for (i = 0; i < Size; i++)
            printf("%d | ", DQ[i]);
        printf("\n\n");
    }
} /*End of display_queue*/
void input_que() /*Begin of input_que*/
{
    int choice;
    do
    {
        printf("1. Insert at rear\n");
        printf("2. Delete from front\n");
        printf("3. Delete from rear\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            delete_rear();
            break;
        case 4:
            display_queue();
            break;
        case 5:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 5);
} /*End of input_que*/
void output_que() /*Begin of output_que*/
{
    int choice;
    do
    {
        printf("1. Insert at rear\n");
        printf("2. Insert at front\n");
        printf("3. Delete from front\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            display_queue();
            break;
        case 5:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 5);
} /*End of output_que*/
void main() /*Begin of main*/
{
    int choice;
    printf("1. Input restricted dequeue\n");
    printf("2. Output restricted dequeue\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        input_que();
        break;
    case 2:
        output_que();
        break;
    default:
        printf("Wrong choice\n");
    }
}