#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Define a class for the nodes in the Huffman tree
class Node
{
public:
    char char_;
    int freq;
    Node *left;
    Node *right;

    Node(char char_, int freq)
    {
        this->char_ = char_;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Define a comparison class for the priority queue
class Compare
{
public:
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

// Function to build the Huffman tree
Node *buildHuffmanTree(vector<char> &chars, vector<int> &freq)
{
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    for (size_t i = 0; i < chars.size(); ++i)
    {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    return minHeap.top();
}

// Function to generate Huffman codes from the tree
void generateCodes(Node *node, string prefix, unordered_map<char, string> &codebook)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->char_ != '\0')
    {
        codebook[node->char_] = prefix;
    }
    else
    {
        generateCodes(node->left, prefix + "0", codebook);
        generateCodes(node->right, prefix + "1", codebook);
    }
}

int main()
{
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    vector<int> freq = {4, 7, 12, 14, 17, 43, 54};

    Node *huffmanTree = buildHuffmanTree(chars, freq);
    unordered_map<char, string> huffmanCodes;
    generateCodes(huffmanTree, "", huffmanCodes);

    for (char c : chars)
    {
        cout << c << " -> " << huffmanCodes[c] << endl;
    }

    return 0;
}