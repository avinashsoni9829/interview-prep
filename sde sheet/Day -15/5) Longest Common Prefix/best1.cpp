class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            int j;
            for (j = 1; j < strs.size(); j++) {
                if (strs[j].size() < i || strs[j][i] != ch) {
                    break;
                }
            }
            //std::cout << j << ", " << strs.size() << std::endl;
            if (j == strs.size()) res.push_back(ch);
            else break;
        }
        return res;
    }
};
