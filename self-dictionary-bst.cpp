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
    Node* searchInDictionary();
    void displayInorder(Node*);
    void updateInDictionary();
    Node* minValueNode(Node*);
    Node* deleteNode(Node*, char[]);
    void deleteInDictionary();
};

/* Definitions of member functions of Dictionary class */
// createNode function - creates a new node of the tree
Node* Dictionary :: createNode(char w[], char m[]) {
    struct Node* new_node = new Node;

    for (int i = 0; i < MAX_SIZE; i++) {    // Assigning the char arrays
        new_node -> word[i] = w[i];
        new_node -> meaning[i] = m[i];
    }

    new_node -> right = new_node -> left = NULL;
    return new_node;
}

// insertIntoDictionary function - inserts a new node into the existing tree
void Dictionary :: insertIntoDictionary() {
    char insert_word[MAX_SIZE], insert_meaning[MAX_SIZE];
    cout << "\nEnter the word (max. letter size = 20): ";
    cin >> insert_word;
    cout << "Enter the meaning of the word (max. letter size = 20): ";
    cin >> insert_meaning;

    if (root == NULL)
        root = createNode(insert_word, insert_meaning);
    else {
        struct Node* new_node = createNode(insert_word, insert_meaning);
        struct Node* temp = root;

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
Node* Dictionary :: searchInDictionary() {
    if (root == NULL) 
        cout << "\nThe dictionary is empty.\n";
    else {
        char search_word[MAX_SIZE];
        cout << "\nEnter the word you would like to search: ";
        cin >> search_word;

        struct Node* temp = root;
        while (true) {
            if (temp == NULL) {
                cout << "Could not find the word " << search_word << ".\n";
                return NULL;
            }
            else if (strcmp(search_word, temp -> word) < 0)
                temp = temp -> left;
            else if (strcmp(search_word, temp -> word) > 0)
                temp = temp -> right;
            else {
                cout << "Found " << search_word << "! It's meaning is " << temp -> meaning << ".\n";
                return temp;
            }
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

// updateInDictionary - finds the word specified by the user and updates its meaning
void Dictionary :: updateInDictionary() {
    struct Node* node = searchInDictionary();  // Searches a word and returns its node if it exists
    
    if (node != NULL) {
        cout << "\nEnter the new meaning of the word " << node -> word << ": ";
        cin >> node -> meaning;

        cout << "The meaning of the word " << node -> word << " has been updated to " << node -> meaning << ".\n";
    }
    else
        cout << "\nThe word cannot be updated.\n";
}

// minValueNode - searches the node with the minimum most value from the right subtree of the selected node
Node* Dictionary :: minValueNode(Node* node)
{
    struct Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// deleteNode - deletes the node the same way it is done in a BST
Node* Dictionary :: deleteNode(Node* node, char delete_word[]) {
    if (strcmp(delete_word, node -> word) < 0)
        root -> left = deleteNode(root -> left, delete_word);   // Checking the side where the word comes in the tree
    else if (strcmp(delete_word, node -> word) > 0)
        root -> right = deleteNode(node -> right, delete_word);
    
    else if (strcmp(delete_word, node -> word) == 0) {           // If the word is found    
        // If the node has no children
        if (node -> left == NULL && node -> right == NULL) {
            free(node);
            return NULL;
        }
        // If the node has one child
        else if (node -> left == NULL) {
            struct Node* temp = node -> right;
            free(node);
            return temp; 
        }
        else if (node -> right == NULL) {
            struct Node* temp = node -> left;
            free(node);
            return temp;
        }
        // If the node has both children, then the inorder successor replaces the deleted node
        else {
            struct Node* temp = minValueNode(node -> right);    // root -> right to find the smallest value in the right subtree
            
            for (int i = 0; i < MAX_SIZE; i++) {    // Assigning the char arrays
                node -> word[i] = temp -> word[i];
                node -> meaning[i] = temp -> meaning[i];
            }

            root -> right = deleteNode(node -> right, delete_word); // Delete the inorder successor
        }

        return root;
    }

    else
        return NULL;
}

 
// deleteInDictionary - finds the word and deletes it and its meaning
void Dictionary :: deleteInDictionary() {
    if (root == NULL)
        cout << "\nThe dictionary is empty.\n";
    else {
        struct Node* temp = root;
        char delete_word[MAX_SIZE];
        cout << "\nEnter the word you want to delete: ";
        cin >> delete_word;

        struct Node* check = deleteNode(root, delete_word);
        if (check != NULL)
            cout << "\nThe word was deleted.\n";
        else
            cout << "\nThe word could not be found, hence not deleting\n";
    }

}

int main() {
    Dictionary dObj;
    int user_input;

    cout << "\n\n------ Dictionary Application ------";
    
    while (true) {
        cout << "\n  Enter 1 to enter a word and its meaning\n\t2 to display the dictionary\n\t3 to search a word\n\t4 to update a word\n\t5 to delete a word\n\t6 to exit: ";
        cin >> user_input;

        if (user_input == 6)
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
            case 4:
                dObj.updateInDictionary();
                break;
            case 5:
                dObj.deleteInDictionary();
                break;
            default:
                cout << "\nInvalid Entry";
        }
    }

    cout << "\n------ Thank you ------";

    return 0;
}