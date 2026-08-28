class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int low = 0 ; 
        int high = 0 ; 
        int n = s.size() ;
        int ans = 0 ;
        int len = 0 ; 
        unordered_map<char,int> mp ; 
        for(high =0 ; high<n; high++){ 
            mp[s[high]]++ ; 
            while(mp[s[high]]>1){
                mp[s[low]]-- ; 
                if(mp[s[low]]==0){
                    mp.erase(s[low]) ; 
                }
                low++ ; 
            }
              len = high - low +1;
            ans = max(ans , len) ;

        }
          return ans  ; 
 
    }
};