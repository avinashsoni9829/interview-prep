class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int id = 0;
        string s = "";
        while(1) {
            bool ok = 1;
            char c = '?';
            for(int i = 0; i < strs.size(); i++) {
                if(id < strs[i].size()) {
                    if(c == '?') {
                        c = strs[i][id];
                    }
                    else if(strs[i][id] != c) {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ok = 0;
                    break;
                }
            }
            id++;
            if(!ok) break;
            s += c;
        }
        return s;
    }
};

