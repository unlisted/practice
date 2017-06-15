#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <queue>

struct Node {
  Node() : payload(-1), left(nullptr), right(nullptr), visited(false) {}
  Node(int p) : payload(p), left(nullptr), right(nullptr), visited(false) {}
  int payload;
  bool visited;
  Node *left;
  Node *right;
};

void bfs( Node *root) {
    // Q to store nodes to visit
    std::queue< Node*> q;

    q.push(root);
    root->visited = true;

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();

        std::cout << current->payload << std::endl;;


        if (current->left && !current->left->visited) {
            q.push(current->left);
            current->left->visited = true;
        }

        if (current->right && !current->right->visited) {
            q.push(current->right);
            current->right->visited = true;
        }
        
    }

}

TEST(TreeTest, One) {
  Node root(0);
  root.left = new Node(1);
  root.right = new Node(2);
  root.left->left = new Node(3);
  root.left->right = new Node(4);
  root.right->left = new Node(5);
  root.right->right = new Node(6);

  bfs(&root);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

