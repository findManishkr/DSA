/*

https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03

simple two pointer approach

*/


#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        int left = 0, right = 0, res = 0;

        while (left < n) {

            int sum = 0, maxi = 0;

            while (right < n && colors[left] == colors[right]) {
                sum += neededTime[right];
                maxi = max(maxi, neededTime[right]);
                right++;
            }

            res += (sum - maxi);
            left = right;
        }

        return res;
    }
};

int main(int argc, char const *argv[]) { 


    return 0;
}