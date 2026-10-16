class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini =  prices[0] ; 
        int n  = prices.size() ; 
        int profit = 0 ;  
        for(int i = 0 ; i<n ; i++ ){ 
            profit = max(profit , prices[i] - mini) ;
            mini = min(mini , prices[i]) ;
        
        }
        return profit ;
    }
};