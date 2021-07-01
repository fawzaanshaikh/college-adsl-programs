#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
        root -> left = root -> right = NULL;
    }

    Node* createNode(int);
    Node* insertNode(Node*);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
};

Node* BST :: createNode(int num) {
    Node* new_node = new Node;
    new_node -> left = new_node -> right = NULL;
    new_node -> data = num;
    return new_node;
}

Node* BST :: insertNode(Node* temp_node) {
    int num;
    cout << "\nEnter a number: ";
    cin >> num;

    if (root == NULL) {
        root = createNode(num);
    }
    else {
        if (temp_node != NULL) {
            if (num < temp_node -> data) {
                temp_node = insertNode(temp_node -> left);
            }
            else {
                temp_node = insertNode(temp_node -> right);
            }
        }
        else {
            temp_node = createNode(num);
        }

    }
}

void BST :: inorder(Node* temp_node) {
    if (temp_node != NULL) {
        inorder(temp_node -> left);
        cout << temp_node -> data << " ";
        inorder(temp_node -> right);
    }
    else {
        return;
    }
}

void BST :: preorder(Node* temp_node) {
    if (temp_node != NULL) {
        cout << temp_node -> data << " ";
        inorder(temp_node -> left);
        inorder(temp_node -> right);
    }
    else {
        return;
    }
}

void BST :: postorder(Node* temp_node) {
    if (temp_node != NULL) {
        inorder(temp_node -> left);
        inorder(temp_node -> right);
        cout << temp_node -> data << " ";
    }
    else {
        return;
    }
}

int main() {
    cout << "Welcome to the BST generator\n\n";

    char permission = 'y';
    int input;
    BST b_obj;
    
    while (true) {
        cout << "Enter 1 to insert a node, 2 to inorder, 3 to preorder, 4 to postorder and 5 to exit: ";
        cin >> input;

        if (input == 5) {
            break;
        }

        switch (input) {
            case 1:
                b_obj.insertNode(b_obj.root);
                break;
            case 2:
                b_obj.inorder(b_obj.root);
                break;
            case 3:
                b_obj.preorder(b_obj.root);
                break;
            case 4:
                b_obj.postorder(b_obj.root);
                break;
            
            default:
                cout << "\nPlease enter a valid input\n";
        }

        cout << "Would you like to continue (y/n): ";
        cin >> permission;
    }

    cout << "\n\nThank you for using the BST generator";

    return 0;
}