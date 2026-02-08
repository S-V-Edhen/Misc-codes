#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         //find the next temp greater than the one you already have.
         //find the temp greater than the one at the top of your stack.
         //everytime you fail to find it, increment.
         int n = temperatures.size();
         stack<int> st;
         vector<int> res(n,0);
         for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
         }
         return res;
    }
};