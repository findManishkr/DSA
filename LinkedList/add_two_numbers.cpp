/*
https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-100-liked

concept : linkedlist + adding two numbers strategy

*/

#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *temp = NULL, *ans;

        int carry = 0;

        while (l1 && l2) {

            int sum = l1->val + l2->val + carry;

            if (!temp) {

                temp = new ListNode(sum % 10);
                ans = temp;

            } else {

                temp->next = new ListNode(sum % 10);
                temp = temp->next;
                
            }

            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {

            int sum = l1->val + carry;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            carry = sum / 10;
            l1 = l1->next;
        }

        while (l2) {

            int sum = l2->val + carry;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            carry = sum / 10;
            l2 = l2->next;
        }

        if (carry > 0)
            temp->next = new ListNode(carry);

        return ans;
    }
};
int main(int argc, char const *argv[]) { 



    return 0;
}