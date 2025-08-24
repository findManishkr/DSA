/*
https://leetcode.com/problems/max-consecutive-ones-iii/description/

concept : variable size window 


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int longestOnes(vector<int>& nums, int k) {
    int N = nums.size();
    int L = 0, R = 0;
    int cntz = 0;
    int MaxLen = 0;

    while (R < N) {
        if (nums[R] == 0) {
            cntz++;
        }

        // Shrink the window if zero count exceeds k
        while (cntz > k) {
            if (nums[L] == 0) {
                cntz--;
            }
            L++;
        }

        // Update maximum length of the window
        MaxLen = max(MaxLen, R - L + 1);

        R++;
    }

    return MaxLen;
}

};

int main(){



    return 0;
}