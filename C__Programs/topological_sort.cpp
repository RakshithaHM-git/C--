
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(int V, vector<vector<int>> &adj) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int j : adj[i])
            indegree[j]++;
    }
    
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    cout << "Topological Sort: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i : adj[node]) {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topologicalSort(V, adj);
    return 0;
}