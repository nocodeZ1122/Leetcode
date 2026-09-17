class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0 ; 
        int high = height.size() - 1;  
        int area = 0 ; 
        int ans =0 ; 
        while(low<high){
            if(height[low]<height[high]){
                area = height[low]*(high - low  ) ;
                ans = max(ans,area) ; 
                low++; 
            }
            if(height[low]>height[high]){
                area = (high - low )*height[high] ;  
                ans = max(area,ans) ; 
                high -- ; 
            }
            if(height[low] == height[high]){
                area = height[low]*(high -low) ;
                ans = max(area , ans) ; 
                low++ ; 
                high -- ; 
            }

        }
        return ans ; 
        
    }
};