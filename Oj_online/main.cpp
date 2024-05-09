#include <iostream>

using namespace std;
  struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;//仅有一个节点不翻转
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* preGroupEnd = &dummy;
        ListNode* currGroupStart = head;

        int count = 0;
        ListNode* curr = head;

        while (1) {
            ListNode* groupEnd = currGroupStart;
            for (int i = 1; i < k && groupEnd; i++) {
                groupEnd = groupEnd->next;
            }

            if (!groupEnd) {
                break;
            }

            preGroupEnd = reverse(preGroupEnd, groupEnd->next);
            currGroupStart = preGroupEnd->next;
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* prev, ListNode* next) {
        ListNode* prevNode = prev->next;
        ListNode* curr = prevNode->next;

        while (curr != next) {
            prevNode->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = prevNode->next;
        }

        return prevNode;

    }


};
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;
}
int main(void)
{
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for (int i = 2; i <= 5; i++) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }

    int k = 2;
    cout << "原序列:  ";
    printList(head);

    ListNode* reversedHead = sol.reverseKGroup(head, k);
    cout << "新序列： ";
    printList(reversedHead);


    return 0;
}