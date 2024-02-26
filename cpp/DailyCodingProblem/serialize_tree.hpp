#ifndef CODECHALLENGES_DAILYCODINGPROBLEM_SERIALIZE_TREE_HPP_
#define CODECHALLENGES_DAILYCODINGPROBLEM_SERIALIZE_TREE_HPP_

/* Given the root to a binary tree, implement serialize(root),
 * which serializes the tree into a string,
 * and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class
class Node:
  def __init__(self, val, left=None, right=None):
  self.val = val
  self.left = left
  self.right = right

The following test should pass:
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left' */

#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

struct Node {
  std::string val_{};
  Node* left_{nullptr};
  Node* right_{nullptr};
  constexpr explicit Node(const std::string_view val,
                          Node* left = nullptr,
                          Node* right = nullptr)
      : val_(val), left_(left), right_(right) {}
};

std::string serialize_dfs(Node* const root) {
  if (!root) return "null";

  auto stk = std::stack<Node*>{};
  std::string str;
  stk.push(root);

  while (!stk.empty()) {
    auto* node = stk.top();
    stk.pop();

    if (node) {
      str += node->val_ + ',';
      stk.push(node->right_);
      stk.push(node->left_);
    } else {
      str += "null,";
    }
  }
  return str;
}

std::string serialize_bfs(Node* const root) {
  if (!root) {
    return "null,";
  }

  std::string str;
  auto q = std::queue<Node*>{};
  q.push(root);

  while (!q.empty()) {
    auto* node = q.front();// Correctly access the front of the queue
    q.pop();               // Ensure we pop after accessing the node

    if (node) {
      str += node->val_ + ',';
      // Enqueue children regardless of their nullptr status
      q.push(node->left_);
      q.push(node->right_);
    } else {
      str += "null,";
    }
  }

  return str;
}

Node* deserialize(const std::string& str) {
  if (str == "null") { return new Node("null"); }
  std::stringstream ss{str};
  std::string item;
  getline(ss, item, ',');
  auto* root = new Node(item);
  auto q = std::queue<Node*>{};
  q.push(root);

  while (!q.empty()) {
    auto* node = q.front();
    q.pop();

    if (getline(ss, item, ',')) {
      if (item != "null") {
        node->left_ = new Node(item);
        q.push(node->left_);
      }
    }
    if (getline(ss, item, ',')) {
      if (item != "null") {
        node->right_ = new Node(item);
        q.push(node->right_);
      }
    }
  }
  return root;
};

void printPreOrder(Node* node) {
  if (!node) {
    std::cout << "null,";
    return;
  }
  std::cout << node->val_ << ',';
  printPreOrder(node->left_);
  printPreOrder(node->right_);
}

#endif//CODECHALLENGES_DAILYCODINGPROBLEM_SERIALIZE_TREE_HPP_
