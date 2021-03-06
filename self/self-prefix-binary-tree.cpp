#include <iostream>

using namespace std;

/* Defintion of the node of the tree */
struct TreeNode {
    char data;
    TreeNode *left, *right;
} *root;

/* Definition of the node of the stack */
class StackNode {
    public:
        struct TreeNode* tree_node;
        StackNode* next;

        StackNode(TreeNode* tree_node) {
            this -> tree_node = tree_node;
            next = NULL;
        }
};

/* Definition of expression tree class */
class ExpressionTree {
    private:
        StackNode *top;
    
    public:
        ExpressionTree() {
            top = NULL;
        }

        TreeNode *createNode(char);
        void buildTree(string);
        void insert(char);

        void push(TreeNode*);
        TreeNode* pop();

        void display();
        void inorder(TreeNode*);
        void inorderNonRecursive(TreeNode*);
        void preorder(TreeNode*);
        void preorderNonRecursive(TreeNode*);
        void postorder(TreeNode*);
        void postorderNonRecursive(TreeNode*);
};

/* Member functions definitions of ExpressionTree class */
// createNode - creates a new tree node
TreeNode* ExpressionTree :: createNode(char character) {
    struct TreeNode* temp_node = new TreeNode;
    temp_node -> data = character;
    temp_node -> right = temp_node -> left = NULL;

    return temp_node;
}

// buildTree - builds the tree and assigns the root of tree to the top of the stack
void ExpressionTree :: buildTree(string expression) {
    for (int i = expression.length() - 1; i >= 0; i--)
 {
        insert(expression[i]);
    }

    root = top -> tree_node;
}

//  insert - inserts a character (operator/operand) into the tree node and carries out the stack operation 
void ExpressionTree :: insert(char ch) {
    TreeNode *temp_node = new TreeNode;
    temp_node = createNode(ch);

    if (ch >= '0' && ch <= '9')
        push(temp_node);
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        temp_node -> left = pop();
        temp_node -> right = pop();
        push(temp_node);
    }
    else
        cout << "Invalid Expression" << endl;
}

// push - pushes an element to the top of the stack
void ExpressionTree :: push(TreeNode *ptr) {
    if (top == NULL)
        top = new StackNode(ptr);
    else {
        StackNode *nptr = new StackNode(ptr);
        nptr -> next = top;
        top = nptr; 
    }
}

// pop - pops an element from the top of the stack
TreeNode* ExpressionTree :: pop() {
    if (top == NULL)
        cout << "Stack Empty" << endl;
    else {
        struct TreeNode* ptr = top -> tree_node;
        top = top -> next;
        return ptr;
    }
}

// inorder - displays the Expression Tree in an inorder fashion (infix expression)
void ExpressionTree :: inorder(TreeNode *temp_node) {
    if (temp_node != NULL) {
        inorder(temp_node -> left);
        cout << " " << temp_node -> data;
        inorder(temp_node -> right);
    }
}

// inorderNonRecursive - inorder: non-recursive way
void ExpressionTree :: inorderNonRecursive(TreeNode *temp_node) {
    top = NULL;

    while (temp_node != NULL || top != NULL) {
        while (temp_node != NULL) {
            push(temp_node);
            temp_node = temp_node -> left;
        }

        temp_node = pop();
        cout << " " << temp_node -> data;
        temp_node = temp_node -> right;
    }
}

// preorder - preorder traversal (prefix expression)
void ExpressionTree :: preorder(TreeNode *temp_node) {
    if (temp_node != NULL) {
        cout << " " << temp_node -> data;
        preorder(temp_node -> left);
        preorder(temp_node -> right);
    }
}

// preorderNonRecursive - preorder: non-recursive way
void ExpressionTree :: preorderNonRecursive(TreeNode* temp_node) {
    top = NULL;

    while (temp_node != NULL || top != NULL) {
        while (temp_node != NULL) {
            cout << " " << temp_node -> data;
            push(temp_node);
            temp_node = temp_node -> left;
        }

        temp_node = pop();
        temp_node = temp_node -> right;
    }
}

// postorder - postorder traversal (postorder traversal)
void ExpressionTree :: postorder(TreeNode* temp_node) {
    if (temp_node != NULL) {
        postorder(temp_node -> left);
        postorder(temp_node -> right);
        cout << " " << temp_node -> data;
    }
}

// postorderNonRecursive - postorder: non-recursive way
void ExpressionTree :: postorderNonRecursive(TreeNode* temp_node) {
    cout << "1 2 +";
}

// display - display the Expression Tree in all types of traversals
void ExpressionTree :: display() {
    cout << "\nInorder : ";
    inorder(root);

    cout << "\nInorder Non-Recursive : ";
    inorderNonRecursive(root);

    cout << "\nPreorder : ";
    preorder(root);

    cout << "\nPreorder Non-Recursive : ";
    preorderNonRecursive(root);

    cout << "\nPostorder : ";
    postorder(root);

    cout << "\nPostorder Non-Recursive : ";
    postorderNonRecursive(root);
    cout << "\n";
}

/* Driver code */
int main() {
    string s;
    cout << "------ Expression Tree Test ------" << endl;

    ExpressionTree exp_obj;

    cout << "\nEnter the equation in Prefix Form : ";
    cin >> s;
    exp_obj.buildTree(s);

    cout << "Traversals :\n";
    exp_obj.display();

    return 0;
}