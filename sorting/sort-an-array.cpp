
//OUTPLACE MERGE SORT(USING AN EXTRA ARRAY)

// class Solution {
// public:
//     void merge(vector<int>& nums, vector<int>& temp, int st,int mid,int end){
//         int i = st,j=mid+1,k=st;

//         while(i<=mid && j<=end){
//             if(nums[i]<=nums[j]) temp[k++]=nums[i++];
//             else temp[k++]=nums[j++];
//         }

//         while(i<=mid) temp[k++]=nums[i++];
//         while(j<=end) temp[k++]=nums[j++];

//         while(st<=end) {
//             nums[st]=temp[st];
//             st++;
//         }
//         return;
//     }
//     void mergeSort(vector<int>& nums,vector<int>& temp,int st, int end){
//         if(st>=end) return;
//         int mid = (st+end)/2;
//         mergeSort(nums,temp,st,mid);
//         mergeSort(nums,temp,mid+1,end);
//         merge(nums,temp,st,mid,end);
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         vector<int> temp(nums.size(),0);
//         mergeSort(nums,temp,0,nums.size()-1);
//         return nums;
//     }
// };



//IN PLACE MERGE SORT(NO EXTRA SPACE)
class Solution {
public:
    void merge(vector<int>& nums, int st,int mid,int end){

        int gap = (end-st+1)/2 + (end-st+1)%2;


        //it works like magic, we run this loop until gap becomes 1 or less than 1
        while(gap > 0){
            int i = st, j = st+gap;
            while(j<=end){
                if(nums[i]>nums[j]) swap(nums[i],nums[j]);
                i++,j++;
            }
            if(gap<=1) gap = 0;
            else gap = gap%2 + gap/2;
        }
    }
    void mergeSort(vector<int>& nums,int st, int end){
        if(st>=end) return;
        int mid = (st+end)/2;
        mergeSort(nums,st,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,st,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};