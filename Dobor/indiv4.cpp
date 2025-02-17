#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::queue;
using std::endl;

void bfs(int start, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        component.push_back(node);

        for (int index = 0; index < adj[node].size(); index++) {
            if (adj[node][index] == 1 && !visited[index]) {
                q.push(index);
                visited[index] = true;
            }
        }
    }
}

int main() {
    ifstream inFile("inputIndiv4.txt");
    ofstream outFile("outputIndiv4.txt");
    int n;
    inFile >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int index = 0; index < n; index++) {
        for (int jndex = 0; jndex < n; ++jndex) {
            inFile >> adj[index][jndex];
        }
    }

    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int index = 0; index < n; index++) {
        if (!visited[index]) {
            vector<int> component;
            bfs(index, adj, visited, component);
            components.push_back(component);
        }
    }

    for (int index = 0; index < components.size(); index++) {
        outFile << "Component " << index + 1 << ": ";
        for (int vertex : components[index]) {
            outFile << vertex + 1 << " ";
        }
        outFile << endl;
    }

    return 0;
}
