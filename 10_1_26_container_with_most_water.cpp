#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()- 1;
        int maxvol = 0;
        while(r > l){
            maxvol = max(((r - l) * min(height[r], height[l])), maxvol);
            if(height[r] > height[l]) l++;
            else r--;
        }
        return maxvol;

    }
};
int main(){
    cout<<"OK";
    return 0;
}