// Roman to INT

class Solution {
public:
    int romanToInt(string s) {
    int n =s.length();
        
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int ans = 0 ;
    for(int i = 0 ; i < n ; ++i){
        
        if(m[s[i]] < m[s[i+1]]){
            ans = ans +  m[s[i+1]] - m[s[i]];
            i = i  + 1;
            continue;
        }
        
        ans = ans + m[s[i]];
      }
        
        return ans;
        
        
        
    }
};



// INT TO ROMAN
class Solution {
public:
    const int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string intToRoman(int N) {
        string ans = "";
        for (int i = 0; N; i++)
            while (N >= val[i]) ans += rom[i], N -= val[i];
        return ans;
    }
};

