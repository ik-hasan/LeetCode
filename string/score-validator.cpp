class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score =0, count=0;
        for(auto it:events){
            if(count ==10) break;
            if(it == "0" || it=="1" || it=="2"|| it=="3"|| it=="4"|| it=="6"){
                score+= stoi(it);
            }
            if(it=="WD" || it=="NB") score+=1;
            else if(it =="W") {
                count+=1;
            }
        }
        return {score,count};
    }
};