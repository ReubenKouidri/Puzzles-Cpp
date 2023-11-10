#include "doubly_linked_list.h"

Pair* create_pair(const int first, const int second) {
  Pair *pair = (Pair*)malloc(sizeof(Pair));
  pair->first = first;
  pair->second = second;
  return pair;
}

void free_pair(Pair *pair) { free(pair); }

ListNode* create_node(Pair *pair) {
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->pair = pair;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void free_node(ListNode *node) {
  free_pair(node->pair);
  free(node);
}

DoublyLinkedList* create_doubly_linked_list() {
  DoublyLinkedList *list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void free_doubly_linked_list(DoublyLinkedList *list) {
  ListNode *current = list->head;
  ListNode *tmp;
  while (current != NULL) {
    tmp = current->next;
    free(current);
    current = tmp;
  }
  free(list);
}

void push_front(DoublyLinkedList *list, Pair *pair) {
  ListNode *node = create_node(pair);
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    node->next = list->head;  // old head becomes next
    list->head->prev = node;  // old head's prev set to new head
    list->head = node;  // set the new head of the list
  }
}

void push_back(DoublyLinkedList *list, Pair *pair) {
  ListNode *node = create_node(pair);
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    node->prev = list->tail;  //
    list->tail->next = node;  // extend old tail
    list->tail = node;  // set new tail
  }
}

ListNode* pop_front(DoublyLinkedList *list) {
  ListNode *node = list->head;
  node->next->prev = NULL;
  list->head = node->next;
  return node;
}

ListNode* pop_back(DoublyLinkedList *list) {
  ListNode *node = list->tail;
  node->prev->next = NULL;
  list->tail = node->prev;
  return node;
}

void delete_head(DoublyLinkedList *list) {
  ListNode *node = list->head;
  node->next->prev = NULL;
  list->head = node->next;
  free(node);
}

void delete_tail(DoublyLinkedList *list) {
  ListNode *node = list->tail;
  node->prev->next = NULL;
  list->tail = node->prev;
  free(node);
}
