//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:


// Function to collect left boundary nodes (excluding leaves)
void collectLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        // Only add if it's not a leaf node
        if (curr->left || curr->right) {
            res.push_back(curr->data);
        }
        // Move to the next node in the left boundary
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

// Function to collect leaf nodes
void collectLeaves(Node* root, vector<int>& res) {
    if (!root) return;
    if (!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }
    // Recursively collect leaves from left and right subtrees
    if (root->left) collectLeaves(root->left, res);
    if (root->right) collectLeaves(root->right, res);
}

// Function to collect right boundary nodes in reverse order (excluding leaves)
void collectRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp; // Temporary vector to hold right boundary nodes
    while (curr) {
        // Only add if it's not a leaf node
        if (curr->left || curr->right) {
            temp.push_back(curr->data);
        }
        // Move to the next node in the right boundary
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    // Add nodes from the temporary vector to result in reverse order
    for (int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

// Function to get the boundary of a binary tree
vector<int> boundary(Node* root) {
    vector<int> res;
    if (!root) return res; // Return empty result for null root

    // Add root data if it has at least one child
    if (root->left || root->right) {
        res.push_back(root->data);
    }
    
    // Collect left boundary nodes
    collectLeftBoundary(root, res);
    
    // Collect leaf nodes
    collectLeaves(root, res);
    
    // Collect right boundary nodes
    collectRightBoundary(root, res);
    
    return res;
}

    // void fn1(Node *root, vector<int> &res){
    //     Node* curr = root->left;
    //     while(curr){
    //         if(curr->left || curr->right){
    //             res.push_back(curr->data);
    //             return;
    //         }
    //         if(curr->left != nullptr) curr = curr->left;
    //         else curr = curr->right;
    //     }
    // }
    
    // void bottom(Node *root, vector<int> &res){
    //     if(root ==nullptr) return ;
    //     if(root->left == nullptr && root->right == nullptr){
    //         res.push_back(root->data);
    //     }
    //     if(root->left != nullptr) bottom(root->left, res);
    //     if(root->right != nullptr) bottom(root->right, res);
    // }
    
    // void fn2(Node *root, vector<int> &res){
    //     vector<int> ans;
    //     Node* curr = root->right;
    //     while(curr){
    //         if(curr->left || curr->right){
    //             ans.push_back(curr->data);
    //         }
    //         if(curr->right) curr = curr->right;
    //         else curr = curr->left;
    //     }
    //     for(int i = ans.size() -1; i >=0; i--){
    //         res.push_back(ans[i]);
    //     }
        
    // }
    
    // vector <int> boundary(Node *root)
    // {
    //     //Your code here
    //     vector<int> res;
    //     if(root == nullptr) return {};
    //     if(root->left != nullptr || root->right != nullptr) res.push_back(root->data);
    //     fn1(root,res);//left side traversal;
    //     bottom(root,res);
    //     fn2(root,res);
    //     return res;
    // }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends