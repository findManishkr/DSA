/*

https://leetcode.com/problems/course-schedule-ii/description/

topic : topological sorting 

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector < vector <int>>graph;
     vector <int> TopoSort( int n ){

               vector < int> answer;   // answer to be return 

         vector <int> indegree( n, 0);
        for( int i = 0;i < n; i++) {
          for( int nbd : graph[i])
              indegree[nbd]++;
          }


          queue < int> q; 

          for( int i = 0;i <n; i++)
         if( !indegree[i] ) q.push(i);
          
         while( !q.empty() ){

            int node = q.front(); q.pop();

              // process node 
               answer.push_back( node);

              for( int nbd : graph[node]){
                 if( !( --indegree[nbd]) ) q.push( nbd);
              }

         }  


            if( answer.size() < n) return {};
        return   answer;
     }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         
            graph.clear();   graph.resize(numCourses, vector<int>());

           for( auto x : prerequisites){
              int u = x[0], v = x[1];
               graph[v].push_back(u);
           }

           return TopoSort(numCourses);
    }
};

int main(){





    return 0;
}