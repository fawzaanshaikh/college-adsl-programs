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

void BinarySearchTree :: insertNode(Node *r, Node *temp) {
    while (1) {
        if (temp -> data < r-> data) {
            if (r -> left == NULL) {
                r -> left = temp;
                break;
            }
            else {
                r = r -> left;
            }
        }
    }
}

// Node *BinarySearchTree :: insertRec(Node *root, int data) {
//     if (root == NULL) {
//         root = create(data);
//     }
// }

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

int main() {

}