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
    ListNode* getnode(ListNode* temp, int k) {
        k -= 1;
        while (k > 0 && temp) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reversing(ListNode* temp) {
        ListNode* l1 = temp;
        ListNode* prev = nullptr;
        while (l1) {
            ListNode* curr = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = curr;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = nullptr;

        while (temp) {
            ListNode* nullpointer = getnode(temp, k);
            if (nullpointer == NULL) {
                if (prevlast) {
                    prevlast->next = temp;
                    break;
                }
            }
            ListNode* l1 = nullpointer->next;
            nullpointer->next = nullptr;
            ListNode* prev = reversing(temp);
            if (temp == head) {
                head = prev;
            } else {
                prevlast->next = nullpointer;
            }
            prevlast = temp;
            temp = l1;
        }
        return head;
    }
};