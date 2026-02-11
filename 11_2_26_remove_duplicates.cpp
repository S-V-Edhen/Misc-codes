#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string st = "";
        int n = s.size();
        vector<bool> used(26, false);
        vector<int> last(26);
        for(int i = 0; i < n; i++) last[s[i] - 'a'] = i;
        for(int i = 0; i < n; i++){
            if(used[s[i] - 'a']) continue;
            while(!st.empty() && st.back() > s[i] && last[st.back() -'a'] > i){
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(s[i]);
            used[s[i] - 'a'] = true;
            
        }
        return st;
    }
};