class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        set<vector<int>> seen(points.begin(),points.end());
        vector<vector<int>> allPoints = points;

        if(seen.count(target)) return 0;

        int k=0;
        while(true){
            k++;
            vector<vector<int>> newPoints;
            int n = allPoints.size();

            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    vector<int> mid ={
                        (allPoints[i][0] + allPoints[j][0])/2,
                        (allPoints[i][1] + allPoints[j][1])/2,
                        (allPoints[i][2] + allPoints[j][2])/2
                    };
                    if(!seen.count(mid)){
                        seen.insert(mid);
                        newPoints.push_back(mid);
                    }
                }
            }

            if(newPoints.empty()) return -1;

            bool found = false;

            for(auto p:newPoints){
                if(p==target) {
                    found=true;
                    break;
                }
            }
            if(found) return k;

            for(auto p:newPoints) allPoints.push_back(p);
        }
    }
};