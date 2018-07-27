#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

typedef struct list {
    Node* head;
}CircularLinkedList;

Node* createNode(int);
CircularLinkedList* initList();
void insertFront(CircularLinkedList*, int);
void insertBack(CircularLinkedList*, int);
void deleteFront(CircularLinkedList*);
void deleteBack(CircularLinkedList*);
void display(CircularLinkedList*);
int countElem(CircularLinkedList*);

int main() {
    CircularLinkedList* list = initList();
    int count = countElem(list);
    printf("COUNT:%d\n", count);
    insertFront(list, 5);
    insertFront(list, 6);
    insertFront(list, 7);
    count = countElem(list);
    printf("COUNT:%d\n", count);
    display(list);
    insertFront(list, 8);
    insertFront(list, 9);
    insertBack(list, 10);
    insertBack(list, 11);
    count = countElem(list);
    printf("COUNT:%d\n", count);
    printf("___________________\n");
    display(list);
    deleteFront(list);
    deleteBack(list);
    deleteFront(list);
    deleteBack(list);
    deleteFront(list);
    deleteBack(list);
    deleteFront(list);
    count = countElem(list);
    printf("COUNT:%d\n", count);
    display(list);
    if (count == 0) free(list);
    return 0;
}

//create one node
Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate!!!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//init list
CircularLinkedList* initList() {
    CircularLinkedList* list = malloc(sizeof(CircularLinkedList));
    if (list == NULL) {
        printf("Failed to allocate\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insertFront(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    //if list is empty
    if (list->head == NULL) {
      list->head = newNode;
      newNode->next = list->head;
    } else {
        Node* temp = list->head;
        while (temp->next != list->head) { temp = temp->next; }
        newNode->next = list->head;
        list->head = newNode;
        temp->next = list->head;
    }
    printf("Inserted\n");
}

void insertBack(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = list->head;
    } else {
        Node* temp = list->head;
        while (temp->next != list->head) { temp = temp->next; }
        temp->next = newNode;
        newNode->next = list->head;
    }
    printf("Inserted Back\n");
}

void deleteFront(CircularLinkedList* list) {
   if (list->head == NULL) {
      printf("List is empty\n");
      return;
   }else {
      Node* curr = list->head;
      //if we have one element
      if (curr->next == list->head) {
        list->head = NULL;
        curr->next = NULL;
        free(curr);
      }else {
        Node* nextNode = list->head;
        while (curr->next != list->head) { curr = curr->next; }
        list->head = nextNode->next;
        curr->next = list->head;
        nextNode->next = NULL;
        free(nextNode);
      }
   }
   printf("Deleted\n");
}

void deleteBack(CircularLinkedList* list) {
   if (list->head == NULL) {
       printf("List is empty\n");
       return;
   }else {
     Node* curr = list->head;
     //if we have one element
     if (curr->next == list->head) {
        list->head = NULL;
        curr->next = NULL;
        free(curr);
     } else {
        Node* prev = NULL;
        //more than one element
        while (curr->next != list->head) {
            prev = curr;
            curr = curr->next;
        }
        if (prev != NULL) prev->next = list->head;

        curr->next = NULL;
        free(curr);
     }
   }
   printf("Deleted\n");
}

void display(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        Node* curr = list->head;
        while (curr->next != list->head) {
            printf("CircularLinkedList-{%d}\n", curr->data);
            curr = curr->next;
        }
        printf("CircularLinkedList-{%d}\n", curr->data);
    }

}

int countElem(CircularLinkedList* list) {
    if (list->head == NULL) return -1;
    Node* curr = list->head;
    int count = 0;
    while (curr->next != list->head) {
        ++count;
        curr = curr->next;
    }
    ++count;
    return count;
}

