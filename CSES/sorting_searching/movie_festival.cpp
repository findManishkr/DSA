/*
 https://cses.fi/problemset/task/1629/


*/


#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              emplace_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define mp              map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define F               first
#define S               second

#define loop(i,a,b)     for(int i=(a); i<(b); i++)
#define looprev(i,a,b)  for(int i=(a); i>=(b); i--)
#define all(x)          (x).begin(), (x).end()

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
bool cmp( vector <int>&a, vector<int>&b){
      if( a[1] ==  b[1]) return a[0] > b[0];
      return a[1] < b[1];
}

int f(   vector < vector <int>>&arr,int N){

    // sort the intervals on the basis of end time , end time are equal the sort on the basis of ( st1 > st2)
    
          sort( arr.begin(),arr.end(), cmp);

          int ans = 0, lastMovieEndTime = 0;
           loop(i,0, N){
                int startTimeCurrMovie = arr[i][0];

                if( startTimeCurrMovie >= lastMovieEndTime ){
                 ans++;    // i can see this movie, else not 

                // now update the lastMoiveEndTime, to ending time of curr movie
                 lastMovieEndTime = arr[i][1];
                }
           }
          
           return ans;
}
int main(int argc, char const *argv[]) { //setupIO();

 int N; cin >> N;
  vector < vector <int>>arr(N);

  loop(i,0,N){
       int a, b; 
       cin >> a>> b;
       arr[i] = {a,b};
  }

   cout << f(arr, N) <<'\n';

    return 0;
}