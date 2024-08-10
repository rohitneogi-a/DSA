#include <stdio.h>
#include <stdlib.h>

// Node structure for a circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list
struct Node* createList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; // Pointing to itself initially
    return newNode;
}

// Function to display the elements of a circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

// Function to insert a node at the beginning of a circular linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Pointing to itself
        head = newNode;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }

    printf("Node inserted at the beginning.\n");
    return head;
}

// Function to insert a node at the end of a circular linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Pointing to itself
        head = newNode;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at the end.\n");
    return head;
}

// Function to delete a node from the beginning of a circular linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty. Cannot delete from the beginning.\n");
    } else {
        if (head->next == head) {
            // If there is only one node in the list
            free(head);
            head = NULL;
        } else {
            struct Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            struct Node* temp = head;
            head = head->next;
            last->next = head;
            free(temp);
        }

        printf("Node deleted from the beginning.\n");
    }
    return head;
}

// Function to delete a node from the end of a circular linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty. Cannot delete from the end.\n");
    } else {
        if (head->next == head) {
            // If there is only one node in the list
            free(head);
            head = NULL;
        } else {
            struct Node* last = head;
            struct Node* secondLast = NULL;

            while (last->next != head) {
                secondLast = last;
                last = last->next;
            }

            secondLast->next = head;
            free(last);
        }

        printf("Node deleted from the end.\n");
    }
    return head;
}

// Function to delete a node after a given node of a circular linked list
struct Node* deleteAfterNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("Circular linked list is empty. Cannot delete.\n");
    } else {
        struct Node* current = head;
        do {
            if (current->data == key) {
                // Node with the given key found
                struct Node* temp = current->next;
                current->next = temp->next;
                free(temp);
                printf("Node deleted after the node with key %d.\n", key);
                return head;
            }
            current = current->next;
        } while (current != head);

        // If the key is not found
        printf("Node with key %d not found. Cannot delete.\n", key);
    }
    return head;
}

// Function to delete the entire circular linked list
void deleteList(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is already empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);

    printf("Circular linked list deleted.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to create the circular linked list: ");
                scanf("%d", &value);
                head = createList(value);
                printf("Circular linked list created.\n");
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
