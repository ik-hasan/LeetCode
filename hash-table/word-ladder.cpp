class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());

        q.push({beginWord,1});
        // st.erase(beginWord);//ye kyu kr rhe ye to hoga hi nhi set me

        while(!q.empty()){
            auto front = q.front();
            string frontString = front.first;
            int frontDist = front.second;
            q.pop();

            if(frontString == endWord) return frontDist;

            for(int index = 0; index<frontString.length();index++){
                char originalChar = frontString[index];//this & line 28 are imp step yhi bhul jaunga
                for(char ch ='a'; ch<='z'; ch++){
                    frontString[index]=ch;
                    if(st.find(frontString) != st.end()){
                        q.push({frontString,frontDist+1});
                        st.erase(frontString);
                    }
                }
                frontString[index] = originalChar;
            }
        } 
        return 0;
    }
};