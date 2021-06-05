#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class BinarySearchTree {
    public:
    struct Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    struct Node* createNode(int);
    void insertNode(int);
    void searchNode(int);
    void countNodes();
    void mirrorBST();
    struct Node* minValueNode(struct Node*);
    struct Node* deleteNode(struct Node*, int);
    void inorderDisplay(struct Node*);
};

struct Node* BinarySearchTree :: createNode(int data) {
    struct Node* new_node = new Node;
    new_node -> data = data;
    new_node -> right = new_node -> left = NULL;
    return new_node;
}

void BinarySearchTree :: insertNode(int data) {
    if (root == NULL)
        root = createNode(data);
    else {
        struct Node* temp = root;

        while (true) {
            if (temp == NULL) {
                temp = createNode(data);
                break;
            }
            else if (data < temp -> data)
                temp = temp -> left;
            else if (data >= temp -> data)
                temp = temp -> right;
        }
    }
}

void BinarySearchTree :: searchNode(int data) {
    if (root == NULL) {
        cout << "The BST is empty.\n";
        return;
    }
    else {
        struct Node* temp = root;

        while (true) {
            if (temp == NULL) {
                cout << "Could not find " << data << endl;
                break;
            }
            else if (data < temp -> data)
                temp = temp -> left;
            else if (data > temp -> data)
                temp = temp -> right;
            else if (data == temp -> data) {
                cout << "Found " << data << "!\n";
                break;
            }            
        }
    }
}

struct Node* BinarySearchTree :: minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct Node* BinarySearchTree :: deleteNode(struct Node* node, int data)
{
    // base case
    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = deleteNode(node->left, data);
    else if (data > node->data)
        node->right = deleteNode(node->right, data);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (node ->left==NULL && node -> right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node); // freeing up the memory
            return temp;
        }
        else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct Node* temp = minValueNode(node->right);
 
        // Copy the inorder successor's content to this node
        node->data = temp->data;
 
        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void BinarySearchTree :: inorderDisplay(struct Node* node) {
    if (node == NULL)
        return;
    else {
        inorderDisplay(node -> left);
        cout << " " << node -> data;
        inorderDisplay(node -> right);
    }
}

// Driver code
int main() {
    return 0;
}