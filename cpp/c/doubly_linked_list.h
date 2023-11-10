#ifndef C_DOUBLY_LINKED_LIST_H
#define C_DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct Pair {
  int first;
  int second;
} Pair;

Pair* create_pair(int first, int second);
void free_pair(Pair *pair);

typedef struct ListNode {
  Pair* pair;
  struct ListNode *next;
  struct ListNode *prev;
} ListNode;

ListNode* create_node(Pair *pair);
void free_node(ListNode *node);

typedef struct DoublyLinkedList {
  ListNode *head;
  ListNode *tail;
} DoublyLinkedList;

DoublyLinkedList* create_doubly_linked_list();
void free_doubly_linked_list(DoublyLinkedList *list);
void push_front(DoublyLinkedList *list, Pair *pair);
void push_back(DoublyLinkedList *list, Pair *pair);
void delete_head(DoublyLinkedList *list);
void delete_tail(DoublyLinkedList *list);
ListNode* pop_front(DoublyLinkedList *list);
ListNode* pop_back(DoublyLinkedList *list);

#endif //C_DOUBLY_LINKED_LIST_H
