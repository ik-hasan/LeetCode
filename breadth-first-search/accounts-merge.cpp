class disjoint {
    vector<int> sizze, parent;

public:
    disjoint(int n) {
        sizze.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findUltParent(u);
        int pv = findUltParent(v);

        if (pu == pv)
            return;

        if (sizze[pu] < sizze[pv]) {
            parent[pu] = pv;
            sizze[pv] += sizze[pu];
        } else {
            parent[pv] = pu;
            sizze[pu] += sizze[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        unordered_map<string, int> mapMailNode;

        disjoint ds(n);

        // Build DSU
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);

        // Put every mail in its ultimate parent's bucket
        for (auto it : mapMailNode) {

            string mail = it.first;
            int node = ds.findUltParent(it.second);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto mail : mergedMail[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};