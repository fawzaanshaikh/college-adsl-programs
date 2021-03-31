#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *lc, *rc;
};

class BinaryTree {
    public:
    Node *root;
    
    BinaryTree() {
        root = NULL;
    }

    void create(int);   // Takes data as parameter
    void insertNode(Node *, Node *);    // One for previous node, one for new node
    void inorderTraversal(Node *);
    // void preorderTraversal();
    // void postorderTraversal();
    void display();
};

void BinaryTree :: create(int data) {
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

void BinaryTree :: insertNode(Node *old_node, Node *new_node) {
    char ch;
    cout << "Left or right of " << old_node -> data << "? - ";
    cin >> ch;

    if (ch == 'l') {
        if (old_node -> lc == NULL) 
            old_node -> lc = new_node;
        else
            insertNode(old_node -> lc, new_node);
    }
    else if (ch == 'r') {
        if (old_node -> rc == NULL) 
            old_node -> rc = new_node;
        else
            insertNode(old_node -> rc, new_node);
    }
    else {
        cout << "Enter valid choice\n";
        insertNode(old_node, new_node);
    }
}

void BinaryTree :: inorderTraversal(Node *t) {
    if (t != NULL) {
        inorderTraversal(t -> lc);
        cout << t -> data << " ";
        inorderTraversal(t -> rc);
    }
}

void BinaryTree :: display() {
    Node *temp;
    temp = root;
    inorderTraversal(temp);
}

int main() {
    BinaryTree bt;

    bt.create(10);
    bt.create(20);
    bt.create(30);
    bt.create(40);
    bt.create(50);
    bt.create(60);
    bt.display();
    
    return 0;
}