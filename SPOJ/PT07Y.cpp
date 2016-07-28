//  http://www.spoj.com/status/b_babtsov/
//
//
//  Created by Ben on 4/8/16.
//

#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

class graph {
public:
    graph(int vertices):
    v_buckets(vertices + 1) // add additional bucket to turn it into 1-index based array.
                            // 0th bucket would be empty and no access would be allowed
    {
    }
    void add_edge(int vertex1, int vertex2) {
        if (!is_valid_vrtx(vertex1) || !is_valid_vrtx(vertex2)) {
            throw runtime_error("vertex number out of bounds");
        }
        v_buckets.at(vertex1).push_front(vertex2);
        v_buckets.at(vertex2).push_front(vertex1);
    }
    forward_list<int> & adjacent_to(int vertex) { // return all the neighbors of a particular vertex
        if (!is_valid_vrtx(vertex)) {
            throw runtime_error("vertex number out of bounds");
        }
        return v_buckets.at(vertex);
    }
    int vertices() {
        return (int)v_buckets.size() - 1;
    }
    void print(){ //useful for debugging
        for (int i = 0; i < v_buckets.size(); i++) {
            auto bucket = v_buckets.at(i);
            cout << i << ") ";
            for (auto v : bucket) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
private:
    inline bool is_valid_vrtx(int n) {
        return n > 0 && n < v_buckets.size();
    }
    vector<forward_list<int>> v_buckets; // vertex buckets
};

bool is_tree(vector<bool> & visited, int & total, graph & g, int vertex, int prev_vertex) {
    if (visited.at(vertex)) {
        return false;
    }
    visited.at(vertex) = true;
    total++;
    for (auto neighbor : g.adjacent_to(vertex)) {
        if (neighbor == prev_vertex) {
            continue;
        }
        if(!is_tree(visited,total,g,neighbor,vertex)) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int nodes, edges;
    cin >> nodes >> edges;
    graph g(nodes);
    for (int i = 0; i < edges; i++) {
        int u,v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
//    g.print();    // uncomment this one to see the resulting graph
    vector<bool> visited_vert(nodes + 1,false);
    int total_vert_visited = 0;
    bool one_tree_detected = is_tree(visited_vert,total_vert_visited,g,1,0); // start BFS from node 1
    if (one_tree_detected && total_vert_visited == g.vertices()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}













