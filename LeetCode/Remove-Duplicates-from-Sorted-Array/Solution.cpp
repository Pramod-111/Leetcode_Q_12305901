class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int l=1;
        for(int r=1;r<nums.size();r++){
            if(nums[r]!=nums[r-1]){
                nums[l]=nums[r];
                l++;
            }
        }
        return l;
    }
};