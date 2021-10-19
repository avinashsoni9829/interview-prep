class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        
        stack<char>st;
        st.push('*');
        for(int i = 0 ; i < n ; ++i)
        {
              if(st.empty() and (s[i] == ')' or s[i] == '}' or s[i] == ']'))
                  return false;
              
              if(st.empty())
              {
                  // opening bracket will be there 
                  
                  st.push(s[i]);
              }
              else
              {
                   if(s[i] == ')')
                   {
                      if(st.top() == '(')
                      {
                        st.pop();   
                      }
                       
                   }
                  else
                      if(s[i] == '}')
                      {
                          if(st.top() == '{')
                      {
                        st.pop();   
                      }
                           
                      }
                  else
                      if(s[i] == ']')
                      {
                         if(st.top() == '[')
                      {
                          st.pop();   
                      }
                      }
                  else
                  st.push(s[i]);
              }
            
            
            
          
        }
        
        
            return st.size() - 1  > 0 ? false  : true ;
        
    }
};
