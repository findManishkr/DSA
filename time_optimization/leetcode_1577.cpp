#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define all(x)          (x).begin(), (x).end()


// optimized form tc O(N^3 ) to O(N^2) using extra auxiliary space ( ie unordered_map)


#define ll long long 
class Solution {
public:
    int f(vector<int>& nums1, vector<int>& nums2 ){
             int M = nums1.size(),  N = nums2.size();
               unordered_map < ll , ll > fm;


                 for( int i = 0; i < M; i++){
                    for( int j = i+1; j < M; j++){

                         ll prod = 1LL * nums1[i] * nums1[j];
                         fm[ prod]++;
                    }
                 }


                 int res = 0;

                 for( int i = 0; i < N; i++){
                     
                     ll sq = 1LL * nums2[i] * nums2[i]; 

                     if( fm.count( sq) ){
                        res += fm[sq];
                     }
                    
                       
                 }



     return res;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        

        int ans = 0;
        ans += f( nums1, nums2);
        ans += f( nums2, nums1);

        return ans;
    }
};

int main(int argc, char const *argv[]) { 



    return 0;
}