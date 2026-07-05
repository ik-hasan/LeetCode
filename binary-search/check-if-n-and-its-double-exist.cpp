class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int x = arr[i]*2;
            for(int j=0;j<arr.size();j++){
                if(j!=i && x==arr[j]) return true;
            }
        }
        return false;
    }
};