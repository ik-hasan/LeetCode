class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xorAll = 0;
        for(int i=0;i<nums.size();i++){
            xorAll ^= nums[i];
        }
        // xorAll me dono ka unique elem ka XOR pda h isey
        // ab separate rkna h

        int separatorBit = xorAll & -(unsigned int)xorAll;
        //ab hmare array me 2 grp bnenge jisme ek grp ke pas 
        //ye separator bit hogi & dusre grp ke pas nhi hogi

        int firstUniq = 0, secondUniq=0;
        for(auto num : nums){
            if(separatorBit & num){
                firstUniq ^= num;
            }
            else {
                secondUniq ^= num;
            }
        }
        return {firstUniq,secondUniq};
    }
};