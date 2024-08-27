// https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-08-27
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // construct graph
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); i ++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].emplace_back(v, succProb[i]);
            graph[v].emplace_back(u, succProb[i]);
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        queue<int> q;
        q.push(start_node);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto& edge: graph[node]) {
                int nextNode = edge.first;
                double nextProb = edge.second;

                double newProb = maxProb[node] * nextProb;
                // cout<<nextNode<<" "<<newProb<<endl;
                if(newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    q.push(nextNode);
                }
            }
        }
        return maxProb[end_node];
    }
};
