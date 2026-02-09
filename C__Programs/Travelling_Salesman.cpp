#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int travellingSalesman(vector<vector<int>> &graph, int start) {
    int n = graph.size();
    vector<int> vertices;

    // Store all vertices except starting vertex
    for (int i = 0; i < n; i++) {
        if (i != start)
            vertices.push_back(i);
    }

    int min_cost = INT_MAX;

    // Generate all permutations of vertices
    do {
        int cost = graph[start][vertices[0]];

        // Calculate cost of current path
        for (int i = 0; i < vertices.size() - 1; i++) {
            cost += graph[vertices[i]][vertices[i + 1]];
        }

        // Return to starting city
        cost += graph[vertices.back()][start];

        min_cost = min(min_cost, cost);

    } while (next_permutation(vertices.begin(), vertices.end()));

    return min_cost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0;

    cout << "Minimum cost: "
         << travellingSalesman(graph, start);

    return 0;
}
