#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>

struct Node {
  Node() : payload(-1), left(nullptr), right(nullptr), visited(false) {}
  Node(int p) : payload(p), left(nullptr), right(nullptr), visited(false) {}
  int payload;
  bool visited;
  Node *left;
  Node *right;
};

enum dfs_type { preorder, inorder, postorder };

void dfs(const Node *root, dfs_type type) {
  if (root && root->visited == false) {
    if (type == preorder)
      std::cout << root->payload << std::endl;
    dfs(root->left, type);
    if (type == inorder)
      std::cout << root->payload << std::endl;
    dfs(root->right, type);
    if (type == postorder)
      std::cout << root->payload << std::endl;
  }
}

TEST(TreeTest, One) {
  Node root(3);
  root.left = new Node(1);
  root.right = new Node(4);
  root.left->left = new Node(0);
  root.left->right = new Node(2);

  dfs(&root, inorder);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
