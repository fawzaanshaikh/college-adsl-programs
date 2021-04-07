#include <iostream>

using namespace std;

class Node {
    public: 
        int data;
        Node *left, *right;
};

class BinarySearchTree {
    public:
    Node *root;
    
    BinarySearchTree() {
        root = NULL;
    }

    void create(int);   // Takes data as parameter
    void insertNode(Node *, Node *);    // One for previous node, one for new node
    void inorderTraversal(Node *);
    // void preorderTraversal();
    // void postorderTraversal();
    void display();
    Node *insertRec(Node *, int);
    void mirror(Node *);
    int height(Node *);
    void print(Node *, int);
    void level(Node *);
};

void BinarySearchTree :: create(int data) {
    Node *new_node = new Node;
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;

    if (root == NULL) {
        root = new_node;
    }
    else {
        insertNode(root, new_node);
    }
}

void BinarySearchTree :: insertNode(Node *old_node, Node *new_node) {
    if (old_node = NULL) {
        old_node = new_node;
    }

    if (new_node -> data <= old_node -> data) {
        insertNode(old_node -> left, new_node);
    }
    else {
        insertNode(old_node -> right, new_node);
    }
}

void BinarySearchTree :: inorderTraversal(Node *t) {
    if (t != NULL) {
        inorderTraversal(t -> left);
        cout << t -> data << " ";
        inorderTraversal(t -> right);
    }
}

void BinarySearchTree :: display() {
    Node *temp;
    temp = root;
    inorderTraversal(temp);
}

void BinarySearchTree :: mirror(Node *node) {
    if (node == NULL) {
        return;
    }
    else {
        Node *temp;
        mirror(node -> left);
        mirror(node -> right);
        temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
    }
}

int BinarySearchTree :: height(Node *root) {
    int left_height, right_height;
    
    if (root == NULL) {
        return -1;
    }
    else {
        left_height = height(root -> left);
        right_height = height(root -> right);

        if (left_height > right_height) {
            return (left_height + 1);
        }
        else {
            return (right_height + 1);
        }
    }
}

void BinarySearchTree :: print(Node *root, int level) {
    if (root == NULL) {
        return;
    }
    else if (level == 1) {
        cout << root -> data << " ";
    }
    else if (level > 1) {
        print(root -> left, level - 1);
        print(root -> right, level - 1);
    }
}

void BinarySearchTree :: level(Node *root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        print(root, i);
        cout << root << i << endl;
    }
}

int main() {
    BinarySearchTree bstObj;
    bstObj.create(1);
    bstObj.create(2);
    bstObj.create(3);
    bstObj.create(4);
    bstObj.create(5);
    bstObj.display();
}