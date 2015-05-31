class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int t =k;
        if( k>=nums.size()) t = nums.size();
        for(int i = 0;  i<= nums.size() -t ; i++){
            for(int j =i+1; j<nums.size(); j++)
                if(nums[i] == nums[j] &&  j-i <=k) 
                    return true;
        }
       
        return false;
    }
};
