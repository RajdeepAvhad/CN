#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int cost[10][10], dist[10][10];

    cout << "Enter cost matrix (999 for infinity):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    // Initialize distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = cost[i][j];

    // Bellman-Ford (Distance Vector logic)
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "\nDistance Vector Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }

    return 0;
}

