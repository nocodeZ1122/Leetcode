class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length() ; 
        unordered_map<char,int> q ; 
        int ans  =0 ; 
        for(int i =0 ; i<len ;i++){ 
            q[s[i]] ++ ;
        }
        for(int i = 0 ; i<len ;i++ ){ 
            if(q[s[i]] == 1){ 
                return i ; 
                break ; 
            }
          
        }
        return -1 ;
        
    }
    
};