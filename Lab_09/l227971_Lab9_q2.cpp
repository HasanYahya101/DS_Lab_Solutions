#include <iostream>
using namespace std;

class AVLNode
{
public:
    int key;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(int k)
    {
        key = k;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVLTree
{
private:
    AVLNode *root;
    int size;

public:
    AVLTree()
    {
        root = nullptr;
        size = 0;
    }

    int getHeight(AVLNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(AVLNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode *leftRotate(AVLNode *node)
    {
        AVLNode *left = node->left;
        AVLNode *leftRight = left->right;

        left->right = node;
        node->left = leftRight;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        left->height = 1 + max(getHeight(left->left), getHeight(left->right));

        return left;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    AVLNode *insert(AVLNode *node, int key)
    {
        if (node == nullptr)
        {
            size++;
            return new AVLNode(key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
        {
            return leftRotate(node);
        }

        return node;
    }

    /*AVLNode *insert(AVLNode *node, int key)// this ones uses both right and left, but the above one uses only left, this one is commented out
    {
        if (node == nullptr)
        {
            size++;
            return new AVLNode(key);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }*/

    void Inorder_Print(AVLNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        Inorder_Print(node->left);
        cout << node->key << " ";
        Inorder_Print(node->right);
    }

    void Inorder_Print()
    {
        Inorder_Print(root);
    }

    void Preorder_Print(AVLNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->key << " ";
        Preorder_Print(node->left);
        Preorder_Print(node->right);
    }

    void Preorder_Print()
    {
        Preorder_Print(root);
    }

    void Postorder_Print(AVLNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        Postorder_Print(node->left);
        Postorder_Print(node->right);
        cout << node->key << " ";
    }

    void Postorder_Print()
    {
        Postorder_Print(root);
    }

    void print()
    {
        cout << "Printing: ";
        Preorder_Print();
        cout << endl;
    }

    ~AVLTree()
    {
        delete root;
    }
};

int main()
{
    AVLTree tree;

    cout << "Input: 20, 15, 10, 5, 3, 25 " << endl;

    tree.insert(20);
    tree.insert(15);
    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(25);

    tree.print();

    system("pause");
    return 0;
}
