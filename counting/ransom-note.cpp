class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freq;

        // Count each char in magazine
        for (char c : magazine) freq[c]++;

        // Check if magazine has all chars required for ransomNote
        for (char c : ransomNote) {
            if (freq[c] == 0) return false;  // Not enough of char 'c'
            freq[c]--;
        }

        return true;
    }
};