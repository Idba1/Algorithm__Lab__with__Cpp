#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node structure
struct Node
{
    char ch;            // Character
    int freq;           // Frequency of the character
    Node *left, *right; // Left and Right child

    // Constructor for leaf node
    Node(char ch, int freq)
        : ch(ch), freq(freq), left(nullptr), right(nullptr) {}

    // Constructor for internal node
    Node(char ch, int freq, Node *left, Node *right)
        : ch(ch), freq(freq), left(left), right(right) {}
};

// Custom comparator for priority queue (Min Heap)
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq; // Higher frequency means lower priority
    }
};

// Function to generate and store Huffman Codes
void printCodes(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // If it's a leaf node, store the character with its code
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    // Recursive call for left child with '0' added to the code
    printCodes(root->left, str + "0", huffmanCode);
    // Recursive call for right child with '1' added to the code
    printCodes(root->right, str + "1", huffmanCode);
}

// Function to build Huffman Tree and generate Huffman Codes
void buildHuffmanTree(string text)
{
    // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }

    // Step 2: Create a priority queue (Min Heap)
    priority_queue<Node *, vector<Node *>, compare> pq;

    // Step 3: Create a leaf node for each character and push into the queue
    for (auto pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 4: Construct the Huffman Tree
    while (pq.size() != 1)
    {
        // Extract the two nodes with the smallest frequency
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with the sum of their frequencies
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right)); // '\0' represents internal node
    }

    // Step 5: Root of the Huffman Tree
    Node *root = pq.top();

    // Step 6: Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    // Step 7: Print Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << "\n";
    }

    // Step 8: Encode the original text
    cout << "\nOriginal string:\n"
         << text << "\n";
    string encodedString = "";
    for (char ch : text)
    {
        encodedString += huffmanCode[ch];
    }
    cout << "\nEncoded string:\n"
         << encodedString << "\n";

    // Step 9: Decode the encoded string
    auto decode = [&](string str)
    {
        cout << "\nDecoded string:\n";
        Node *curr = root;
        for (char bit : str)
        {
            if (bit == '0')
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }

            // If leaf node is reached, print character and reset to root
            if (!curr->left && !curr->right)
            {
                cout << curr->ch;
                curr = root;
            }
        }
        cout << "\n";
    };

    decode(encodedString);
}

// Main function
int main()
{
    string text = "HUFFMAN"; // Input text
    buildHuffmanTree(text);  // Call function to generate Huffman codes
    return 0;
}
