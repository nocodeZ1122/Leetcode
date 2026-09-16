class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        bool down = true;

        for(char c : s)
        {
            rows[row] += c;

            if(row == 0)
                down = true;
            else if(row == numRows - 1)
                down = false;

            if(down)
                row++;
            else
                row--;
        }

        string ans;

        for(string x : rows)
            ans += x;

        return ans;
    }
};