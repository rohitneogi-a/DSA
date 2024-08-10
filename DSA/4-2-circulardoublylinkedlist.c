#include <stdio.h>
#include <stdlib.h>

// Node structure for a circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a circular doubly linked list
struct Node* createList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Function to display the elements of a circular doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to insert a node at the beginning of a circular doubly linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    head = newNode;
    printf("Node inserted at the beginning.\n");
    return head;
}

// Function to insert a node at the end of a circular doubly linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    printf("Node inserted at the end.\n");
    return head;
}

// Function to delete a node from the beginning of a circular doubly linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty. Cannot delete from the beginning.\n");
    } else {
        if (head->next == head) {
            // If there is only one node in the list
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            free(temp);
        }
        printf("Node deleted from the beginning.\n");
    }
    return head;
}

// Function to delete a node from the end of a circular doubly linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty. Cannot delete from the end.\n");
    } else {
        if (head->next == head) {
            // If there is only one node in the list
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head->prev;
            temp->prev->next = head;
            head->prev = temp->prev;
            free(temp);
        }
        printf("Node deleted from the end.\n");
    }
    return head;
}

// Function to delete a node after a given node in a circular doubly linked list
struct Node* deleteAfterNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty. Cannot delete.\n");
    } else {
        struct Node* current = head;
        do {
            if (current->data == key) {
                // Found the node with the given key
                struct Node* temp = current->next;
                current->next = temp->next;
                temp->next->prev = current;
                free(temp);
                printf("Node deleted after the node with key %d.\n", key);
                return head;
            }
            current = current->next;
        } while (current != head);
        printf("Node with key %d not found. Cannot delete.\n", key);
    }
    return head;
}

// Function to delete the entire circular doubly linked list
void deleteList(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is already empty.\n");
        return;
    }

    struct Node* current = head;
    while (head->next != head) {
        current = head->next;
        head->next = current->next;
        current->next->prev = head;
        free(current);
    }
    free(head);
    printf("Circular doubly linked list deleted.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    do {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. Create a circular doubly linked list\n");
        printf("2. Display\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete after a given node\n");
        printf("8. Delete the entire circular doubly linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to create the circular doubly linked list: ");
                scanf("%d", &value);
                head = createList(value);
                printf("Circular doubly linked list created.\n");
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                head = deleteAfterNode(head, key);
                break;
            case 8:
                deleteList(head);
                head = NULL;
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}
