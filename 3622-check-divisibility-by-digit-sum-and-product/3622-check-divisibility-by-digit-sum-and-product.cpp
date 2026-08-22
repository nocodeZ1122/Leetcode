class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ; 
        int prod =1 ; 
        int digit =0;
        int dummy=n;

        while(n){
            digit = n%10 ; 
            n = n/10 ; 
            sum =sum+ digit ;
            prod =prod* digit ;
        }
        int x = sum + prod ;
        if( dummy % x == 0){
            return true; 
        }
        else{
        return false ;
        }
    }
};