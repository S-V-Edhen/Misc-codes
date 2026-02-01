#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            //iterate over numbers one by one
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            //for that number (nums[i]) we find combinations that work
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) r--;
                else if (sum < 0) l++;
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    //now since we can have repetitions, we move on until e encounter the same number. these 2 while loops, remove things from the upper loop. so it stays O(N^2) despite having two loops
                    while(l < r && nums[r] == nums[--r]);
                    while(l < r && nums[l] == nums[++l]);
                }
            }
        }
        return res;
    }
};