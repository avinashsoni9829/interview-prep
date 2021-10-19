class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int n = words.size();
        
        set<int>super_set ;
        
        for(auto z:allowed){
            super_set.insert(z);
        }
        
        int ans = 0 ;
        
        for(auto z:words){
            bool wrong = false;
            for(auto k : z){
                  
                if(super_set.find(k)==super_set.end()){
                      wrong = true;
                    break;
                }
            }
            
            if(wrong == false){
                 ans = ans + 1;
            }
            
        }
        
        return ans;
        
        
    }
};
