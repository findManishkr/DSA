/*

https://leetcode.com/problems/corporate-flight-bookings/description/

concept : diff array technique

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            

            

               vector <int> diff(n + 1, 0);
                 for( auto x :  bookings ){
                    int l = x[0] - 1, r = x[1] -1, seats = x[2];         // ( in idexes l and r substracted -1 to manipulate them from one based indexing to 0 based indexing )
                       diff[l] += seats;
                       diff[r+1] -= seats;
                 }
               
               // now take prefix sum of difference arr from index [0, n-1];

                for( int i = 1; i < n; i++)
                diff[i] = diff[i] + diff[i-1];

                // now remove nth inedx element ie pop_back
                diff.pop_back();


         return diff;
    }
};

/*
     `problem is straight forward on diffarray trick`


*/

int main(){



    return 0;
}