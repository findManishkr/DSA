/*
https://cses.fi/problemset/task/1619



*/

/*

  method 1  : using sweep line algorithm
   

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

int f(  vector < vector < int>>& arr,int N){

    vector < vector < int>>Event;      // stores the start and end time of movie
    // create event for all arrivals and departures [ +1 : start , -1: end]

     loop(i,0,N){
         int st_time = arr[i][0];
         int en_time = arr[i][1];

         Event.push_back( {st_time, 1})  ;     // + 1 : start
         Event.push_back( {en_time,-1})  ;      // -1 : end  
     }


      // sort event  arr on the basis of time, if time are equal ,sort by the this rule ( -1 should come first than + 1)

       sort(Event.begin(),Event.end());
           
           int MaxNoMovie = 0, CurrNoMovie = 0;
        for( auto x : Event){
             CurrNoMovie +=  x[1];
             MaxNoMovie = max( MaxNoMovie, CurrNoMovie);
        }

        return MaxNoMovie ;

}
int main(int argc, char const *argv[]) {// setupIO();
  
     int N; cin >> N;
      vector < vector < int>> arr(N);    // contains start  and end time of each movie
       loop( i, 0, N){
           int a, b;
           cin >> a>> b;
           arr[i] = {a,b};
       }


   cout << f(arr, N) << endl;

    return 0;
}