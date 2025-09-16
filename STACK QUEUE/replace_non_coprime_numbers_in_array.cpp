/*
https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16


 concept : greedy + stack + observation 

*/



#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            while (!st.empty() && gcd(st.top(), x) > 1) {

                x = lcm(st.top(), x);
                st.pop();
            }

            st.push(x);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){


    return 0;
}