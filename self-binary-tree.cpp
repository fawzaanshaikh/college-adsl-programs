#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
} *root;

Node* createNode(int value)
{
    Node *new_node = new Node;
    new_node -> data = value;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

Node* insertIntoBT(Node* root, int value)
{
    if (root == NULL)
        root = createNode(value);
    else
    {
        cout << "Enter the node to the right or the left of node " << root -> data << " (r/l): ";
        char direction;
        cin >> direction;

        if (direction == 'r')
            root -> right = insertIntoBT(root -> right, value);
        else if (direction == 'l')
            root -> left = insertIntoBT(root -> left, value);
        else
            cout << "Invalid entry\n";
    }

    return root;
}

void inorderTraversal(Node* root)
{
    if (root == NULL)
        return;
    else
    {
        inorderTraversal(root -> left);
        cout << root -> data << " ";
        inorderTraversal(root -> right);
    }
}

int main()
{
    cout << "\n\n------ Binary Tree Creator ------ \n\n";

    int choice = -1;
    while (true)
    {
        cout << "\nEnter 1 to insert a node into the binary tree, 2 to delete a node, 3 to search a node, 4 to display (inorder), 5 to exit: ";
        cin >> choice;

        if (choice == 5)
            break;
        
        switch (choice)
        {
            case 1:
                cout << "\nEnter the data to be input into the binary tree: ";
                int input;
                cin >> input;
                root = insertIntoBT(root, input);
                break;
            case 4:
                inorderTraversal(root);
                break;
            default:
                cout << "Invalid entry\n";
        }
    }

    cout << "\n\n------ Thank you for using the application ------ \n\n";

    return 0;
}