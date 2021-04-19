#include <iostream>
#include <string.h>

using namespace std;

struct Node 
{
    int data;
    Node *left, *right;
    bool l_thread, r_thread;
} *root;

class ThreadedBinaryTree 
{
    public:
        Node *head;
        ThreadedBinaryTree() 
        {
            root = NULL;
        }

        Node *getData();
        void createThreadedBinaryTree();
        void insertNode(Node *, Node *);
        void displayThreadedBinaryTree(Node *, Node *);
        void searchInThreaddedBinaryTree(char *);
        void updateInThreaddedBinaryTree(char *);
        void deleteFromThreaddedBinaryTree(Node *, char *);
};

Node *ThreadedBinaryTree :: getData() 
{
    Node *new_node = new Node;
    cout << "Enter a data - ";
    cin >> new_node -> data;

    new_node -> right = new_node -> left = NULL;
    new_node -> l_thread = new_node -> r_thread = true;

    return new_node;
}

void ThreadedBinaryTree :: createThreadedBinaryTree() 
{
    Node *new_node = new Node;
    char user_choice = 'y';

    while (user_choice != 'n')
    {
        new_node = getData();
        if (root == NULL) 
        {
            root = new_node;
            head -> data = -999;
            head -> left = root;
            head -> right = head;
            root -> left = head;
        }
        else 
            insertNode(root, new_node);
        
        cout << "Would you like to continue? (y/n) : ";
        cin >> user_choice;
    }
}

void ThreadedBinaryTree :: insertNode(Node *temp, Node *add) 
{
    if (add -> data < temp -> data) 
    {
        if (temp -> l_thread == true) 
        {
            add -> left = temp -> left;
            add -> right = temp;
            temp -> left = add;
            temp -> l_thread = false;
        }
        else 
        {
            insertNode(temp -> left, add);
        }
    }
    else 
    {
        if (temp -> r_thread == true) 
        {
            add -> right = temp -> right;
            add -> left = temp;
            temp -> right = add;
            temp -> r_thread = false;
        }
        else 
        {
            insertNode(temp -> right, add);
        }
    }
}

void ThreadedBinaryTree :: displayThreadedBinaryTree(Node *temp, Node *head) 
{
    while (temp != head) 
    {
        while (temp -> l_thread == false) 
        {
            temp = temp -> left;
        }
        cout << temp -> data;
        while (temp -> r_thread == true) 
        {
            temp = temp -> right;
            if (temp == head)
                return;
            cout << temp -> data;
        }
    }
}

int main() 
{
    ThreadedBinaryTree dictObj;

    int choice;
    char permission, search_key[20];

    do {
        cout << "\nEnter: 1 to create, 2 to display, 3 to search and 4 to update. \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dictObj.createThreadedBinaryTree();
            break;
        case 2:
           dictObj.displayThreadedBinaryTree(root, dictObj.head);
            break;
            

        default:
            cout << "Please enter a valid number";
            break;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> permission;
    } while (permission == 'y');

    return 0;
}