#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){ //we go over eac element twice, element at the top is compared against the current element, if the condition checks, it's price is adjusted.
                prices[st.top()] -= prices[i]; //adjust price
                st.pop(); //once adjusted, the index is removed from the stack.
            }
            st.push(i); //push elements into the stack
        }
        return prices;
    }
};