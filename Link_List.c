#include <stdio.h>
#include <stdlib.h>

// Structure for Singly and Circular Linked List
struct Node {
    int data;
    struct Node* next;
};

// Structure for Doubly Linked List
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Function to free the singly linked list
void freeSinglyList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free the doubly linked list
void freeDoublyList(struct DNode* head) {
    struct DNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// ------------------- Singly Linked List Functions -------------------
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    struct Node* temp = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void displaySinglyList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ------------------- Doubly Linked List Functions -------------------
void insertAtBeginningD(struct DNode** head, int newData) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;
    
    *head = newNode;
}

void insertAtEndD(struct DNode** head, int newData) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    struct DNode* temp = *head;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void displayDoublyList(struct DNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ------------------- Circular Linked List Functions -------------------
void insertAtEndC(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    struct Node* temp = *head;
    newNode->data = newData;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
}

void displayCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    if (head == NULL) return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

// ------------------- Main Function -------------------
int main() {
    struct Node* singlyHead = NULL;
    struct DNode* doublyHead = NULL;
    struct Node* circularHead = NULL;
    
    int choice, listType, value;

    while (1) {
        printf("\nChoose List Type:\n");
        printf("1. Singly Linked List\n2. Doubly Linked List\n3. Circular Linked List\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &listType);

        if (listType == 4) break;

        while (1) {
            printf("\nOperations:\n");
            printf("1. Insert at Beginning\n2. Insert at End\n3. Display\n4. Back to Main Menu\n");
printf("Enter choice (1-4): ");
while (scanf("%d", &choice) != 1) {
    printf("Invalid input! Please enter a number between 1 and 4: ");
    while(getchar() != '\n'); // clear the input buffer
}


            if (choice == 4) break;

            switch (choice) {
                case 1:
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    if (listType == 1) 
                        insertAtBeginning(&singlyHead, value);
                    else if (listType == 2) 
                        insertAtBeginningD(&doublyHead, value);
                    break;

                case 2:
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    if (listType == 1) 
                        insertAtEnd(&singlyHead, value);
                    else if (listType == 2) 
                        insertAtEndD(&doublyHead, value);
                    else if (listType == 3) 
                        insertAtEndC(&circularHead, value);
                    break;

                case 3:
                    printf("List: ");
                    if (listType == 1) 
                        displaySinglyList(singlyHead);
                    else if (listType == 2) 
                        displayDoublyList(doublyHead);
                    else if (listType == 3) 
                        displayCircularList(circularHead);
                    break;

                default:
                    printf("Invalid choice!\n");
            }
        }
    }
    
    // Free allocated memory
    freeSinglyList(singlyHead);
    freeDoublyList(doublyHead);
    freeSinglyList(circularHead); // Reuse the free function for circular list

    printf("Program exited.\n");
    return 0;
}
