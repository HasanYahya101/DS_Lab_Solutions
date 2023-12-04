#include <iostream>
#include <climits>
using namespace std;

class Node
{
	public:
	int val;
	Node* left;
	Node* right;
	
	Node(int value)
	{
		val = value;
		left = right = NULL;
	}
};

class BinaryTree
{
    public:
    Node* root;
    int max_sum;

    BinaryTree()
    {
        root = new Node(10);
        root->left = new Node(2);
        root->right = new Node(10);
        root->left->left = new Node(20);
        root->left->right = new Node(1);
        root->right->right = new Node(-25);
        root->right->right->left = new Node(3);
        root->right->right->right = new Node(4);
        max_sum = INT_MIN;
    }

    int findMaxSum(Node* node)
    {
        if (node == NULL)
            return 0;

        int left = max(findMaxSum(node->left), 0);
        int right = max(findMaxSum(node->right), 0);

        max_sum = max(max_sum, left + right + node->val);

        return max(left, right) + node->val;
    }

    int findMaxSum()
    {
        findMaxSum(root);
        return max_sum;
    }

};

int main()
{
	BinaryTree tree;
	cout << "Max path sum is " << tree.findMaxSum() << endl;
	return 0;
}
