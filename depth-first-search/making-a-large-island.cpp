class dsu{
    public:
    vector<int> sizze,parent;
    dsu(int n){
        sizze.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int ulPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = ulPar(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu = ulPar(u);
        int pv = ulPar(v);
        if(pu==pv) return;

        if(sizze[pu] < sizze[pv]){
            parent[pu] = pv;
            sizze[pv]+=sizze[pu];
        }
        else if(sizze[pu] >= sizze[pv]){
            parent[pv] = pu;
            sizze[pu]+=sizze[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        dsu ds(m*n);

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;

                int node = i*m + j;

                for(int k=0;k<4;k++){
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if(ni<0 || ni>=n || nj<0 || nj>=m || grid[ni][nj]==0 ) continue;
                    
                    int nbrNode = ni*m + nj;

                    ds.unionBySize(node,nbrNode);
                }
                
            }
        }


        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1) continue;

                set<int> st;

                for(int k=0;k<4;k++){

                    int ni=i+dx[k];
                    int nj=j+dy[k];

                    if(ni<0 || ni>=n || nj<0 || nj>=m || grid[ni][nj]==0) continue;

                    st.insert(ds.ulPar(ni*m+nj));
                }

                int total=0;

                for(auto it:st) total+=ds.sizze[it];

                ans=max(ans,1+total);
            }
        }
        return ans==INT_MIN ? n*m : ans;
    }
};