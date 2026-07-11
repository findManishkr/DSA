/*
https://leetcode.com/problems/neighboring-bitwise-xor/

concept : xor properties


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
    bool doesValidArrayExist(vector<int>& derived) {

        /*

          # Time complexity
            - a single for loop 

            TC = O(N) | where N is the len of `derived ` array
            SC = O(1) : as no extra space is used
        */
            
                 int res = 0;

                 for( int el : derived)
                 res ^= el;

                 return (!res);
    }
};


/*
   
  # example 
     n = 4 , derived = [............]
           
     say , original = [a1, a2, a3 , a4] 

       derived[1] = a1 ^ a2
       derived[2] = a2 ^ a3
       derived[3] = a3 ^ a4
       derived[4] = a4 ^ a1

       so derived = [a1 ^ a2,  a2 ^ a3,  a3 ^ a4, a4 ^ a1 ]

          each element occuring twice , hence  we know that by xor properties

         # Xor properties
           a ^ a = 0;

          so  cummulative xor of all the array elements must be zero 


           





*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}