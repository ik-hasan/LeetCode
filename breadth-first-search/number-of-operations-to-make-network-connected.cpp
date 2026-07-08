class disjoint{
  vector<int> parent,size;
  public:

  disjoint(int n){
    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
      parent[i]=i;
    }
  }

  int ultimateParent(int node){
    if(node==parent[node]) return node;
    return parent[node] = ultimateParent(parent[node]);
  }

  void unionBySize(int u, int v){
    int ult_u = ultimateParent(u);
    int ult_v = ultimateParent(v);
    if(ult_u == ult_v) return;

    if(size[ult_u]<size[ult_v]){
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }
    else if(size[ult_u] >= size[ult_v]){
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    }
  }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1) return -1;

        disjoint ds(n);

        for (auto &it : connections) {
            ds.unionBySize(it[0], it[1]);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.ultimateParent(i) == i) components++;
        }

        return components - 1;
    }
};