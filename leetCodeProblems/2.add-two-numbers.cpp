/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummyHead(0);    // 先做一个虚拟头结点，回头输出他的next
        ListNode *p = &dummyHead; // 做一个指向头结点的指针p。
        int sum = 0;
        while (l1 != NULL || l2 != NULL || sum > 0)
        {
            if (l1 != NULL)
            {
                sum += l1->val; // l1->val，返回l1指针指向的某一结点内储存的值
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(sum % 10); // 申请新的结点。
            p = p->next;
            sum /= 10;
        }
        return dummyHead.next;
    }
};
// @lc code=end
