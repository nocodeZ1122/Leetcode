class Solution {
public:
    int parent[26];

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Smaller character becomes parent
        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        // Initially every character is its own component
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        // Build equivalence classes
        for (int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';

            unite(a, b);
        }

        string ans;

        // Replace each character by smallest equivalent character
        for (char c : baseStr) {
            ans += char(find(c - 'a') + 'a');
        }

        return ans;
    }
};