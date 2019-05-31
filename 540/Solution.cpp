class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // assuming the input array is always non-empty and has a solution
        
        return singleNonDuplicate(nums, 0, nums.size()-1);
    }
    
    int singleNonDuplicate(vector<int>& nums, int left, int right){
        if (left == right) return nums[left];
        
        int mid = (left + right)/2;
        
        if (nums[mid-1] == nums[mid]){
            if ((mid-1)%2){ // the size of the left side is even, the solution is on the right side
                return singleNonDuplicate(nums, left, mid-2);
            } else{
                return singleNonDuplicate(nums, mid+1, right);
            }
        } else if (nums[mid] == nums[mid+1]){
            if (mid%2){
                return singleNonDuplicate(nums, left, mid-1); 
            } else{
                return singleNonDuplicate(nums, mid+2, right);
            }
        } else{ // it must be the single element
            return nums[mid];
        }
    }
};