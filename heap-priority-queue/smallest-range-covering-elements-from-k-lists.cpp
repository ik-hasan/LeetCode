


class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;
    Info(int data,int rowIndex,int colIndex){
        this->data=data;
        this->rowIndex=rowIndex;
        this->colIndex=colIndex;
    }
};

class compare{
    public:
    bool operator()(Info* a,Info* b){
        return a->data > b->data;//min heap
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<Info*,vector<Info*>,compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            Info* elem = new Info(nums[i][0],i,0);//data,row,col
            pq.push(elem);
            maxi = max(maxi,elem->data);
            mini = min(mini,elem->data);
        }

        int startingRangeVal = mini, endingRangeVal = maxi;
        
        while(!pq.empty()){

            auto front = pq.top();
            pq.pop();
            int rowIndex = front->rowIndex;
            int colIndex = front->colIndex;
            mini = front->data;

            if(maxi-mini < endingRangeVal-startingRangeVal){
                endingRangeVal = maxi;
                startingRangeVal = mini;
            }

            int totalCols = nums[rowIndex].size();
            if(colIndex + 1 < totalCols){
                Info* elem = new Info(nums[rowIndex][colIndex+1],rowIndex,colIndex+1);
                pq.push(elem);
                maxi = max(maxi,elem->data);
            }
            else break;
        }
        
        vector<int> ans;
        ans.push_back(startingRangeVal);
        ans.push_back(endingRangeVal);
        return ans;
    }
};