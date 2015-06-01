class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> solution(2,-1);
        for (int i = 0; i < nums.size(); i++) { 
            mp[nums[i]] = i; 
        }
        for (int i = 0; i < nums.size(); i++) { 
            if (mp.find(target- nums[i]) != mp.end()&&mp[target- nums[i]] != i){
                solution[0]=i+1;
                solution[1]=mp[target- nums[i]]+1;
                return solution;
            }
               
        }
         
        return solution; 
    }
};
