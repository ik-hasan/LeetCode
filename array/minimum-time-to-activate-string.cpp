// BRUTE FORCE
// class Solution {
// public:

//     bool solve(string &s,int k) {
//         int ans = 0;
//         int lastStar = -1;
        
//         for (int right = 0; right < s.size(); right++) {
//             if (s[right] == '*')
//                 lastStar = right;
        
//             ans += (lastStar + 1);
//             if(ans>=k) return true;
//         }
//         return false;
//     }

//     int minTime(string s, vector<int>& o, int k) {

//         for(auto i=0;i<o.size();i++){
//             s[o[i]] = '*';
//             if(solve(s,k)) return i;
//         }
//         return -1;
//     }
// };


class Solution {
public:
    using ll = long long;

    ll f(ll x) {
        return x * (x + 1) / 2;
    }

    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();

        ll total = f(n);
        ll withoutStar = total;

        set<int> st = {-1, n};

        for (int i = 0; i < order.size(); i++) {
            int p = order[i];

            auto it = st.lower_bound(p);
            int r = *it;
            int l = *prev(it);

            withoutStar -= f(r - l - 1);
            withoutStar += f(p - l - 1);
            withoutStar += f(r - p - 1);

            st.insert(p);

            if (total - withoutStar >= k)
                return i;
        }

        return -1;
    }
};





