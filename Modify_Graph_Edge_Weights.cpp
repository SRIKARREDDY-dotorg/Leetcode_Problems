// https://leetcode.com/problems/modify-graph-edge-weights/submissions/1374045798/?envType=daily-question&envId=2024-08-30
class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // Modify all edges
        // positive integer values 1 -> 2*10^9
        // shortest distance b/w src & dest = target
        long long distance = runDijkstra(edges, source, destination, n);
        if(distance < target) return {};

        bool isMatching = false;
        if(distance == target) {
            isMatching = true;
        }

        for(auto& edge: edges) {
            if(edge[2] > 0) continue;

            edge[2] = isMatching ? INF: 1;

            if(!isMatching) {
                long long newDistance = runDijkstra(edges, source, destination, n);

                if(newDistance <= target) {
                    isMatching = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return isMatching ? edges : vector<vector<int>>();
    }
    long long runDijkstra(vector<vector<int>>& edges, int source, int destination, int n) {
        vector<vector<long long>> adjGraph(n, vector<long long>(n, INF));
        vector<long long> minDistance(n, INT_MAX);
        vector<bool> visited(n, 0);
        
        minDistance[source] = 0;

        for(const vector<int>& edge: edges) {
            if(edge[2] < 0) continue;
            adjGraph[edge[0]][edge[1]] = edge[2];
            adjGraph[edge[1]][edge[0]] = edge[2];
        }

    for(int i = 0; i < n; i ++) {
        int nearestUnvisitedNode = -1;
        for(int j = 0; j < n; j ++) {
            if(!visited[j] && (nearestUnvisitedNode == -1 || minDistance[j] < minDistance[nearestUnvisitedNode])) {
                nearestUnvisitedNode = j;
            }
        }
        // mark the nearest unvisited node as visted and got the min distance.
        visited[nearestUnvisitedNode] = true;
        
        for(int v = 0; v < n; v ++) {
            minDistance[v] = min(minDistance[v], minDistance[nearestUnvisitedNode] + adjGraph[nearestUnvisitedNode][v]);
        }
    }
    return minDistance[destination];
}
};


// optimised approach
class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // Modify all edges
        // positive integer values 1 -> 2*10^9
        // shortest distance b/w src & dest = target
        long long distance = runDijkstra(edges, source, destination, n);
        if(distance < target) return {};

        bool isMatching = false;
        if(distance == target) {
            isMatching = true;
        }

        for(auto& edge: edges) {
            if(edge[2] > 0) continue;

            edge[2] = isMatching ? INF: 1;

            if(!isMatching) {
                long long newDistance = runDijkstra(edges, source, destination, n);

                if(newDistance <= target) {
                    isMatching = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return isMatching ? edges : vector<vector<int>>();
    }
    long long runDijkstra(vector<vector<int>>& edges, int source, int destination, int n) {
        vector<vector<long long>> adjGraph(n, vector<long long>(n, INF));
        vector<long long> minDistance(n, INT_MAX);
        vector<bool> visited(n, 0);
        
        minDistance[source] = 0;

        for(const vector<int>& edge: edges) {
            if(edge[2] < 0) continue;
            adjGraph[edge[0]][edge[1]] = edge[2];
            adjGraph[edge[1]][edge[0]] = edge[2];
        }

    for(int i = 0; i < n; i ++) {
        int nearestUnvisitedNode = -1;
        for(int j = 0; j < n; j ++) {
            if(!visited[j] && (nearestUnvisitedNode == -1 || minDistance[j] < minDistance[nearestUnvisitedNode])) {
                nearestUnvisitedNode = j;
            }
        }
        // mark the nearest unvisited node as visted and got the min distance.
        visited[nearestUnvisitedNode] = true;
        
        for(int v = 0; v < n; v ++) {
            minDistance[v] = min(minDistance[v], minDistance[nearestUnvisitedNode] + adjGraph[nearestUnvisitedNode][v]);
        }
    }
    return minDistance[destination];
}
};
