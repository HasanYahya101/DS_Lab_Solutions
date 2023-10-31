#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class BST // Binary Search Tree
{
private:
    Node *root;

    void inorderTraversal(Node *node) // recursive function
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // copy function that uses recursion
    void copy(Node *&newNode, Node *oldNode) // recursive function
    {
        if (oldNode == nullptr)
        {
            newNode = nullptr;
        }
        else
        {
            newNode = new Node;
            newNode->data = oldNode->data;
            copy(newNode->left, oldNode->left);
            copy(newNode->right, oldNode->right);
        }
    }

    int getHeight(Node *node) // using recursion
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void printLevel(Node *node, int level) // using recursion
    {
        if (node == nullptr)
        {
            return;
        }
        if (level == 1)
        {
            cout << node->data << " ";
        }
        else if (level > 1)
        {
            printLevel(node->left, level - 1);
            printLevel(node->right, level - 1);
        }
    }

public:
    BST()
    {
        this->root = nullptr;
    }

    bool insert(int val)
    {
        if (this->root == nullptr)
        {
            this->root = new Node;
            this->root->data = val;
            this->root->left = nullptr;
            this->root->right = nullptr;
            return true;
        }
        else
        {
            Node *temp = this->root;
            while (temp != nullptr)
            {
                if (temp->data == val)
                {
                    return false;
                }
                else if (temp->data > val)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = new Node;
                        temp->left->data = val;
                        temp->left->left = nullptr;
                        temp->left->right = nullptr;
                        return true;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = new Node;
                        temp->right->data = val;
                        temp->right->left = nullptr;
                        temp->right->right = nullptr;
                        return true;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
        return false;
    }

    // copy constructor that uses recursion
    BST(const BST &bst)
    {
        this->root = nullptr;
        copy(this->root, bst.root); // recursion happens in this function
    }

    void inorderPrint()
    {
        inorderTraversal(this->root); // recursion happens in this function
    }

    void levelOrderPrint()
    {
        if (this->root == nullptr)
        {
            return;
        }

        int height = getHeight(this->root);
        for (int i = 1; i <= height; i++)
        {
            printLevel(this->root, i);
            cout << endl;
        }
    }

    int count_Leaf_Nodes(Node *node) // using VLR ie preorder traversal, also using resursion
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return 1; // This is a leaf node
        }

        int leftCount = count_Leaf_Nodes(node->left);
        int rightCount = count_Leaf_Nodes(node->right);

        return leftCount + rightCount;
    }
    int count_Leaf_Nodes()
    {
        return count_Leaf_Nodes(root);
    }

    int count_Nodes(Node *node) // using LVR ie inorder traversal, also using recursion
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftCount = count_Nodes(node->left);
        int rightCount = count_Nodes(node->right);

        return leftCount + rightCount + 1; // Add 1 for the current node
    }

    int count_Nodes()
    {
        return count_Nodes(this->root);
    }

    Node *search(Node *node, int key) // helper function
    {
        if (node == nullptr || node->data == key)
        {
            return node;
        }

        if (key < node->data)
        {
            return search(node->left, key); // recursion
        }
        else
        {
            return search(node->right, key); // recursion
        }
    }

    Node *search(int key)
    {
        return search(this->root, key);
    }

    ~BST() // using post order LRV - Destroying the tree
    {
        if (this->root == nullptr)
        {
            return;
        }

        Node *temp = this->root;
        while (temp != nullptr)
        {
            if (temp->left == nullptr && temp->right == nullptr)
            {
                delete temp;
                temp = nullptr;
            }
            else if (temp->left != nullptr)
            {
                temp = temp->left;
            }
            else if (temp->right != nullptr)
            {
                temp = temp->right;
            }
        }
    }
};

string to_str(bool value)
{
    if (value == true)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

int main()
{
    BST bst1;
    bool returnValue;
    returnValue = bst1.insert(5);
    cout << "Inserting 5: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(3);
    cout << "Inserting 3: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(7);
    cout << "Inserting 7: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(2);
    cout << "Inserting 2: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(4);
    cout << "Inserting 4: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(6);
    cout << "Inserting 6: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(8);
    cout << "Inserting 8: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(1);
    cout << "Inserting 1: " << to_str(returnValue) << endl;
    returnValue = bst1.insert(1);
    cout << "Inserting 1: " << to_str(returnValue) << endl;
    cout << "Inorder traversal: ";
    bst1.inorderPrint();
    cout << endl;
    cout << "Level order traversal (level by level): " << endl;
    bst1.levelOrderPrint();
    cout << "Finding 5: " << bst1.search(5) << " address" << endl;
    if (bst1.search(5) != nullptr)
    {
        cout << "Data of node with key 5: " << bst1.search(5)->data << endl;
    }
    cout << "Finding 3: " << bst1.search(3) << " address" << endl;
    if (bst1.search(3) != nullptr)
    {
        cout << "Data of node with key 3: " << bst1.search(3)->data << endl;
    }
    cout << "Finding 14: " << bst1.search(15) << " - address (0 address means NULL)" << endl;
    if (bst1.search(15) == nullptr)
    {
        cout << "As you can see there is no address, so it is NULL" << endl;
    }
    cout << "Number of nodes in the tree (using LVR): " << bst1.count_Nodes() << endl;
    cout << "Number of leaf nodes in the tree (using VLR): " << bst1.count_Leaf_Nodes() << endl;
    cout << endl;
    cout << "Check the Destructor" << endl;
    cout << endl
         << "As you can see all functions are implimented and working fine" << endl
         << endl;

    system("pause");
    return 0;
}