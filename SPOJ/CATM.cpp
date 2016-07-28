//  http://www.spoj.com/status/b_babtsov/
//
//
//  Created by Ben on 4/15/16.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>
#include <utility>
#include <cassert>
using namespace std;

void print_grid(vector<vector<int>> grid) {
    for (auto row : grid) {
        for (auto elem : row) {
            if (elem == INT_MAX) {
                cout << "+" << " ";
            } else if (elem == INT_MIN) {
                cout << "-" << " ";
            } else {
                cout << elem << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

inline bool is_on_grid(const vector<vector<int>> & grid, const pair<int, int> & point) {
    return point.first >= 0 && point.first < grid.size()
        && point.second >= 0 && point.second < grid[0].size();
}
inline bool is_on_edge(const vector<vector<int>> & grid, const pair<int, int> & point) {
    return point.first == 0 || point.first == grid.size() - 1
    || point.second == 0 || point.second == grid[0].size() - 1;
}

void min_cat_dist(vector<vector<int>> & grid, pair<int, int> cat_coordinate) {
    grid[cat_coordinate.first][cat_coordinate.second] = 0;
    queue<pair<int, int>> bfs_queue;
    bfs_queue.push(cat_coordinate);
    while(!bfs_queue.empty()) {
        pair<int, int> p = bfs_queue.front();
        bfs_queue.pop();
        int neighbor_dist = grid[p.first][p.second] + 1;
        pair<int, int> neighbors[4] = {make_pair(p.first - 1, p.second),
                                       make_pair(p.first + 1, p.second),
                                       make_pair(p.first, p.second - 1),
                                       make_pair(p.first, p.second + 1)};
        for (auto neighbor : neighbors) {
            if (is_on_grid(grid, neighbor) && neighbor_dist < grid[neighbor.first][neighbor.second]) {
                bfs_queue.push(neighbor);
                grid[neighbor.first][neighbor.second] = neighbor_dist;
            }
        }
    }
}

bool can_escape(vector<vector<int>> & grid, pair<int, int> mouse_coordinate) {
    queue<tuple<int, int, int>> bfs_queue;
    auto mouse = make_tuple(mouse_coordinate.first, mouse_coordinate.second,0);
    bfs_queue.push(mouse);
    while(!bfs_queue.empty()) {
        tuple<int, int,int> path_point = bfs_queue.front();
        bfs_queue.pop();
        auto p = make_pair(get<0>(path_point),get<1>(path_point));
        int mouse_dist = get<2>(path_point);
        if (is_on_edge(grid,p) && grid[p.first][p.second] >= mouse_dist) {
            return true;
        }
        pair<int, int> neighbors[4] = {make_pair(p.first - 1, p.second),
            make_pair(p.first + 1, p.second),
            make_pair(p.first, p.second - 1),
            make_pair(p.first, p.second + 1)};
        for (auto neighbor : neighbors) {
            if (is_on_grid(grid, neighbor) && mouse_dist + 1 < grid[neighbor.first][neighbor.second]) {
                bfs_queue.push(make_tuple(neighbor.first, neighbor.second, mouse_dist + 1));
            }
        }
        grid[p.first][p.second] = INT_MIN; // mark the current spot as visited by the mouse
    }
    return false;
}


inline bool balanced(pair<int, int> x) {
    return x.first == x.second;
}

bool diagonal(pair<int, int> mouse, pair<int, int> cat1, pair<int, int> cat2) {
    pair<int, int> mouse_cat1_dist(abs(mouse.first - cat1.first),abs(mouse.second - cat1.second));
    pair<int, int> mouse_cat2_dist(abs(mouse.first - cat2.first),abs(mouse.second - cat2.second));
    pair<int, int> cat1_cat2_dist(abs(cat1.first - cat2.first),abs(cat1.second - cat2.second));
    if (!balanced(mouse_cat1_dist) || !balanced(mouse_cat2_dist)) {
        return false;
    }
    assert(balanced(cat1_cat2_dist));
    if (mouse_cat2_dist.first < cat1_cat2_dist.first && mouse_cat1_dist < cat1_cat2_dist) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int rows,columns;
    cin >> rows >> columns;
    int testcases;
    cin >> testcases;
    while (testcases--) {
        pair<int, int> mouse, cat1, cat2;
        cin >> mouse.first >> mouse.second >> cat1.first >> cat1.second >> cat2.first >> cat2.second;
        vector<int> row(columns,INT_MAX);
        vector<vector<int>> grid(rows, row);
        mouse.first--; mouse.second--;cat1.first--;cat1.second--;cat2.first--;cat2.second--;
        if (is_on_edge(grid, mouse) || !diagonal(mouse, cat1, cat2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}