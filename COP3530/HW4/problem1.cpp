// ---------------------- problem1.cpp ----------------------------
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    string val;
    Node() {
        left = NULL;
        right = NULL;
        val = "";
    }
};

void in_order(Node* root) {
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
    
}

void post_order(Node* root) {
    if (root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

void pre_order(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}

Node* scan_init_tree() {
    string firstLine;
    getline(cin,firstLine);
    int N  = atoi(firstLine.c_str());
    vector<Node*> node_pool(N,NULL);
    for (int i = 0; i < N; i++) {
        node_pool[i] = new Node();
    }
    for (int i = 0; i < N; i++) {
        string userInput;
        getline(cin,userInput);
        stringstream s(userInput);
        string str_val;
        s >> str_val;
        node_pool[i]->val = str_val;
        int l, r;
        s >> l >> r;
        if (0 < l && l < N) {
            node_pool[i]->left = node_pool[l];
        }
        if (0 < r && r < N) {
            node_pool[i]->right = node_pool[r];
        }
    }
    return node_pool[0];
}

int main() {
    Node* tree_root = scan_init_tree();
    post_order(tree_root);
    cout << endl;
    in_order(tree_root);
    cout << endl;
    pre_order(tree_root);
    cout << endl;
    return 0;
}