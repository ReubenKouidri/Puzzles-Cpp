
#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
};

struct Node *create_node(int data) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void push_back(struct LinkedList *ll, int data) {
  struct Node *node = create_node(data);
  struct Node *it = ll->head;
  while (it->next != NULL) it = it->next;
  it->next = node;
}

void insert_at(struct LinkedList *ll, int data, int index) {
  struct Node *node = create_node(data);
  struct Node *it = ll->head;
  struct Node *prev = ll->head;

  for (int i = 0; i < index; i++) {
    it = it->next;
    if (i > 0) prev = prev->next;
  }
  prev->next = node;
  node->next = it;
}

void free_node(struct Node *node) {
  free(node);
}

void free_linked_list(struct LinkedList *ll) {
  struct Node *current = ll->head;
  struct Node *next;

  while (current != NULL) {
    next = current->next;
    free_node(current);
    current = next;
  }
  ll->head = NULL;  // reset head pointer to NULL
}

void print_node(struct Node *node) {
  printf("Node(data: %d, next: %p)\n", node->data, node->next);
}

void print_list(struct LinkedList *ll) {
  struct Node *it = ll->head;
  printf("[\n");
  while (it != NULL) {
    printf("\t");
    print_node(it);
    it = it->next;
  }
  printf("]\n");
}

#endif //C_LINKED_LIST_H