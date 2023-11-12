#include <iostream>
using namespace std;

class AVLNode
{
public:
    int key;
    int height;
    int count; // for handling duplicates
    AVLNode *left;
    AVLNode *right;

    AVLNode(int k)
    {
        key = k;
        height = 1;
        count = 1;
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
    class iterator
    {
    private:
        AVLNode *current;
        AVLNode *root;

    public:
        iterator(AVLNode *root)
        {
            this->root = root;
            current = root;
        }

        bool hasNext()
        {
            return current != nullptr;
        }

        int next()
        {
            if (current == nullptr)
            {
                return INT_MIN;
            }

            if (current->left == nullptr)
            {
                int key = current->key;
                current = current->right;
                return key;
            }
            else
            {
                AVLNode *pre = current->left;
                while (pre->right != nullptr && pre->right != current)
                {
                    pre = pre->right;
                }

                if (pre->right == nullptr)
                {
                    pre->right = current;
                    int key = current->key;
                    current = current->left;
                    return key;
                }
                else
                {
                    pre->right = nullptr;
                    int key = current->key;
                    current = current->right;
                    return key;
                }
            }
        }

        void itprint()
        {
            while (hasNext())
            {
                std::cout << next() << " ";
            }
            std::cout << endl;
        }
    };

private:
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
            node->count++; // Increment count for duplicate value
            return node;
        }

        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balanceFactor > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void updateHeight(AVLNode *node)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Recursive function to find the minimum node
    AVLNode *findmin(AVLNode *node)
    {
        if (node == nullptr || node->left == nullptr)
        {
            return node;
        }
        return findmin(node->left);
    }

    // Recursive function to find the node with the n-th minimum value
    AVLNode *findNthMin(AVLNode *node, int &n)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        AVLNode *left = findNthMin(node->left, n);
        if (left != nullptr)
        {
            return left;
        }

        if (--n <= 0)
        {
            return node;
        }

        AVLNode *right = findNthMin(node->right, n);
        return right;
    }

    // Helper for finding the nth minimum node (public function)
    AVLNode *findNthMinHelper(int n)
    {
        return findNthMin(root, n);
    }

public:
    AVLTree()
    {
        root = nullptr;
        size = 0;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    bool isAVL()
    {
        int balanceFactor = getBalanceFactor(root);
        return abs(balanceFactor) <= 1;
    }

    int findmin()
    {
        AVLNode *node = findmin(root);
        return (node == nullptr) ? INT_MIN : node->key;
    }

    int find2ndmin()
    {
        int n = 2; // looking for the 2nd min element
        AVLNode *node = findNthMinHelper(n);
        return (node == nullptr) ? INT_MIN : node->key;
    }

    int find3rdmin()
    {
        int n = 3; // looking for the 3rd min element
        AVLNode *node = findNthMinHelper(n);
        return (node == nullptr) ? INT_MIN : node->key;
    }

    void itprint_with_dup()
    {
        AVLNode *current = root;
        while (current != nullptr)
        {
            if (current->left == nullptr)
            {
                int key = current->key;
                int count = current->count;
                while (count > 0)
                {
                    std::cout << key << " ";
                    count--;
                }
                current = current->right;
            }
            else
            {
                AVLNode *pre = current->left;
                while (pre->right != nullptr && pre->right != current)
                {
                    pre = pre->right;
                }

                if (pre->right == nullptr)
                {
                    pre->right = current;
                    int key = current->key;
                    int count = current->count;
                    while (count > 0)
                    {
                        std::cout << key << " ";
                        count--;
                    }
                    current = current->left;
                }
                else
                {
                    pre->right = nullptr;
                    current = current->right;
                }
            }
        }
        std::cout << std::endl;
    }

    void itprint_without_dup()
    {
        AVLNode *current = root;
        while (current != nullptr)
        {
            if (current->left == nullptr)
            {
                int key = current->key;
                cout << key << " ";
                current = current->right;
            }
            else
            {
                AVLNode *pre = current->left;
                while (pre->right != nullptr && pre->right != current)
                {
                    pre = pre->right;
                }

                if (pre->right == nullptr)
                {
                    pre->right = current;
                    int key = current->key;
                    cout << key << " ";
                    current = current->left;
                }
                else
                {
                    pre->right = nullptr;
                    current = current->right;
                }
            }
        }
        std::cout << std::endl;
    }

    int getHeight(AVLNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    // get root
    AVLNode *getRoot()
    {
        return root;
    }

    int getBalanceFactor(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    ~AVLTree()
    {
        delete root;
    }
};

int main()
{
    AVLTree avl;

    // Insert elements into the AVL tree
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(30); // duplicate
    avl.insert(40);
    avl.insert(40); // duplicate
    avl.insert(50);
    avl.insert(25);

    // Print preorder traversal
    cout << "Preorder (with duplicates): ";
    avl.itprint_with_dup();
    cout << "Preorder (without duplicates): ";
    avl.itprint_without_dup();

    // Check if tree is AVL
    cout << "Is AVL: " << (avl.isAVL() ? "Yes" : "No") << endl;

    // Find minimum values
    cout << "Minimum: " << avl.findmin() << endl;
    cout << "2nd Minimum: " << avl.find2ndmin() << endl;
    cout << "3rd Minimum: " << avl.find3rdmin() << endl; // all 3 min functions use single recursive function

    system("pause");
    return 0;
}
