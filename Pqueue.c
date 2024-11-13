#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of elements in the queue

// Structure to represent a priority queue element
struct PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
};

// Function to initialize the priority queue
void initQueue(struct PriorityQueue *pq) {
    pq->size = 0;
}

// Function to insert an element into the priority queue
void insert(struct PriorityQueue *pq, int value, int priority) {
    if (pq->size == MAX) {
        printf("Priority Queue is full.\n");
        return;
    }
    // Insert the new element at the end
    int i = pq->size++;
    pq->data[i] = value;
    pq->priority[i] = priority;

    // Rearrange the elements to maintain the priority order
    while (i > 0 && pq->priority[i] > pq->priority[(i - 1) / 2]) {
        // Swap with parent
        int tempData = pq->data[i];
        int tempPriority = pq->priority[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->priority[i] = pq->priority[(i - 1) / 2];
        pq->data[(i - 1) / 2] = tempData;
        pq->priority[(i - 1) / 2] = tempPriority;
        i = (i - 1) / 2;
    }
}

// Function to extract the element with the highest priority
int extractMax(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return -1; // Indicate empty queue
    }
    int maxValue = pq->data[0];
    pq->data[0] = pq->data[--(pq->size)];
    pq->priority[0] = pq->priority[pq->size];

    // Rearrange the elements to maintain the priority order
    int i = 0;
    while (i < pq->size / 2) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        // Check if left child is greater
        if (leftChild < pq->size && pq->priority[leftChild] > pq->priority[largest]) {
            largest = leftChild;
        }
        // Check if right child is greater
        if (rightChild < pq->size && pq->priority[rightChild] > pq->priority[largest]) {
            largest = rightChild;
        }
        // If largest is not the current node, swap and continue
        if (largest != i) {
            int tempData = pq->data[i];
            int tempPriority = pq->priority[i];
            pq->data[i] = pq->data[largest];
            pq->priority[i] = pq->priority[largest];
            pq->data[largest] = tempData;
            pq->priority[largest] = tempPriority;
            i = largest;
        } else {
            break;
        }
    }
    return maxValue;
}

// Function to display the priority queue
void display(struct PriorityQueue *pq) {
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->data[i], pq->priority[i]);
    }
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);

    // Inserting elements into the priority queue
    insert(&pq, 5, 1);
    insert(&pq, 10, 3);
    insert(&pq, 15, 2);
    insert(&pq, 20, 5);
    insert(&pq, 25, 4);

    display(&pq);

    // Extracting elements from the priority queue
    printf("Extracted max: %d\n", extractMax(&pq));
    printf("Extracted max: %d\n", extractMax(&pq));

    display(&pq);

    return 0;
}
