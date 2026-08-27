 class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        priority_queue<int> left;

        priority_queue<int, vector<int>, greater<int>> right;

        for(int x : nums1)
        {
            if(left.empty() || x <= left.top())
                left.push(x);
            else
                right.push(x);

            if(left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }

            else if(right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
        }

        for(int x : nums2)
        {
            if(left.empty() || x <= left.top())
                left.push(x);
            else
                right.push(x);

            if(left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }

            else if(right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
        }

        if(left.size() == right.size())
        {
            return (left.top() + right.top()) / 2.0;
        }

        return left.top();
    }
};