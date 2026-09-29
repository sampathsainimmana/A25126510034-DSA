#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

void create(int r) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    n->roll = r;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        struct Node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void insertBeg(int r) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    n->roll = r;
    n->next = head;
    head = n;
}

void insertEnd(int r) {
    create(r);
}

void search(int r) {
    struct Node *t = head;

    while (t != NULL) {
        if (t->roll == r) {
            printf("Roll number found\n");
            return;
        }
        t = t->next;
    }

    printf("Roll number not found\n");
}

void deleteNode(int r) {
    struct Node *t = head;
    struct Node *prev = NULL;

    while (t != NULL && t->roll != r) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Roll number not found\n");
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    free(t);
    printf("Roll number deleted\n");
}

void display(void) {
    struct Node *t = head;

    printf("List: ");
    while (t != NULL) {
        printf("%d -> ", t->roll);
        t = t->next;
    }
    printf("NULL\n");
}

int main(void) {
    create(101);
    create(102);
    create(103);
    display();

    insertBeg(100);
    display();

    insertEnd(104);
    display();

    search(102);
    search(999);

    deleteNode(102);
    display();

    deleteNode(999);
    display();

    return 0;
}

/*
OUTPUT:
List: 101 -> 102 -> 103 -> NULL
List: 100 -> 101 -> 102 -> 103 -> NULL
List: 100 -> 101 -> 102 -> 103 -> 104 -> NULL
Roll number found
Roll number not found
Roll number deleted
List: 100 -> 101 -> 103 -> 104 -> NULL
Roll number not found
List: 100 -> 101 -> 103 -> 104 -> NULL
*/