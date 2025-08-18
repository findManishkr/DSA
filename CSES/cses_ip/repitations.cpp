#include <bits/stdc++.h>
using namespace std;

void f( string s ){
  int N = s.size();
       
 
     int maxLen = 1;

       int i = 0;
     while( i < N ){
       int j = i;

       while( j < N && s[j] == s[i] ) j++;

       maxLen  = max( maxLen , j - i);

       i = j;
    
    }
       
     cout << maxLen <<'\n';
}

void  f2( string s){

         int ans = 1;
         int mx = 1;

    for( int i = 1; i < s.size(); i++){
          if( s[i] != s[i-1]) 
            ans = 1;
          else
            ans++;

           mx = max( mx, ans);  
          
    }
    
    cout << mx<<'\n';

}
int main(){
    string s;
    cin >> s;

        

    f(s);



    return 0;
}