#include <iostream>
#include <string.h>

using namespace std;

class Node {    // Dictionary has a key, meaning and two pointers
    char key[20];
    char meaning[20];
    Node *lc, *rc;
};

class Dictionary {
    Node *root;

    public:
        Dictionary() {
            root = NULL;
        }

        void create();
        void insertNode();
        int searchKeyword(char *);
        void display();
        void display(Node *);
        int update(char *);
        void del(char *);
        Node *del(Node *, char *);
        Node *minimum(Node *);
};

void showMenu() {
    cout << "\nMenu\n1. Create\n2. Display\n3. Search\n4. Update\n5. Delete\n";
    return;
}

int main() {
    char a;
    int ch;
    char x[20];
    Dictionary dict_obj;

    do {
        showMenu();
        cin >> ch;

        switch(ch) {
            case 1: dict_obj.create();  break;
            case 2: 
                cout << "Contents in the dictionary\n";
                dict_obj.display();
                break;
            case 3:
                cout << "Enter the keyword you want to search - ";
                cin >> x;

                if (dict_obj.searchKeyword(x) == 1)
                    cout << "Keyword Found\n";
                else
                    cout << "Keyword Not Found\n";
                break;
            case 4:
                cout << "Enter the keyword whose meaning you want to update - ";
                cin >> x;

                if (dict_obj.update(x) == 1)
                    cout << "Keyword Found\n";
                else
                    cout << "Keyword Not Found\n";
                break;
            case 5:
                cout << "Enter the keyword whose meaning you want to delete - ";
                cin >> x;
                dict_obj.del(x);
                cout << "Updated dictionary is -\n";
                dict_obj.display();
                break;
            default: 
                cout << "Please enter a valid number.\n";
        }

        cout << "Would you like to continue? (y/n) ";
        cin >> a;
    } while (a == 'y');
}