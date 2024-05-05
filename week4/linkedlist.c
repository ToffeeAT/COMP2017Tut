#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * list_init(int value) {
    struct node * head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        free(head);
    } else {
        head->data = value;
        head->next = NULL;
    }
    return head;
}

void list_add(struct node ** head, int value) {
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        free(head);
    } else {
        new_node->data = value;
        new_node->next = head;
        if (*head == NULL) {
            *head = new_node;
        } else {
            struct node *current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
}

void list_remove(struct node ** head, struct node * n) {
    if (*head == NULL) {
        return;
    }
    if (*head == n) {
        *head = n->next;
        free(n);
        return;
    }

    struct node * current = *head;
    while (current->next != NULL && current->next!= n) {
        current = current->next;
    }
    if (current->next == n) {
        current->next = n->next;
        free(n);
    }
}

struct node* list_next(const struct node * n) {
    if (n != NULL) {
        return n->next;
    }
    return NULL;
}

void list_free(struct node ** head) {
    struct node * current = *head;
    struct node * next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
