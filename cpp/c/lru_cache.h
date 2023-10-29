
#ifndef CPP_LRU_CACHE_H
#define CPP_LRU_CACHE_H

#include <stdlib.h>
#include <math.h>

struct Pair;

#define KEY_TYPE struct Pair
#define VALUE_TYPE int
#define SIZE_T unsigned int

typedef struct Pair {  // e.g. (n, k)
  VALUE_TYPE first;
  VALUE_TYPE second;
} Pair;

typedef struct ListNode {  // doubly linked
  KEY_TYPE key;
  VALUE_TYPE value;
  struct ListNode *prev;
  struct ListNode *next;
} ListNode;

typedef struct {
  SIZE_T capacity;  // max num elements
  SIZE_T size;
  ListNode *head;
  ListNode *tail;
  ListNode **map;  // hashmap: pointer to pointer i.e. array of pointers
} LRUCache;

ListNode* create_node(KEY_TYPE key, VALUE_TYPE value) {
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));
  node->key = key;
  node->value = value;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

LRUCache* create_cache(SIZE_T capacity) {
  LRUCache *cache = malloc(sizeof(LRUCache));
  cache->capacity = capacity;
  cache->size = 0;
  cache->head = NULL;
  cache->tail = NULL;
  cache->map = (ListNode**)calloc(capacity, sizeof(ListNode*));  // contiguous so can access memory by ptr arrythmetic
  return cache;
}

void free_cache(LRUCache* cache) {
  ListNode *node = cache->head;
  while(node != NULL) {
    ListNode *tmp = node->next;
    free(node);
    node = tmp;
  }
  free(cache->map);
  free(cache);
}

void remove_node(LRUCache* cache, ListNode* node) {
  if (node->prev == NULL) {  // node at head
    node->next->prev = NULL;
    cache->head = node->next;
  } else if (node->next == NULL) {  // node at tail
    node->prev->next = NULL;
    cache->tail = node->prev;
  } else {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  cache->size--;
  free(node);
}

void add_to_front(LRUCache *cache, ListNode *node) {
  node->prev = NULL;  // set prev to NULL
  node->next = cache->head;  // set next to old head; can be NULL
  if (cache->head != NULL) cache->head->prev = node;  // set old head's prev to node
  cache->head = node;  // set new head to node
  if (cache->tail == NULL) cache->tail = node;  // empty cache so head and tail will be the same
  cache->size++;  // increment size
  if (cache->size > cache->capacity) remove_node(cache, cache->tail);  // check size < cap and remove tail
}

SIZE_T hash(KEY_TYPE key, const SIZE_T n, const SIZE_T k, const SIZE_T kmax) {
  return n * kmax + k + 1;
  SIZE_T size = (SIZE_T)(log10(key) + 1);  // how many digits in key
  char numString[size];
  sprintf(numString, "%uz", key);
  printf("f: %c, s: %c", numString[0], numString[1]);
  return
}

void remove_from_cache(LRUCache *cache, KEY_TYPE key) {
  SIZE_T idx = hash(key);
//  SIZE_T idx = key % cache->capacity;  // find index of array
  ListNode *node = cache->map[idx];
  while (node != NULL) {
    if (node->key == key) {
      remove_node(cache, node);
      cache->map[idx] = NULL;
      break;
    }
    node = node->next;
  }
}

#endif //CPP_LRU_CACHE_H