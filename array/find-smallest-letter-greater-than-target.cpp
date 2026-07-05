class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target=='z') return letters[0];

        for(int i=0;i<letters.size();i++){
            if(target-'0' < letters[i]-'0'){
                return letters[i];
            }
        }

        return letters[0];
    }
};