// count subsequences of type  a ^i b^ j c ^ k

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
       long long int  a = 0;
       long long int ab = 0 ;
       long long int abc = 0;
       long long int n = s.length();
       
       const long long int modu = 1e9  + 7;
       for(int i = 0 ; i  < n ; ++i){
            
            if(s[i] == 'a'){
                a = 2 * a + 1; 
                a%=modu;
            }
            else
            if(s[i] == 'b'){
                 ab = 2 * ab + a;
                 ab%=modu;
            }
            else
            {
                abc = 2 * abc + ab;
                abc%=modu;
            }
       }
       
       return abc%modu;
       
       
    }
};
