// Jade Tu
// Chpt5 PA
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for each element in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Queue structure to represent the queue implemented as a linked list
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create and initialize an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueue operation: adds an item to the end of the queue, pseudocode found in PA 5.5.1
void enqueue(Queue* queue, int item) {
    // Allocate new node and assign data (newNode->next is set to NULL)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;
    
    if (queue->front == NULL) {
        // If the queue is empty, set front to the new node
        queue->front = newNode;
    } else {
        // Otherwise, link the new node at the end of the queue
        queue->rear->next = newNode;
    }
    // Update the rear pointer to the new node
    queue->rear = newNode;
}

// Dequeue operation: removes and returns the item from the front of the queue, pseudocode found in PA 5.5.1
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        // Return 0 if the queue is empty
        printf("An item was not dequeued.\n"); //Displays that the item was not removed 
		return 0;
    }
    // Save the data from the front node and move the front pointer
    Node* temp = queue->front;
    int dequeuedItem = temp->data;
    queue->front = temp->next;
    // If the queue becomes empty, update the rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp); // free memory for the dequeued node
    printf("Item %d was removed from the queue.\n", dequeuedItem); // Displays the item that was removed
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL) { //Looks at the queue front and if there isn't anything declares that the queue is empty
		printf("The queue is empty.\n");
	}
	else { // Else, the queue is not empty if it is not null
		printf("The queue is not empty.\n");
	}
}

// Function to peek at the front item without removing it
int peek(Queue* queue) {
    if (queue->front != NULL) { // If the front of the queue is not null, displays the data of the front of the queue's data
		printf("The top item on the queue is: %d\n", queue->front->data);
	}
	else {
		printf("The queue is empty.\n"); // If the queue is empty, declares that the queue is empty
	}
}

// Function to get the length of the queue
int getLength(Queue* queue) {
	int length = 0; // declares and initializes the variable length at 0
    Node* curNode = queue->front; // puts the current node as the first in the queue 
	while (curNode != NULL) { // while there are still nodes to count 
		length += 1; // adds 1 to length 
		curNode = curNode->next; // moves onto the next node 
	}
	printf("The queue's length is: %d\n", length); // when it's done, will display what the length of the queue is 
}

// Function to traverse and display the queue
void displayQueue(Queue* queue) {
    Node* curNode = queue->front; // starts from the beginning of the queue
	while (curNode != NULL) { // while there are still nodes in the queue
		printf("%d -> ", curNode->data); // prints the data of the current node
		curNode = curNode->next; // moves onto the next node 
	}
	printf("NULL\n"); // if it is null, will display null 
}

int main() {
    Queue* queue = createQueue();
    
   // Implement the main method
   displayQueue(queue);								// 1. Display the queue
   isEmpty(queue);										// 2. Call isEmpty to display if the queue is empty
   peek(queue);											// 3. Call peek and display the top item in the queue
   getLength(queue);									// 4. Display the queue's length
   enqueue(queue, 1);									// 5. Enqueue item 1 to queue
   enqueue(queue, 2);									// 6. Enqueue item 2 to queue 
   peek(queue);											// 7. Call peek and display the top item in the queue
   enqueue(queue, 3);									// 8. Enqueue item 3 to queue 
   getLength(queue);									// 9. Display the queue's length 
   dequeue(queue);										// 10. Dequeue an item from the queue and display the item's value
   peek(queue);											// 11. Call peek and display the top item in the queue
   enqueue(queue, 4);									// 12. Enqueue item 4 to queue
   displayQueue(queue);								// 13. Display the queue
   enqueue(queue, 5);									// 14. Enqueue item 5 to queue
   dequeue(queue);										// 15. Dequeue an item from the queue and display the item's value
   enqueue(queue, 6);									// 16. Enqueue item 6 to queue
   getLength(queue);									// 17. Display the queue's length
   displayQueue(queue);								// 18. Display the queue
   dequeue(queue);										// 19. Dequeue an item from the queue and display the item's value
   isEmpty(queue);										// 20. Call isEmpty to display if the queue is empty
   dequeue(queue);										// 21. Dequeue an item from the queue and display the item's value
   dequeue(queue);										// 22. Dequeue an item from the queue and display the item's value
   getLength(queue);									// 23. Display the queue's length
   dequeue(queue);										// 24. Dequeue an item from the queue and display the item's value
   dequeue(queue);										// 25. Dequeue an item from the queue and display the item's value
   isEmpty(queue);										// 26. Call isEmpty to display if the queue is empty
   
   
    
    // Free the queue structure (all nodes should have been dequeued by now)
    free(queue);
    
    return 0;
}
