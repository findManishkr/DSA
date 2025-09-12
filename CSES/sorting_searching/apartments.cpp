#include <bits/stdc++.h>
using namespace std;


#define loop(i,a,b) for( int i = (a); i < (b); i++)
#define all(x)  (x).begin(), (x).end()



void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(){ setupIO();

int n, m, k; 
cin >> n >> m >> k;

vector  <int> desired_size(n);
loop(i,0,n) cin >> desired_size[i];

vector <int>original_size(m);
loop(i,0,m) cin >> original_size[i];

sort( all(desired_size));
sort( all(original_size));

   int i = 0,j = 0,  cnt = 0;
   while( i < n && j < m){

       if( desired_size[i]  <= ( original_size[j] + k) && desired_size[i] >= ( original_size[j] - k)  )
          cnt++,i++,j++;
       else if( desired_size[i]  > ( original_size[j] + k)) j++;
       else if( desired_size[i] < ( original_size[j] - k) ) i++;

      
   }


    cout << cnt <<'\n';

    return 0;
}