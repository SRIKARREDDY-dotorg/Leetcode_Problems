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

// Using priority queue

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // undirected weighted graph
        // gives the maximum probability.
        vector<pair<int, double>> adjGraph[n];

        for(int i = 0; i < edges.size(); i++) {
            adjGraph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjGraph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> ans(n, 0.0);
        priority_queue<pair<double, int>> pq;
        
        pq.push({1.0, start_node});
        while(!pq.empty()) {
            pair<double, int> pdi  = pq.top();
            int node = pdi.second;
            double prob = pdi.first;
            pq.pop();

            for(auto& edge: adjGraph[node]) {
                if(edge.second*prob > ans[edge.first]) {
                    ans[edge.first] = edge.second*prob;
                    pq.push({ans[edge.first], edge.first});
                }
            }
        }

        return ans[end_node];
    }
};
