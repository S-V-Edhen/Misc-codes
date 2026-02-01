#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        while(high >= low){
            int pX = low + (high - low)/2;
            int pY = (m + n + 1) / 2 - pX;
            
            int maxLX = (pX == 0)? INT_MIN : nums1[pX - 1];
            int minRX = (pX == m)? INT_MAX : nums1[pX];

            int maxLY = (pY == 0)? INT_MIN : nums2[pY - 1];
            int minRY = (pY == n)? INT_MAX : nums2[pY];

            if(maxLX <= minRY && maxLY <= minRX) return ((m + n) % 2 == 0)? (max(maxLX,maxLY) + min(minRX,minRY))/2.0 : max(maxLX, maxLY);
            else if(maxLX > minRY) high = pX - 1;
            else low = pX + 1;
        }
        return 0.0;
    }
};