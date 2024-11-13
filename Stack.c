#include <stdio.h>
#include <stdlib.h>

int n, arr[100];
int Top = -1;

void Push();
void Pop();
void Show();

int main() {
    int choice;

    printf("\nEnter the size of the array (max 100): ");
    scanf("%d", &n);

    if (n > 100) {
        printf("Size exceeds max limit\n");
        exit(0);
    }

    while (1) {
        printf("\nOperations performed by stack:");
        printf("\n1. Push\n2. Pop\n3. Show\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Push(); break;
            case 2: Pop(); break;
            case 3: Show(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }

    return 0;
}

void Push() {
    int item;
    printf("Value of n is: %d\n", n);
    if (Top == n - 1) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &item);
        Top = Top + 1;
        arr[Top] = item;
        printf("Element inserted.\n");
    }
}

void Pop() {
    if (Top == -1) {
        printf("\nUnderflow\n");
    } else {
        printf("Popped Element: %d\n", arr[Top]);
        Top = Top - 1;
    }
}

void Show() {
    int i;
    if (Top == -1) {
        printf("\nUnderflow\n");
    } else {
        printf("Elements present in the stack:\n");
        for (i = Top; i >= 0; i--) {
            printf("%d\n", arr[i]);
        }
    }
}
