#include <iostream>
using namespace std;
struct Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree()
    {
        root = NULL;
        root = new Node('A');
        root->left = new Node('B');
        root->right = new Node('C');
        root->left->left = new Node('D');
        root->left->right = new Node('E');
        root->left->right->left = new Node('H');
        root->left->right->right = new Node('I');
        root->right->right = new Node('F');
        root->right->right->left = new Node('J');
        root->right->right->right = new Node('K');
        root->left->right->right->left = new Node('L');
    }

    void print_level_by_level(void)
    {
        int level = 0;
        while (print_given_level(root, level))
        {
            cout << endl;
            level++;
        }
    }

    bool print_given_level(Node *root, int level)
    {
        if (root == NULL)
        {
            return false;
        }
        if (level == 0)
        {
            cout << root->data << " ";
            return true;
        }
        bool left = print_given_level(root->left, level - 1);
        bool right = print_given_level(root->right, level - 1);
        return left || right;
    }

    void print_Leaf_Nodes(Node *root_ptr) // printing Tree leafs Nodes using resursions
    {
        if (root_ptr == NULL)
        {
            return;
        }
        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
            cout << root_ptr->data << " ";
        }
        print_Leaf_Nodes(root_ptr->left);  // recursion
        print_Leaf_Nodes(root_ptr->right); // recursion
    }

    void print_Leaf_Nodes(void) // this is a helper function to call the recursion function with the same name
    {
        print_Leaf_Nodes(this->root);
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int SecondLargestdepth_countingRoot(Node *root_ptr)
    {
        if (root_ptr == NULL)
        {
            return 0;
        }
        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
            return 0;
        }
        int left = SecondLargestdepth_countingRoot(root_ptr->left);
        int right = SecondLargestdepth_countingRoot(root_ptr->right);
        return 1 + max(left, right);
    }

    int SecondLargestdepth_countingRoot()
    {
        return SecondLargestdepth_countingRoot(this->root);
    }

    // not counting the root node in the depth
    int SecondLargestdepth_notcountingRoot(Node *root_ptr) // this is a recursion function
    {
        if (root_ptr == NULL)
        {
            return 0;
        }
        if (root_ptr->left == NULL && root_ptr->right == NULL)
        {
            return 0;
        }
        int left = SecondLargestdepth_notcountingRoot(root_ptr->left);
        int right = SecondLargestdepth_notcountingRoot(root_ptr->right);
        return 1 + max(left, right);
    }

    // helper function that calls recursive function with the same name
    int SecondLargestdepth_notcountingRoot() // not counting the first node in the depth
    {
        return SecondLargestdepth_notcountingRoot(this->root) - 1;
    }
};

/*
creating a tree of following way (using hardcoding), because insert function was not required in the Lab Manual.
A as root
B left of A
C right of A
D left of B
E right of B
F right of C
H left of E
I right of E
J left of F
K right of F
L left of I
-------------------> Tree will look like this <-------------------
A
├── B
│   ├── D
│   └── E
│       ├── H
│       └── I
│           └── L
└── C
    └── F
        ├── J
        └── K
*/

int main(void)
{
    Tree tree;
    cout << "Adding A to L (except for G according to example) in the tree (this was done by hard coding in default constructor)..." << endl;
    cout << "Printing the tree level by level..." << endl;
    tree.print_level_by_level();
    cout << "As you can see, the Tree is Created Correctly, as per the Manual." << endl;
    cout << "Printing the Leaf Nodes of the Tree..." << endl;
    tree.print_Leaf_Nodes();
    cout << endl;
    cout << "Printing the Second Largest Depth of the Tree, including the First Node itself in the count..." << endl;
    cout << "The Second Largest Depth is: " << tree.SecondLargestdepth_countingRoot() << endl;
    cout << "Printing the Second Largest Depth of the Tree, not including the First Node itself in the count..." << endl;
    cout << "The Second Largest Depth is: " << tree.SecondLargestdepth_notcountingRoot() << endl
         << endl;

    system("pause");
    return 0;
}