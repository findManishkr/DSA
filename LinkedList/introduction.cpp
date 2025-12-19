/*

 https://leetcode.com/problems/design-linked-list/description/

*/


#include <bits/stdc++.h>
using namespace std;


class Node {
public:

int val;
Node* next;

Node( int x) : val(x), next(NULL) {};

};
class MyLinkedList {
public:
    // linked list data structure
    Node* head;
    int size;

    MyLinkedList() {
        head = NULL;  // ie it does not point to any node yet ie “Currently, the linked list is empty — no nodes are present.”
        size  = 0;
    }
    
    int get(int index) {
         // invalid case
         if( index < 0 || index >= size) return -1;

         // invalid case handled , now handle valid case 

         Node *curr = head ;

         for( int i = 0; i < index; i++)
            curr = curr->next;

            return curr->val;
    }
    
    void addAtHead(int val) {
         
         Node* newNode = new Node( val );

         newNode->next = head;
         head = newNode;

         size++;

        
    }
    
    void addAtTail(int val) {


       if( size == 0){

          addAtHead(val);
           return ;
        
       }else{

        Node* newNode = new Node(val);

        Node* curr = head;

        while( curr->next ){ 

        curr = curr->next;  

        }  

        curr->next = newNode;
        size++; 
       };
            
        
    }
    
    void addAtIndex(int index, int val) {

             if( index < 0 || index > size) return ;

           

             if( index == 0 ){
              addAtHead( val);
             }else if( index == size ){
                addAtTail( val);
             }else{

            Node* newNode = new Node( val);
            Node* curr = head;
               
                 for( int i = 0; i < index - 1; i++ )
                     curr = curr->next;

                    newNode->next = curr->next;
                     curr->next = newNode ;
                    
                     size++;
                 }

                

    }

    void deleteAtIndex(int index) {

        if(  index < 0 || index >= size ) return ;

        if (index == 0) {

            Node* temp = head;
            head = head->next;
            delete temp;
            
        }else {

           Node* curr =  head;

         for( int i = 0; i < index - 1; i++)
              curr = curr->next;

         //. now currnet pointer points to the index before the node to be deleted   
           Node* temp = curr->next;

            curr->next = curr->next->next;
         delete temp;

        }
         size--;  



        
    }


};


int main(int argc, char const *argv[]) { 



    return 0;
}