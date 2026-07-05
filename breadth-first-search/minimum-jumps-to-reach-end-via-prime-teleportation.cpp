// class Solution {
// public:
//     int minJumps(vector<int>& nums) {
//         if(nums.size()==1) return 0;
//         int n = nums.size();
//         vector<bool> isPrime(n,true);
//         for(int i=0;i<n;i++){
//             if(nums[i]<2) {
//                 isPrime[i]=false;
//                 continue;
//             }
//             int e = nums[i];
//             for(int j=2;j*j<=e;j++){
//                 if(e % j == 0) {
//                     isPrime[i] = false;
//                     break;
//                 }
//             }
//         }

//         unordered_map<int,list<int>> adjList;
//         for(int i=0;i<n;i++){
//             if(i+1<n) adjList[i].push_back(i+1);
//             if(i-1>=0) adjList[i].push_back(i-1);
//             if(isPrime[i]){
//                 for(int j=0;j<n;j++){
//                     if( j != i && nums[j] % nums[i] == 0 ) adjList[i].push_back(j);
//                 }
//             }
//         }

//         queue<int> q;
//         unordered_map<int,bool> vis;
//         q.push(0);
//         vis[0] = true;
//         int target = n-1;

//         int ans = 0;
//         while(!q.empty()){  
//             int sz = q.size();
//             for(int i=0;i<sz;i++){
//                 auto front = q.front();
//                 if(front == target) return ans;
//                 q.pop();
//                 for(auto nbr:adjList[front]){
//                     if(!vis[nbr]) {
//                         q.push(nbr);
//                         vis[nbr] = true;
//                     }
//                 }
//             }
//             ans++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int MX = *max_element(nums.begin(), nums.end());

        // Step 1: Build SPF sieve
        vector<int> spf(MX + 1);
        for (int i = 0; i <= MX; i++) spf[i] = i;
        for (int i = 2; i  <= sqrt(MX); i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= MX; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        // Step 2: For every index, find its prime factors
        //         and add this index to that prime's bucket
        unordered_map<int, vector<int>> bucket; // prime -> list of indices
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            while (v > 1) {
                int p = spf[v];
                // avoid adding same index twice for same prime
                if (bucket[p].empty() || bucket[p].back() != i) {
                    bucket[p].push_back(i);
                }
                while (v % p == 0) v /= p; // remove all copies of p
            }
        }

        // Step 3: BFS
        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == n - 1) return dist[cur];

            // Try adjacent steps
            for (int nb : {cur - 1, cur + 1}) {
                if (nb >= 0 && nb < n && dist[nb] == -1) {
                    dist[nb] = dist[cur] + 1;
                    q.push(nb);
                }
            }

            // Try teleport — only if nums[cur] is itself prime
            int v = nums[cur];
            if (v >= 2 && spf[v] == v) { // spf[v] == v means v is prime
                if (bucket.count(v)) {
                    for (int nb : bucket[v]) {
                        if (dist[nb] == -1) {
                            dist[nb] = dist[cur] + 1;
                            q.push(nb);
                        }
                    }
                    bucket.erase(v); // never touch this bucket again
                }
            }
        }

        return dist[n - 1];
    }
};