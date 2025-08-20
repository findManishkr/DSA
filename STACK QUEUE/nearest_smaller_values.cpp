/*

https://cses.fi/alon/task/1645/


*/


#include <bits/stdc++.h>
using namespace std;

vector <int> nearsest_smaller_values( vector<int>&arr, int n){

    vector<int>res(n+1);
       stack< int> st;
    for( int i = 1; i <=n; i++){

         while( !st.empty() && arr[ st.top() ] >= arr[i])
           st.pop();
       
            res[i] = st.empty() ?  0 : st.top();
              st.push( i);

    }


    return res;
}
int main(){


int n; cin >> n;
vector< int>arr(n + 1);
for( int i = 1; i <=n; i++ ) cin >> arr[i];

vector<int>ans = nearsest_smaller_values(arr,n);


for( int i = 1; i <=n; i++)
  cout << ans[i] <<' ';




    return 0;
}