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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeKListsDFS(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKListsDFS(vector<ListNode*>& lists, int l, int r) {
        if (l >= r) {
            return lists[l];
        }

        int mid = (l + r) / 2; 
        ListNode* left = mergeKListsDFS(lists, l, mid);          // 注意这里不能是 这一行mid-1，下一行mid
        ListNode* right = mergeKListsDFS(lists, mid + 1, r);
        ListNode head;
        ListNode* cur = &head;
        while (left && right) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        if (left != nullptr) {
            cur->next = left;
        }

        if (right != nullptr) {
            cur->next = right;
        }

        return head.next;
    }
};