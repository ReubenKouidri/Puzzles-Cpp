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
  constexpr Node(Node&& temp) noexcept {
    val_ = std::move(temp.val_);
    left_ = std::move(temp.left_);
    right_ = std::move(temp.right_);
    temp.val_.clear();
    temp.left_ = nullptr;
    temp.right_ = nullptr;
  }
};

std::string serialize_bfs(Node* const root) {
  if (!root) {
    return "null,";
  }

  std::string str;
  auto q = std::queue<Node*>{};
  q.push(root);

  while (!q.empty()) {
    auto* node = q.front();
    q.pop();

    if (node) {
      str += node->val_ + ',';
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
}


void print_tree(Node* const node) {
  auto queue = std::queue<Node*>{};
  queue.push(node);

  while (!queue.empty()) {
    auto* n = queue.front();
    queue.pop();
    if (!n) {
      std::cout << "null,";
      continue;
    }
    std::cout << n->val_ << ',';
    queue.push(n->left_);
    queue.push(n->right_);
  }
}

#endif//CODECHALLENGES_DAILYCODINGPROBLEM_SERIALIZE_TREE_HPP_
