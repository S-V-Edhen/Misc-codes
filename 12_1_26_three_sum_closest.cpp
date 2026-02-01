#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //if(nums.size() <= 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long closestsum = INT_MAX;
        for(int i = 0; i < n; i++){
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return sum;
                if(abs(target - sum) < abs(closestsum - target)) closestsum = sum;
                if(sum > target) r--;
                else if(sum < target) l++;
            }
        }
        return closestsum;
    }
};