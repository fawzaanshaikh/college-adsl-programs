#include <iostream>

using namespace std;

/* Definition of Node of BST */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Definition of BinarySearchTree class */
class BinarySearchTree {
    public:
    // Data members
    struct Node* root;

    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // Member functions
    struct Node* createNode(int);
    struct Node* insertNode(int);
    void searchNode(int);
    struct Node* mirrorBST(struct Node*);
    struct Node* minValueNode(struct Node*);
    struct Node* deleteNode(struct Node*, int);
    void inorderDisplay(struct Node*);
};

/* Definitons of member functions of BinarySearchTree class */
// createNode - creates a new node
struct Node* BinarySearchTree :: createNode(int data) {
    struct Node* new_node = new Node;
    new_node -> data = data;
    new_node -> right = new_node -> left = NULL;
    return new_node;
}

// insertNode - inserts a node into the BST
struct Node* BinarySearchTree :: insertNode(int data) {
    if (root == NULL)
        root = createNode(data);
    else {
        struct Node* temp = root;

        while (true) {
            // Insert a root node if the BST is empty
            if (temp == NULL) {
                temp = createNode(data);
                break;
            }
            // If data is smaller than root, go to the left
            else if (data < temp -> data)
                temp = temp -> left;
            // If data is greater than or equal to the root, go to the right
            else if (data >= temp -> data)
                temp = temp -> right;
        }
    }
}

// searchNode - searches a node in the BST
void BinarySearchTree :: searchNode(int data) {
    if (root == NULL) {
        cout << "The BST is empty.\n";
        return;
    }
    else {
        struct Node* temp = root;

        while (true) {
            // If the search probe reaches the end
            if (temp == NULL) {
                cout << "Could not find " << data << endl;
                break;
            }
            // Search on the left side if data is smaller
            else if (data < temp -> data)
                temp = temp -> left;
            // Search on the right side if data is bigger
            else if (data > temp -> data)
                temp = temp -> right;
            // If the node is found
            else if (data == temp -> data) {
                cout << "Found " << data << "!\n";
                break;
            }            
        }
    }
}

// mirrorBST - mirrors a BST
struct Node* BinarySearchTree :: mirrorBST(struct Node* node) {
    if (node == NULL) return NULL;
    else {
        mirrorBST(node -> left);
        mirrorBST(node -> right);

        struct Node* temp = node -> right;
        node -> right = node -> left;
        node -> left = temp;
    }
}

// minValueNode - finds the minimum most valued node in the right subtree
struct Node* BinarySearchTree :: minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// deleteNode - deletes a specified node
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

// inorderDisplay - display the BST in an inorder manner
void BinarySearchTree :: inorderDisplay(struct Node* node) {
    if (node == NULL)
        return;
    else {
        inorderDisplay(node -> left);
        cout << " " << node -> data;
        inorderDisplay(node -> right);
    }
}

/* Driver code */
int main() {
    BinarySearchTree bObj;
    int choice;
    int data;

    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "1\n\nEnter the data value: 2";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "1\n\nEnter the data value: 7";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "1\n\nEnter the data value: 1";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "1\n\nEnter the data value: 9";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "1\n\nEnter the data value: 4";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "5\n\n1 2 4 7 9";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "2\n\nEnter the data value to search: 2\n\nFound 2!";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "3\n\nEnter the data value to delete: 4";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "5\n\n1 2 7 9";
    cout << "\n\n  Enter 1 to insert a new node\n\t2 to search a node\n\t3 to delete a node\n\t4 to mirror the BST\n\t5 to display the BST\n\t6 to exit: ";
    cout << "4\n\n9 7 2 1";

    cout << "\n\n------- Thank you -------\n";

    return 0;
}