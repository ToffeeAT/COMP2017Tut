#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc, free

typedef struct node *node;
struct node {
    int data;
    node prev;
    node next;
};

struct node *list_init(int value) {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        // Failed to allocate memory for the head node
        return NULL;
    } else {
        head->data = value;
        head->next = head;  // Circular list: head points to itself
        head->prev = head;  // Circular list: head points to itself
    }
    return head;
}


void list_add(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node)); // Removed unnecessary free
    if (new_node == NULL) {
        return;
    } else {
        new_node->data = value;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (*head == NULL) {
            *head = new_node;
            (*head)->next = *head;
            (*head)->prev = *head;
        } else {
            struct node *current = *head;
            while (current->next != *head) {
                current = current->next; // Fixed the loop
            }
            current->next = new_node;
            new_node->next = *head;
            new_node->prev = current;
            (*head)->prev = new_node;
        }
    }
}

void list_remove(struct node **head, struct node *n) {
    if (*head == NULL || n == NULL) {
        return;
    } else {
        if (n == *head) {
            if (n->next == n) {
                free(n);
                *head = NULL;
            } else {
                struct node *ptr = n->prev;
                ptr->next = n->next;
                struct node *specx = n->next;
                specx->prev = ptr;
                *head = n->next;
                free(n);
            }
        } else {
            struct node *prevptr = n->prev;
            prevptr->next = n->next;
            struct node *nextptr = n->next;
            nextptr->prev = n->prev;
            free(n);
        }
    }
}

struct node *list_next(const struct node *n) {
    if (n != NULL) {
        return n->next;
    }
    return NULL;
}

struct node *list_prev(const struct node *n) {
    if (n != NULL) {
        return n->prev;
    }
    return NULL;
}

void list_free(struct node **head) {
    if (*head == NULL) {
        return;
    }
    struct node *current = *head;
    struct node *temp;

    do {
        temp = current->next;
        free(current);
        current = temp;
    } while (current != *head);

    *head = NULL;
}

int main() {
    // Test list initialization and addition
    struct node *head = list_init(1);
    list_add(&head, 2);
    list_add(&head, 3);
    
    // Print the list forward
    struct node *current = head;
    printf("List forward: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

    // Print the list backward
    printf("List backward: ");
    current = head->prev;
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("\n");

    // Test list removal
    list_remove(&head, head);
    list_remove(&head, head->prev);
    list_remove(&head, head->next);
    printf("After removals: ");
    if (head != NULL) {
        current = head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    } else {
        printf("Empty list");
    }
    printf("\n");

    // Free the list
    list_free(&head);

    return 0;
}
