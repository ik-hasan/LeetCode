// class Solution {
// public:
//     int sumFourDivisors(vector<int>& nums) {

//         int n = nums.size();
//         vector<int> ans;
//         for(int i=0;i<n;i++){

//             int x = 0;
//             int sum = 0;

//             for(int j=1;j<=nums[i];j++){

//                 if(nums[i] % j == 0 ){
//                     sum+=j;
//                     x++;
//                     if(x==4 && j==nums[i]){
//                         ans.push_back(sum);
//                     }
//                     if(x>4) {
//                         break;
//                     }
//                 }
//             }
//         }

//         int actualSum = 0;
//         for(int i=0;i<ans.size();i++){
//             actualSum += ans[i];
//         }
//         return actualSum;
//     }
// };




class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int n = nums.size();        
        int actualSum = 0;
        for(int i=0;i<n;i++){

            int x = 0;
            int sum = 0;

            for(int j=1;j<=nums[i];j++){

                if(nums[i] % j == 0 ){
                    sum+=j;
                    x++;
                    if(x==4 && j==nums[i]){
                        actualSum += sum;
                    }
                    if(x>4) {
                        break;
                    }
                }
            }
        }
       
        return actualSum;
    }
};