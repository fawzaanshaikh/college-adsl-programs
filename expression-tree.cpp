/* Program to construct an expression treefor a given prefix expressionand perform recursive and non-recursive traversals */

/* ------------------ Remaining :- Code for preorderNonRecursive() function ------------------ */

#include <iostream>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left, *right;
} *root;

class StackNode
{
    public:
        TreeNode *tree_node;
        StackNode *next;

        StackNode(TreeNode *tree_node)
        {
            this -> tree_node = tree_node;
            next = NULL;
        }
};

    class ExpressionTree
    {
        private:
            StackNode *top;
        
        public:
            ExpressionTree()
            {
                top = NULL;
            }

            TreeNode *createNode(char);
            void buildTree(string);
            void insert(char);

            void push(TreeNode *);
            TreeNode* pop();

            void display();
            void inorder(TreeNode *);
            void inorderNonRecursive(TreeNode *);
            void preorder(TreeNode *);
            void preorderNonRecursive(TreeNode *);
            void postorder(TreeNode *);
    };

TreeNode* ExpressionTree :: createNode(char character)
{
    TreeNode *temp_node = new TreeNode;
    temp_node -> right = temp_node -> left = NULL;
    temp_node -> data = character;

    return temp_node;
}

void ExpressionTree :: buildTree(string expression)
{
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        insert(expression[i]);
    }

    root = top -> tree_node;
}

void ExpressionTree :: insert(char ch)
{
    TreeNode *temp_node = new TreeNode;
    temp_node = createNode(ch);

    if (ch >= '0' && ch <= '9')
        push(temp_node);
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        temp_node -> left = pop();
        temp_node -> right = pop();
        push(temp_node);
    }
    else
        cout << "Invalid Expression" << endl;
}

void ExpressionTree :: push(TreeNode *ptr)
{
    if (top == NULL)
        top = new StackNode(ptr);
    else
    {
        StackNode *nptr = new StackNode(ptr);
        nptr -> next = top;
        top = nptr; 
    }
}

TreeNode* ExpressionTree :: pop()
{
    if (top == NULL)
        cout << "Stack Empty" << endl;
    else
    {
        TreeNode *ptr = top -> tree_node;
        top = top -> next;
        return ptr;
    }
}

void ExpressionTree :: inorder(TreeNode *temp_node)
{
    if (temp_node != NULL)
    {
        inorder(temp_node -> left);
        cout << " " << temp_node -> data;
        inorder(temp_node -> right);
    }
}

void ExpressionTree :: inorderNonRecursive(TreeNode *temp_node)
{
    top = NULL;

    while (temp_node != NULL || top != NULL)
    {
        while (temp_node != NULL)
        {
            push(temp_node);
            temp_node = temp_node -> left;
        }
        temp_node = pop();
        cout << " " << temp_node -> data;
        temp_node = temp_node -> right;
    }
}

void ExpressionTree :: preorder(TreeNode *temp_node)
{
    if (temp_node != NULL)
    {
        cout << " " << temp_node -> data;
        preorder(temp_node -> left);
        preorder(temp_node -> right);
    }
}

void ExpressionTree :: postorder(TreeNode *temp_node)
{
    if (temp_node != NULL)
    {
        postorder(temp_node -> left);
        postorder(temp_node -> right);
        cout << " " << temp_node -> data;
    }
}

void ExpressionTree :: display()
{
    cout << "\nInorder : ";
    inorder(root);

    cout << "\nInorder Non-Recursive : ";
    inorderNonRecursive(root);

    cout << "\nPreorder : ";
    preorder(root);

    cout << "\nPreorder Non-Recursive : ";
   // preorderNonRecursive(root);

    cout << "\nPostorder : ";
    postorder(root);
    cout << "\n";
}

int main()
{
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