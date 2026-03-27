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

class Solution1 {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
            /*
            
                time complexity: O(N^2) due to 2 loops
            
            
            */
                   
                int n = times.size();

                vector<int>chairs(n, -1);
                vector<int> ans(n,0);

                for( int i = 0; i < n; i++)
                 times[i].push_back(i);


                 auto lambda = [&]( const vector<int>&a, vector<int>&b){
                           return a[0] < b[0];
                 };
                 sort( times.begin(), times.end(), lambda );

                   for( int i = 0; i < n; i++){
                      int arr = times[i][0];
                      int dep = times[i][1];
                      int idx = times[i][2];

                      for( int j = 0; j < n; j++){
                          if( chairs[j] == -1 || chairs[j] <= arr){
                            chairs[j] = dep;
                            ans[idx] = j;
                            break;
                          }
                      }




                   }
            return ans[targetFriend];    
    }
};

/*


*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}