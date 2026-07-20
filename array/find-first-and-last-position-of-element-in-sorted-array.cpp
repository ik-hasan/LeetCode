class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=-1,b=-1,s=0,e=nums.size()-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            int midd=nums[mid];

            if(midd==target){
                a=mid;
                e=mid-1;
            }
            else if(midd>target) e=mid-1;
            else s=mid+1;
        }

        s=0,e=nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int midd=nums[mid];

            if(midd==target){
                b=mid;
                s=mid+1;
            }
            else if(midd>target) e=mid-1;
            else s=mid+1;
        }
        return {a,b};
    }
};