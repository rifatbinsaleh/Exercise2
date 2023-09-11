#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node at the middle of the linked list
void insertAtMiddle(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node from the beginning of the linked list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete a node from the middle of the linked list
void deleteFromMiddle(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }
    if (current->next == NULL) {
        printf("Position is out of bounds. Nothing to delete.\n");
        return;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Function to search for a value in the linked list
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Return -1 if the value is not found
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert elements at various positions
    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtMiddle(&head, 4, 2);

    // Display the linked list
    printf("Linked List: ");
    display(head);

    // Delete elements from various positions
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromMiddle(&head, 2);

    // Display the updated linked list
    printf("Updated Linked List: ");
    display(head);

    // Search for a value in the linked list
    int key = 3;
    int position = search(head, key);
    if (position != -1) {
        printf("%d found at position %d.\n", key, position);
    } else {
        printf("%d not found in the linked list.\n", key);
    }

    // Clean up - free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
