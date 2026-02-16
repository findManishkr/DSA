/*


https://leetcode.com/problems/reverse-bits/?envType=daily-question&envId=2026-02-16


*/

#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


class Solution {
public:
    int BiStringToNum(string s) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (s[i] == '1')
                res += (1 << (31 - i));
        }
        return res;
    }
    string NumToBiString(int n) {

        string temp = "";

        for (int i = 31; i >= 0; i--) {
            // if ith bit is set , add '1' to string else add '0'

            if ((n & (1 << i)))
                temp += '1';
            else
                temp += '0';
        }
        return temp;
    }
    int reverseBits(int n) {

        string temp = NumToBiString(n);
        reverse(temp.begin(), temp.end());
        int ans = BiStringToNum(temp);

        return ans;
    }
};

/*

  # Method - 1

       1. convert `num` to string
       2. reverse the string
       3. convert string to `num` again

   # time complexity

   O(32) + O(32) + o(32) = O(96) = o(1)




*/


// write divide and conquer soluton also , 

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}