// ---------------------- problem3.cpp ----------------------------
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <deque>
#include <algorithm>
using namespace std;

struct Node {
    Node * left;
    Node * right;
    string val;
    Node(string content) {
        left = NULL;
        right = NULL;
        val = content;
    }
};

class TreeBuilder {
private:
    vector<string> * post_order;
    vector<string> * in_order;
    int length;
    vector<string> * tokenize_string(int N, string s) {
        length = N;
        vector<string> * vect = new vector<string>;
        stringstream ss(s);
        for (int i = 0; i < N; i++) {
            string token;
            ss >> token;
            vect->push_back(token);
        }
        return vect;
    }
    int find_in_vect(vector<string> vect,string value,int begin, int end) {
        for (int i = begin; i <= end; i++) {
            if (vect[i] == value){
                return i;
            }
        }
        return -100;
    }
    Node * recursive_reconstruct(int begin_inorder, int end_inorder, int begin_post, int end_post) {
        if (end_inorder < begin_inorder || end_post < begin_post) {
            return NULL;
        }
        Node * root = new Node(post_order->at(end_post));
        int in_ord_rt_indx = find_in_vect(*in_order, post_order->at(end_post), begin_inorder, end_inorder);
        root->left = recursive_reconstruct(begin_inorder, in_ord_rt_indx - 1,begin_post, begin_post + in_ord_rt_indx - (begin_inorder + 1));
        root->right = recursive_reconstruct(in_ord_rt_indx + 1, end_inorder, begin_post + in_ord_rt_indx - begin_inorder, end_post-1);
        return root;
    }
public:
    TreeBuilder(int N, string post_o, string in_o) {
        post_order = tokenize_string(N, post_o);
        in_order = tokenize_string(N, in_o);
    }
    Node * build(){
        return recursive_reconstruct(0,length - 1,0,length - 1);
    }
    ~TreeBuilder() {
        delete post_order;
        delete in_order;
    }
};

void level_order(Node * root) {
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

int main() {
    string elements;
    getline(cin,elements);
    int N  = atoi(elements.c_str());
    string post_order;
    getline(cin,post_order);
    string in_order;
    getline(cin,in_order);
    TreeBuilder tb(N,post_order,in_order);
    Node * root = tb.build();
    level_order(root);
    return 0;
}
