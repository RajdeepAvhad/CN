#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int cost[10][10];
    cout << "Enter cost matrix (999 for infinity):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    cout << "\n--- Link State Routing Table ---\n";

    for (int src = 0; src < n; src++) {

        int dist[10], visited[10] = {0};

        // initialize distances
        for (int i = 0; i < n; i++)
            dist[i] = cost[src][i];

        visited[src] = 1;

        // Dijkstra's Algorithm
        for (int count = 1; count < n; count++) {
            int minDist = 999, u = -1;

            // find minimum unvisited node
            for (int i = 0; i < n; i++)
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }

            visited[u] = 1;

            // relax neighbors
            for (int v = 0; v < n; v++)
                if (!visited[v] && dist[u] + cost[u][v] < dist[v])
                    dist[v] = dist[u] + cost[u][v];
        }

        // Print routing table for this source
        cout << "\nShortest paths from Node " << src << ":\n";
        for (int i = 0; i < n; i++)
            cout << "To " << i << " : " << dist[i] << endl;
    }

    return 0;
}

