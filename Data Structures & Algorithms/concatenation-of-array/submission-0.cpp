class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.size() * 2);
        int idx = 0;
        for(int i = 0; i < nums.size(); i++) res[idx++] = nums[i];
        for(int i = 0; i < nums.size(); i++) res[idx++] = nums[i];
        return res;
    }
};