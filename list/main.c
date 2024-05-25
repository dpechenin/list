#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* addElement(Node* head, int value, unsigned int position) {
    Node  *new_node, *tmp;
    int i = 0;

    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if(!head) {
        return new_node;
    }

    if(!position) {
        new_node->next = head;
        return new_node;
    }

    tmp = head;
    while(tmp->next && i < position-1) {
        tmp = tmp->next;
        i++;
    }

    if(!tmp->next) {
        tmp->next = new_node;
        return head;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
    return head;
}

void printList(Node *head) {
    if(!head) {
        printf("List is empty!");
    }

    while(head) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* deleteNode(Node *head, unsigned int index) {
    Node *elm = head, *tmp;
    int i = 0;

    if (!head) {
        printf("List is empty");
        return head;
    }

    if(!index) {
        elm = head->next;
        head->next = NULL;//!!!
        free(head);
        return elm;
    }

    while(elm && i < index-1) {
        elm = elm->next;
        i++;
    }

    if(!elm) {
        return head;
    }
    if(!elm->next) {
        return head;
    }

    tmp = elm->next;
    if((elm->next)->next) {
        elm->next = (elm->next)->next;
        tmp->next = NULL;
    }
    else {
        elm->next = NULL;
    }
    free(tmp);
    return head;
}

void deleteList(Node **head) {
    Node *next, *tmp = *head;

    while(tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }

    *head = NULL;

    printf("List was deleted!");
}

int main(void) {
    Node *pMyList = NULL;
    pMyList = addElement(pMyList, 3, 0);
    pMyList = addElement(pMyList, 3, 1);
    pMyList = addElement(pMyList, 5, 2);
    printList(pMyList);
    deleteNode(pMyList, 1);
    printList(pMyList);
    deleteList(&pMyList);
    return 0;
}
