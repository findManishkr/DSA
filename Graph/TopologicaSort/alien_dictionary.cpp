/*

https://neetcode.io/problems/foreign-dictionary

concept : topological sorting + careful observation to find edge dependencies


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {

            string res ;       // ultimate answer
        
          // construct edges
             
              vector< vector < char >> edges;

           for( int i = 0; i < words.size()-1; i++){

                 string w1 = words[i], w2 = words[i+1];

                  if( w1.size() > w2.size() &&  w1.substr(0,w2.size()) == w2)
                    return "";      // violates prefix rule, that's why it has  exited early

                 for( int j = 0; j < min( w1.size(), w2.size()); j++){
                      if( w1[j] != w2[j] ){
                       edges.push_back( {w1[j], w2[j]});
                        break;
                      }
                 }
           }

           // now create adjacecy map
            unordered_map< char , list < char >> graph;
            unordered_map < char, int > indegree;

              // initialize graph, and indegree
               for( const string& str : words){
                     for( char ch : str ){
                         graph[ ch] = {};          // list <char>();     // or simply {}
                         indegree[ch] = 0;
                     }
               }

             for( auto x : edges){
                 char u = x[0], v = x[1];
                  graph[u].push_back( v);
                  indegree[v]++;
             }

             // adjaceny map created and indegree of each node is calculated

              // now use kahn's algo to find out ordering of the string 

              queue < char > q;
              // push the nodes with 0 indegree in queue

             for( auto it = indegree.begin(); it != indegree.end(); ++it)
                  if( ! (it->second) ) q.push( it->first );

                while( !q.empty()){
                 
                  char currNode = q.front(); q.pop();

                  // process currNode 

                      res.push_back( currNode);

                     for( char nbd : graph[ currNode ] )
                        if( !(--indegree[nbd]) ) q.push( nbd);
                     

                }   
             

             if( res.size() < indegree.size())    return "";

             return res;
    }
};



int main(){


    return 0;
}