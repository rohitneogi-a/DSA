#include <stdio.h>
#include <stdlib.h>

// Node structure for a single linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a single linked list
struct Node* createList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of a single linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Single linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of a single linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning.\n");
    return head;
}

// Function to insert a node at the end of a single linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        // If the list is empty
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Node inserted at the end.\n");
    return head;
}

// Function to insert a node before a given node of a single linked list
struct Node* insertBeforeNode(struct Node* head, int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        printf("Single linked list is empty. Cannot insert before a given node.\n");
        free(newNode);
        return head;
    }

    if (head->data == key) {
        // If the key matches the first node
        newNode->next = head;
        head = newNode;
        printf("Node inserted before the node with key %d.\n", key);
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        // If the key is not found
        printf("Node with key %d not found. Cannot insert.\n", key);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("Node inserted before the node with key %d.\n", key);
    return head;
}

// Function to insert a node after a given node of a single linked list
struct Node* insertAfterNode(struct Node* head, int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        printf("Single linked list is empty. Cannot insert after a given node.\n");
        free(newNode);
        return head;
    }

    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        // If the key is not found
        printf("Node with key %d not found. Cannot insert.\n", key);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    printf("Node inserted after the node with key %d.\n", key);
    return head;
}

// Function to delete a node from the beginning of a single linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Single linked list is empty. Cannot delete from the beginning.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
    return head;
}

// Function to delete a node from the end of a single linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Single linked list is empty. Cannot delete from the end.\n");
    } else {
        if (head->next == NULL) {
            // If there is only one node in the list
            free(head);
            head = NULL;
        } else {
            struct Node* current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
        }
        printf("Node deleted from the end.\n");
    }
    return head;
}

// Function to delete a node after a given node of a single linked list
struct Node* deleteAfterNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("Single linked list is empty. Cannot delete.\n");
    } else {
        struct Node* current = head;
        while (current != NULL && current->data != key) {
            current = current->next;
        }

        if (current == NULL || current->next == NULL) {
            // If the key is not found or the key is the last node
            printf("Node with key %d not found or there is no node after it. Cannot delete.\n", key);
        } else {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("Node deleted after the node with key %d.\n", key);
        }
    }
    return head;
}

// Function to delete the entire single linked list
void deleteList(struct Node* head) {
    if (head == NULL) {
        printf("Single linked list is already empty.\n");
        return;
    }

    struct Node* current = head;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }

    printf("Single linked list deleted.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, key;

    do {
        printf("\nSingle Linked List Operations:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a given node\n");
        printf("6. Insert after a given node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a given node\n");
        printf("10. Delete the entire single linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to create the single linked list: ");
                scanf("%d", &value);
                head = createList(value);
                printf("Single linked list created.\n");
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
                printf("Enter the key before which to insert: ");
                scanf("%d", &key);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertBeforeNode(head, key, value);
                break;
            case 6:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAfterNode(head, key, value);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the key after which to delete: ");
                scanf("%d", &key);
                head = deleteAfterNode(head, key);
                break;
            case 10:
                deleteList(head);
                head = NULL;
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 11);

    return 0;
}
