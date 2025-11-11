class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, right = k - 1;
        int white = 0, black = 0;
        for (int i = 0;i < k;i++) {
            if (blocks[i] == 'W') 
                white++;
            else 
                black++;
        }
        int ans = white;
        while (right < blocks.size() - 1 && ans != 0) {
            if (blocks[left] == 'W' && blocks[right + 1] == 'B') 
                white--;
            else if (blocks[left] == 'B' && blocks[right + 1] == 'W') 
                white++;
            left++;
            right++;
            if (white < ans) 
                ans = white;
        }
        return ans;
    }
};
