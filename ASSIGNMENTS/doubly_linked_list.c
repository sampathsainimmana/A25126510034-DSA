#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertPage(char page[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->page, page);
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void displayForward() {
    struct Node *temp = head;
    printf("Pages First to Last:\n");
    while (temp != NULL) {
        printf("%s ", temp->page);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
    struct Node *temp = tail;
    printf("Pages Last to First:\n");
    while (temp != NULL) {
        printf("%s ", temp->page);
        temp = temp->prev;
    }
    printf("\n");
}

void deletePage(char page[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->page, page) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Page not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
    printf("Page deleted successfully\n");
}

int main() {
    insertPage("Google");
    insertPage("YouTube");
    insertPage("GitHub");
    insertPage("Wikipedia");

    displayForward();
    displayBackward();

    printf("\nDeleting YouTube...\n");
    deletePage("YouTube");

    displayForward();
    displayBackward();

    return 0;
}

/*
Output:

Pages First to Last:
Google YouTube GitHub Wikipedia
Pages Last to First:
Wikipedia GitHub YouTube Google

Deleting YouTube...
Page deleted successfully
Pages First to Last:
Google GitHub Wikipedia
Pages Last to First:
Wikipedia GitHub Google
*/