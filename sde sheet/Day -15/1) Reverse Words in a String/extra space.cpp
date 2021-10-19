class Solution {
    
    /*  O(n) with extra space */
public:
    string reverseWords(string s) {
        
        vector<string>st;
        int  n = s.length();
        string curr;
        for(int i = 0  ;i < n ; ++i)
        {
               
              if(s[i]==' ' )
              {
                   if(curr.length()>=1)
                   st.push_back(curr);
                  curr.clear();
                 
              }
             else
              if(s[i]!=' ')
              curr = curr + s[i]; 
             
        }
        if(curr.length() > 0)
        st.push_back(curr);
       string ans; 
        
       
        
        for(int i = st.size() - 1 ; i>=0;i--){
            ans+=st[i];
            if(i>0)
            ans+=" ";
        }
        
        return ans;
        
        
        
    }
};
