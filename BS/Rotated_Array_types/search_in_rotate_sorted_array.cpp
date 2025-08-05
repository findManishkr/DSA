#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        



            int N = nums.size();  
         
             int lo = 0, hi = N -1;

              while( hi - lo >= 0){

                int mi = lo + ( hi - lo )/2;

                   if( nums[ mi ] == target ) return mi;

                if( nums[lo] <= nums[ mi] ){    // left part is sorted search in left partition 

                if(  nums[lo] <= target && target < nums[ mi]  ){

                    hi = mi - 1;
                }else{

                    lo = mi + 1 ;
                }






                }else{      // else, right part is sorted , search in the right part of the array
       
                   if( nums[mi] < target &&  target <= nums[hi] ){
                      lo = mi + 1 ;
                   }else
                     hi = mi -  1;

                }


              }

       return  -1 ;

    }
};

int main(){

    
    return 0;
}