#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    char key[20];
    char meaning[20];
    Node *left, *right;
} *root;

class Dictionary {
    public:
        Dictionary() {
            root = NULL;
        }

        Node *getData();
        void createDictionary();
        void insertNode(Node *);
        void displayDictionary();
};

Node *Dictionary :: getData() {
    Node *new_node = new Node;
    cout << "Enter a key value - ";
    cin >> new_node -> key;

    cout << "Enter its meaning";
    cin >> new_node -> meaning;

    new_node -> right = NULL;
    new_node -> left = NULL;

    return new_node;
}

void Dictionary :: createDictionary() {
    Node *new_node = new Node;
    new_node = getData();

    if (root == NULL)
        root = new_node;
    else 
        insertNode(new_node);
}

void Dictionary :: insertNode(Node *new_node) {
    Node *temp = new Node;
    temp = root;
    
    while (1) {
        if (strcmp(new_node -> key, temp -> key) < 0) {
            if (temp -> left == NULL){
                temp -> left = new_node;
                break;
            }
            else
                temp = temp -> left;
        }
        else {
            if (temp -> right == NULL){
                temp -> right = new_node;
                break;
            }
            else
                temp = temp -> right;
        }
    }
}

void Dictionary :: displayDictionary() {

}

int main() {
    Dictionary dictObj;

    int choice;
    char permission;

    do {
        cout << "Enter 1 to create the dictionary and 2 to display the dictionary\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dictObj.createDictionary();
            break;
        case 2:
            dictObj.displayDictionary();
            break;

        default:
            cout << "Please enter a valid number";
            break;
        }
    } while (permission == 'y');

    return 0;
}