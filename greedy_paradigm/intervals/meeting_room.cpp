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


 // Definition of Interval:
 class Interval {
 public:
     int start, end;
     Interval(int start, int end) {
         this->start = start;
         this->end = end;
     }
 };
 

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
            
            

               int N = intervals.size();

            sort( intervals.begin(),intervals.end(), [&]( const Interval &a , const Interval &b){
                if( a.end == b.end) return a.start < b.start;
                 return   a.end < b.end;
            } );

            for( int i = 1; i < N; i ++  ){
                 if( intervals[i-1].end > intervals[i].start)
                  return false;
            }
            
           return true;
    }
};


/*

  with out any conflict how would my answer look like 
 

   [prev even endtime <= curr event starttime] =>  [sort on the basis of endTime]
    [5,10] [15,20] [0,30]



*/

int main(int argc, char const *argv[]) { setupIO();



    return 0;
}