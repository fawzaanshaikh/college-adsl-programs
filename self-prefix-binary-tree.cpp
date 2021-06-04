#include <iostream>

using namespace std;

// Definition of the node of the tree
struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} *root;

// Definition of the node of the stack
struct StackNode
{
    struct TreeNode *node; 
    struct StackNode *next;
} *top;

// Function to create a stack node
StackNode* createStackNode(TreeNode* tree_node)
{
    StackNode* new_node = new StackNode;
    new_node -> node = tree_node;
    new_node -> next = NULL;
}

// Function to push a tree node to the stack
StackNode* push(StackNode* top, TreeNode* node)
{
    if (top == NULL)
        top = createStackNode(node);
    else
    {
        StackNode* temp = createStackNode(node);
        temp -> next = top;
        top = temp;
    }

    return top;
}

// Function to pop a tree node from the stack
TreeNode* pop(StackNode* top)
{
    
    TreeNode* temp_tree_node = NULL;

    if (top == NULL)
        cout << "Stack is empty\n\n";
    else
    {
        StackNode* temp = top;
        top = top -> next;
        temp_tree_node = temp -> node;
        free(temp);
    }

    return temp_tree_node;
}

// Function to create a tree node
TreeNode* createTreeNode(char c)
{
    TreeNode* new_node = new TreeNode;
    new_node -> data = c;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

// Function to build the tree
void buildTree(string s)
{
    StackNode* temp_stack;
    TreeNode* temp_tree;

    if (root == NULL)
        root = temp_tree;

    // Reading the string from the back
    for (int i = s.length() - 1; i >= 0; i--)
    {
        temp_tree = createTreeNode(s[i]);
        if (s[i] >= '0' && s[i] <= '9')
            top = push(top, temp_tree);
        else
        {
            temp_tree -> left = pop(top);
            temp_tree -> right = pop(top);
            
        }
    }


    inorder(root);
}

// Function to display the tree
void inorder(TreeNode* root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

// Driver code
int main()
{
    cout << "\n\n------- Prefix Binary Tree -------\n\n";
    cout << "Enter the prefix expression: ";

    string expression;
    cin >> expression;

    buildTree(expression);

    cout << "\n\n------- Thank you -------\n\n";

    return 0;
}