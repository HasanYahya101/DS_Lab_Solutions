#include <iostream>
using namespace std;

template <typename dataType>

class Node
{
public:
    dataType data;
    Node<dataType> *right;
    Node<dataType> *left;
};

template <typename dataType>

class AVL_BST
{
private:
    Node<dataType> *root;

public:
    AVL_BST()
    {
        root = NULL;
    }

    void insert(dataType data)
    {
        Node<dataType> *newNode = new Node<dataType>;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node<dataType> *temp = root;
            while (temp != NULL)
            {
                if (data < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newNode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    void inorder(Node<dataType> *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    void preorder(Node<dataType> *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void postorder(Node<dataType> *temp)
    {
        if (temp != NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

    void display()
    {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    int height(Node<dataType> *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            int leftHeight = height(temp->left);
            int rightHeight = height(temp->right);

            if (leftHeight > rightHeight)
            {
                return leftHeight + 1;
            }
            else
            {
                return rightHeight + 1;
            }
        }
    }

    void Balance_Tree() // convert to balanced tree using AVL
    {
        Node<dataType> *temp = root;
        if (balanceFactor(temp) > 1)
        {
            if (balanceFactor(temp->left) > 0)
            {
                // left left case
                rightRotate(temp);
            }
            else
            {
                // left right case
                leftRotate(temp->left);
                rightRotate(temp);
            }
        }
        else if (balanceFactor(temp) < -1)
        {
            if (balanceFactor(temp->right) < 0)
            {
                // right right case
                leftRotate(temp);
            }
            else
            {
                // right left case
                rightRotate(temp->right);
                leftRotate(temp);
            }
        }
    }

    void leftRotate(Node<dataType> *temp)
    {
        Node<dataType> *newNode = new Node<dataType>;
        newNode->data = temp->data;
        newNode->left = temp->left;
        newNode->right = temp->right->left;

        temp->data = temp->right->data;
        temp->right = temp->right->right;
        temp->left = newNode;
    }

    void rightRotate(Node<dataType> *temp)
    {
        Node<dataType> *newNode = new Node<dataType>;
        newNode->data = temp->data;
        newNode->right = temp->right;
        newNode->left = temp->left->right;

        temp->data = temp->left->data;
        temp->left = temp->left->left;
        temp->right = newNode;
    }

    void print_given_level(Node<dataType> *temp, int level)
    {
        if (temp == NULL)
        {
            return;
        }
        if (level == 1)
        {
            cout << temp->data << " ";
        }
        else if (level > 1)
        {
            print_given_level(temp->left, level - 1);
            print_given_level(temp->right, level - 1);
        }
    }

    void print_level_by_level()
    {
        cout << "Level by Level:" << endl;
        int h = height(root);
        for (int i = 1; i <= h; i++)
        {
            print_given_level(root, i);
            cout << endl;
        }
    }

    int skewed()
    {
        // check if it is left skewed or right skewed
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return leftHeight - rightHeight;
    }

    int balanceFactor(Node<dataType> *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        else
        {
            return height(temp->left) - height(temp->right);
        }
    }

    ~AVL_BST()
    {
        delete root;
    }
};

int main()
{
    AVL_BST<int> tree_1;
    cout << "Creating an AVL Tree and inputting 3, 2, 1..." << endl;
    tree_1.insert(3);
    tree_1.insert(2);
    tree_1.insert(1);
    cout << "Checking if the tree is Skewed: " << endl;
    if (tree_1.skewed() > 0)
    {
        cout << "The tree is left skewed" << endl;
    }
    else if (tree_1.skewed() < 0)
    {
        cout << "The tree is right skewed" << endl;
    }
    else if (tree_1.skewed() == 0)
    {
        cout << "The tree is not skewed" << endl;
    }
    cout << "Printing the Tree: " << endl;
    tree_1.display();
    tree_1.print_level_by_level();
    cout << "Converting to AVL Tree..." << endl;
    tree_1.Balance_Tree();
    cout << "Printing the Tree: " << endl;
    tree_1.display();
    tree_1.print_level_by_level();
    cout << "As you can see, the tree is now balanced" << endl;

    cout << "\n\nNow doing the same for 4,7,15,30" << endl;
    AVL_BST<int> tree_2;
    tree_2.insert(4);
    tree_2.insert(7);
    tree_2.insert(15);
    tree_2.insert(30);
    cout << "Checking if the tree is Skewed: " << endl;
    if (tree_2.skewed() > 0)
    {
        cout << "The tree is left skewed" << endl;
    }
    else if (tree_2.skewed() < 0)
    {
        cout << "The tree is right skewed" << endl;
    }
    else if (tree_2.skewed() == 0)
    {
        cout << "The tree is not skewed" << endl;
    }
    cout << "Printing the Tree: " << endl;
    tree_2.display();
    tree_2.print_level_by_level();
    cout << "Converting to AVL Tree..." << endl;
    tree_2.Balance_Tree();
    cout << "Printing the Tree: " << endl;
    tree_2.display();
    tree_2.print_level_by_level();
    cout << "As you can see, the tree is now balanced" << endl;

    cout << "\n\nNow doing the same for 4,3,5,2,6,1,7" << endl;
    AVL_BST<int> tree_3;
    tree_3.insert(4);
    tree_3.insert(3);
    tree_3.insert(5);
    tree_3.insert(2);
    tree_3.insert(6);
    tree_3.insert(1);
    tree_3.insert(7);
    cout << "Checking if the tree is Skewed: " << endl;
    if (tree_3.skewed() > 0)
    {
        cout << "The tree is left skewed" << endl;
    }
    else if (tree_3.skewed() < 0)
    {
        cout << "The tree is right skewed" << endl;
    }
    else if (tree_3.skewed() == 0)
    {
        cout << "The tree is not skewed" << endl;
    }
    cout << "Printing the Tree: " << endl;
    tree_3.display();
    tree_3.print_level_by_level();
    cout << "Converting to AVL Tree..." << endl;
    tree_3.Balance_Tree();
    cout << "Printing the Tree: " << endl;
    tree_3.display();
    tree_3.print_level_by_level();
    cout << "As you can see, the tree was already balanced and has not changed" << endl
         << endl;

    system("pause");
    return 0;
}