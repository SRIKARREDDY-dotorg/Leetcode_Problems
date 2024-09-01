// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/?envType=daily-question&envId=2024-06-30

class UnionFind {
public:
    int components;
    vector<int> parent, size;
    UnionFind(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        components = n;
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    bool isConnected() {
        return components == 1;
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY) return false;
        if(size[rootX] < size[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        components--;
        return true;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int edgesRequired = 0;

        UnionFind alice(n), bob(n);
        for(auto& edge: edges) {
            if(edge[0] == 3) {
                if(alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }

        for(auto& edge: edges) {
            if(edge[0] == 1) {
                if(alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }

            else if(edge[0] == 2) {
                if(bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }

        if(alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        return -1;
    }
};
