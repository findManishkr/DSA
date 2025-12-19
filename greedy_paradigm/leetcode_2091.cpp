/*
https://leetcode.com/problems/removing-minimum-and-maximum-from-array/


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
    int minimumDeletions(vector<int>& nums) {

        int N  = nums.size();


        int idx1 = min_element( nums.begin(),nums.end()) - nums.begin();
        int idx2 = max_element( nums.begin(),nums.end()) - nums.begin();

        if( idx1 > idx2)
        swap(idx1,idx2);


        return  min( {idx2 + 1, N - idx1 , idx1+1 + N - idx2});
        
    }
};

/*
  this is clean code

  there were three possible answers , res was min of all threee

*/

/*
`problel statement paraphrasing`

1. arr of dist. el is given
2. del -> either removing el from front or back


`return`-> min no of del ops to remove both maxi and mini

lets see testcases

[2,10,7,5,4,1,8,6]        clearly mini = 1(5) , maxi = 10(1)


*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}