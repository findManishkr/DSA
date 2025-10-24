/*

 modulo inverse of `a ` under modulo `m` is `b`

 then  =>   ( a * b ) % m = 1;

 modular inverse(b) exists if gcd(a,m) = 1, ie a and m are co-prime

 if `m is prime number and a is not divisible by m 
     a^(m-1) % m = 1;`

     then 

     a^(m-2) % m = a^-1




*/



#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;     // mod is a prime number

// fast explonatiation
                    // ( a ^ b) % mod

ll power(ll a, ll b , ll m = mod){

  ll res = 1;

     a %= m;

   while( b > 0 ){

    // if b is odd
       
    if( b & 1){
        res = (res * a) % m;
    }

     a = ( a * a) % m;

        b >>= 1;


   }
return res;

}

ll modInverse( ll a, ll m = mod){



  return power(a, m-2,m);
}

int main(){




 cout <<  modInverse(3, 11) <<' ';    // output 4




    return 0;
}