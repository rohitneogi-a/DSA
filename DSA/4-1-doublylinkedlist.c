#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of the doubly linked list
void display(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }
    printf("Doubly linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning.\n", value);
    return head;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("%d inserted at the end.\n", value);
    return head;
}

// Function to insert a node before a given node in the doubly linked list
struct Node* insertBefore(struct Node* head, int value, int target) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        printf("Doubly linked list is empty. Cannot insert before.\n");
        return head;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found. Cannot insert before.\n", target);
    } else {
        newNode->prev = current->prev;
        newNode->next = current;
        if (current->prev != NULL) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;
        printf("%d inserted before %d.\n", value, target);
    }
    return head;
}

// Function to insert a node after a given node in the doubly linked list
struct Node* insertAfter(struct Node* head, int value, int target) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        printf("Doubly linked list is empty. Cannot insert after.\n");
        return head;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with value %d not found. Cannot insert after.\n", target);
    } else {
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        printf("%d inserted after %d.\n", value, target);
    }
    return head;
}

// Function to delete a node from the beginning of the doubly linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty. Cannot delete from the beginning.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
    return head;
}

// Function to delete a node from the end of the doubly linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty. Cannot delete from the end.\n");
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            head = NULL;
        }
        free(current);
        printf("Node deleted from the end.\n");
    }
    return head;
}

// Function to delete a node after a given node in the doubly linked list
struct Node* deleteAfter(struct Node* head, int target) {
    if (head == NULL) {
        printf("Doubly linked list is empty. Cannot delete after.\n");
    } else {
        struct Node* current = head;
        while (current != NULL && current->data != target) {
            current = current->next;
        }
        if (current == NULL || current->next == NULL) {
            printf("Node with value %d not found or no node after it. Cannot delete after.\n", target);
        } else {
            struct Node* temp = current->next;
            current->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
            free(temp);
            printf("Node deleted after %d.\n", target);
        }
    }
    return head;
}

// Function to delete the entire doubly linked list
void deleteList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("Doubly linked list deleted.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a node\n");
        printf("6. Insert after a node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a node\n");
        printf("10. Delete the entire doubly linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to create the doubly linked list: ");
                scanf("%d", &value);
                head = createNode(value);
                printf("Doubly linked list created.\n");
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
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the target node value before which to insert: ");
                scanf("%d", &target);
                head = insertBefore(head, value, target);
                break;
            case 6:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the target node value after which to insert: ");
                scanf("%d", &target);
                head = insertAfter(head, value, target);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the target node value after which to delete: ");
                scanf("%d", &target);
                head = deleteAfter(head, target);
                break;
            case 10:
                deleteList(head);
                head = NULL;
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice!\n");
        }
    }

    return 0;
}
