// ---------------------- problem2.cpp ----------------------------
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <deque>
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
void level_order(Node* root) {
    deque<Node*> queue;
    queue.push_back(root);
    while (!queue.empty()) {
        Node* elem = queue.front();
        queue.pop_front();
        cout << elem->val << " ";
        if (elem->left != NULL) {
            queue.push_back(elem->left);
        }
        if (elem->right != NULL) {
            queue.push_back(elem->right);
        }
    }
    cout << endl;
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
    level_order(tree_root);
    return 0;
}