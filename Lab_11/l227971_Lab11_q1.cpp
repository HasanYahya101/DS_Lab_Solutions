#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Define a struct for a node in the Huffman tree
struct node
{
    char data;
    int frequency;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};

// Function to build the Huffman tree
node *buildHuffmanTree(vector<node *> &v)
{
    while (v.size() > 1)
    {
        // Sort vector based on frequency in ascending order
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = 0; j < v.size() - i - 1; j++)
            {
                if (v[j]->frequency > v[j + 1]->frequency)
                {
                    swap(v[j], v[j + 1]);
                }
            }
        }

        // Create a new internal node with the two lowest frequencies
        node *newNode = new node();
        newNode->data = '\0'; // Internal nodes have no data
        newNode->frequency = v[0]->frequency + v[1]->frequency;
        newNode->left = v[0];
        newNode->right = v[1];

        // Remove the two lowest frequency nodes from the vector
        v.erase(v.begin());
        v.erase(v.begin());

        // Insert the new internal node into the vector
        v.push_back(newNode);
    }

    return v[0];
}

void swap(node *&a, node *&b)
{
    node *temp = a;
    a = b;
    b = temp;
}

// Function to generate Huffman codes for each character
void generateHuffmanCodes(node *root, string code, vector<pair<char, string>> &huffmanCodes)
{
    if (root->left == NULL && root->right == NULL)
    {
        huffmanCodes.push_back({root->data, code});
        return;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode the input string using Huffman codes
string encodeString(const string &input, const vector<pair<char, string>> &huffmanCodes)
{
    string encodedString = "";
    for (char ch : input)
    {
        for (const auto &code : huffmanCodes)
        {
            if (code.first == ch)
            {
                encodedString += code.second;
                break;
            }
        }
    }
    return encodedString;
}

int main()
{
    string text;
    ifstream file("huffman_testing.txt");
    while (getline(file, text))
    {
        cout << text;
    }
    cout << endl;
    file.close();

    // Count character frequencies
    vector<node *> nodes;
    for (char ch : text)
    {
        bool found = false;
        for (node *n : nodes)
        {
            if (n->data == ch)
            {
                n->frequency++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            node *temp = new node();
            temp->data = ch;
            temp->frequency = 1;
            nodes.push_back(temp);
        }
    }

    // Build the Huffman tree
    node *huffmanTreeRoot = buildHuffmanTree(nodes);

    // Generate Huffman codes for each character
    vector<pair<char, string>> huffmanCodes;
    generateHuffmanCodes(huffmanTreeRoot, "", huffmanCodes);

    // Display Huffman codes for each character
    for (const auto &entry : huffmanCodes)
    {
        cout << "Character '" << entry.first << "' : Code " << entry.second << endl;
    }

    // Encode the input string
    string encodedString = encodeString(text, huffmanCodes);
    cout << "Encoded String: " << encodedString << endl;

    system("pause");
    return 0;
}
