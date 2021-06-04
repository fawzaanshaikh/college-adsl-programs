#include <iostream>
#include <string.h>

using namespace std;

/* Definition of Node structure */
struct Node {
    char word[20];
    char meaning[20];
    struct Node* right;
    struct Node* left;
};

/* Definition of Dictionary class */
class Dictionary {

    public:
    // Data members
    struct Node* root;
    const int MAX_SIZE = 20;  // Maximum length of the strings

    // Constructor
    Dictionary() {
        root = NULL;
    }

    // Member functions
    Node* createNode(char[], char[]);
    void insertIntoDictionary();
    void searchInDictionary();
    void displayInorder(Node*);
};

/* Definitions of member functions of Dictionary class */
// createNode function - creates a new node of the tree
Node* Dictionary :: createNode(char w[], char m[]) {
    Node* new_node = new Node;

    for (int i = 0; i < MAX_SIZE; i++) {    // Assigning the char arrays
        new_node -> word[i] = w[i];
        new_node -> meaning[i] = m[i];
    }

    new_node -> right = new_node -> left = NULL;
    return new_node;
}

// insertIntoDictionary function - inserts a new node into the existing tree
void Dictionary :: insertIntoDictionary() {
    char wd[20], mn[20];
    cout << "\nEnter the word (max. letter size = 20): ";
    cin >> wd;
    cout << "Enter the meaning of the word (max. letter size = 20): ";
    cin >> mn;

    if (root == NULL)
        root = createNode(wd, mn);
    else {
        Node* new_node = createNode(wd, mn);
        Node* temp = root;

        while (true) {
            if (strcmp(new_node -> word, temp -> word) < 0) {
                if (temp -> left == NULL) {
                    temp -> left = new_node;
                    break;
                }
                else
                    temp = temp -> left;
            }
            else {
                if (temp -> right == NULL) {
                    temp -> right = new_node;
                    break;
                }
                else
                    temp  = temp -> right;
            }
        }
    }

}

// searchInDictionary - searches for a word in dictionary and displays its meaning
void Dictionary :: searchInDictionary() {
    char wd[20];
    cout << "\nEnter the word you would like to search: ";
    cin >> wd;

    Node* temp = root;
    while (true) {
        if (temp == NULL) {
            cout << "Could not find the word " << wd << ".\n";
            break;
        }
        else if (strcmp(wd, temp -> word) < 0)
            temp = temp -> left;
        else if (strcmp(wd, temp -> word) > 0)
            temp = temp -> right;
        else {
            cout << "Found " << wd << "! It's meaning is " << temp -> meaning << ".\n";
            break;
        }
    }

}

// displayInorder - displays the words and their meanings in lexicographically
void Dictionary :: displayInorder(Node* node) {
    if (node == NULL)
        return;
    else {
        displayInorder(node -> left);
        cout << node -> word << "\t\t\t" << node -> meaning << endl;
        displayInorder(node -> right);
    }
}

int main() {
    Dictionary dObj;
    int user_input;

    cout << "\n\n------ Dictionary Application ------";
    
    while (true) {
        cout << "\nEnter 1 to enter a word and its meaning, 2 to display the dictionary, 3 to search a word 7 to exit: ";
        cin >> user_input;

        if (user_input == 7)
            break;

        switch(user_input) {
            case 1:
                dObj.insertIntoDictionary();
                break;
            case 2:
                cout << "\nWord\t     |\t\tMeaning\n";
                cout << "----------------------------\n";
                dObj.displayInorder(dObj.root);
                break;
            case 3:
                dObj.searchInDictionary();
                break;
            default:
                cout << "\nInvalid Entry";
        }
    }

    cout << "\n------ Thank you ------";

    return 0;
}