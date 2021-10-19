class Solution {
public:
    vector<string>ans;
    
    void helper(string op , int open ,int close)
    {
         if(open == 0  and close ==0){
              ans.push_back(op);
        }
        
         if(open!=0)
		 {
              
             string op1 = op;
             op1.push_back('(');
             helper(op1,open-1,close);
         }
         
             if(close > open){
                  string op2 = op;
                  op2.push_back(')');
                  helper(op2,open , close - 1);
                 
             }
    }
    
    
    vector<string> generateParenthesis(int n) {
      string op ="";
      helper(op,n,n);
      return ans;
     }
};
