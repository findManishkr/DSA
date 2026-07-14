/*

 https://codeforces.com/problemset/problem/1420/B

 concept : basic bit observation


*/


#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

#define ll long long

int main(){   setupIO();
 int t ; cin >> t; // no of test case


    while(t--){

       int n; cin >> n; // length of the arr
       vector<int> arr(n); // arr declaration
       for( int i = 0; i < n; i++) cin >> arr[i];   // taking input , of array el

       vector< ll >farr(31, 0);  // freq arr to store the count of every msb pos lieing b/w [0,31] 

        

           
             for( int i = 0; i < n; i++ ){
                for( int bitpos = 30; bitpos >= 0; bitpos--){

                   if( arr[i] & ( 1LL << bitpos)){    // to chek whether which is msb pos
                       farr[bitpos]++;
                       break;
                   }

             }

        }

        /*
            elemensts of the array , that having same msb pos
            will satisfy this property  ( a & b) > ( a ^ b)

            say [8, 9, 10 ,11]  having msb pos = 3 ( 0 based)

            so total no of pairs  = ( 4c2)
               4 * (4 - 1 ) / 2 = 4 * 3 = 12 / 2 = 6;
        
        
        */

        ll res = 0;

        for( int i = 0; i < 31 ; i++)
        res += ( 1ll*farr[i] * (1ll*farr[i] -1ll) )/2;


        cout << res <<'\n';


    }







    return 0;



}


/*

    observation:
        say, msb_pos( a[i] )  = k
             msb_pos(b[j])     = k;      and both are equal [ie (1,1)  or (0,0)]

              then 
                  a&b >= ( a ^b)

         else 
             a & b < ( a ^b)         



*/


/*
   time complexity: O(N) * O(31) / testcase
   space complexity : O(31)     // can be reduced to O(1)









*/



/*

  summ. of n over all test case        <= 1e5

     so in worst case , say n = 1e5 for particular test case 

     t = 1, n = n1
     t = 2, n = n2 
     .
     .
     t = t, n = nt

       n1 + n2  + n3 ... nt <= 1e5    f(n) =  sum(n)  =>  f(n) <= 1e5

       so , in worst case , for all test cases to process, 1e5 this much time is going to be spend







*/