// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_length = 0;
        ListNode* current_node = head;
        while (current_node) {
            current_node = current_node->next;
            list_length++;
        }
        current_node = head;
        
        if (list_length == 1) {
            delete head;
            head = nullptr;
        }
        else {
            // assign current node as the previous of the removed one
            for (int i = 0; i < list_length - n - 1; i++) {
                current_node = current_node->next;
                
            }
            
            // if element to be removed is the head
            if (n == list_length) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            } 
            else if (n == 1) {  // if the element to be removed is the tail
                ListNode* temp = current_node->next;
                delete temp;
                current_node->next = nullptr;
            }
            else {              // if the element to be removed is somewhere in the middle 
                ListNode* temp1 = current_node->next;
                ListNode* temp2 = temp1->next;
                delete temp1;
                current_node->next = temp2;
            }
        }     
        return head;
    }
};