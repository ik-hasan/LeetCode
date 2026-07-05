
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Ignore leading spaces
        while (i < n && s[i] == ' ') i++;
        if(i==s.size()) return 0;
        
        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // 3. Convert digits
        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return sign * num;
    }
};

// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0, sign = 1;
//         long res = 0; // Using long to handle overflow cases

//         // Trim leading spaces
//         while (i < s.size() && s[i] == ' ') i++;
//         if (i == s.size()) return 0;

//         // Check for sign
//         if (s[i] == '-') { sign = -1; i++; }
//         else if (s[i] == '+') i++;

//         // Process numerical characters
//         while (i < s.size() && isdigit(s[i])) {
//             res = res * 10 + (s[i] - '0');

//             // Handle overflow
//             if (sign * res > INT_MAX) return INT_MAX;
//             if (sign * res < INT_MIN) return INT_MIN;

//             i++;
//         }

//         return (int)(sign * res);
//     }
// };
