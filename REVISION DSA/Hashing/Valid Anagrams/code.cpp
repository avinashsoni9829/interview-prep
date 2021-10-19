class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char,int>mp1,mp2;
        
        for(auto z:s) mp1[z]++;
        for(auto z:t) mp2[z]++;
        
        for(auto k : mp1)
        {
           if(mp1[k.first]!=mp2[k.first]) return false;  
        }
        
          for(auto k : mp2)
        {
           if(mp1[k.first]!=mp2[k.first]) return false;  
        }
        
        return true;
        
    }
};
