class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size() ; 
        int start1 = intervals[0][0] ; 
        int end1 = intervals[0][1] ; 
        vector<vector<int>> ans ; 
        for(int i = 1 ; i<n ; i++){
             int start2 =  intervals[i][0] ; 
             int end2 = intervals[i][1] ; 
             if(end1>= start2){
                end1 = max(end1 , end2) ; 
             }
                else{
                    ans.push_back({start1 ,end1}) ;
                    start1 = start2  ; 
                    end1 = end2 ;
                   
                } 
                 
        }
        ans.push_back({start1,end1}) ; 
        return ans  ; 
    }
};