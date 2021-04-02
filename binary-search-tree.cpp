// 02/04/2021

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *lc, *rc;
};

class BSTree {
    public:
    Node *root;

    BSTree() {
        root = NULL;
    }

    void create(int);   // Takes data as parameter
    void insertNode(Node *, Node *);    // One for previous node, one for new node
    void inorderTraversal(Node *);
    void display();
};

void BSTree :: create(int data) {
    Node *new_node = new Node;
    new_node -> data = data;
    new_node -> lc = NULL;
    new_node -> rc = NULL;

    if (root == NULL) {
        root = new_node;
    }
    else {
        insertNode(root, new_node);
    }
}

void BSTree :: display() {
    Node *temp;
    temp = root;
    inorderTraversal(temp);
}

void BSTree :: inorderTraversal(Node *t) {
    inorderTraversal(t -> lc);
    cout << t -> data;
    inorderTraversal(t -> rc);
}

int main() {


    return 0;
}