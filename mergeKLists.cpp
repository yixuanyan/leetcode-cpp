#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution1 //二分
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list = new ListNode();
        ListNode *list_head = list;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                list->next = list2;
                list2 = list2->next;
            }
            else
            {
                list->next = list1;
                list1 = list1->next;
            }
            list = list->next;
        }
        list->next = list1 == nullptr ? list2 : list1;
        return list_head->next;
    }
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid, r));
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) //递归二分 空间复杂度O(logk)
    {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode *mergeKLists1(vector<ListNode *> &lists) //循环二分 原地修改空间O(1)
    {
        if (lists.size() == 0)
            return NULL;
        const int l = lists.size();
        for (int step = 1; step < l; step *= 2)
        {
            for (int i = step; i < l; i += 2 * step)
            {
                lists[i - step] = mergeTwoLists(lists[i - step], lists[i]);
                lists[i] = NULL;
            }
        }
        return lists[0];
    }
};
class Solution //优先队列
{
public:
    struct Status
    {
        int val;
        ListNode *ptr;
        bool operator<(const Status &temp) const
        {
            return val > temp.val;
        }
        /* data */
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head, *tail = head;
        priority_queue<Status> q;
        for (auto node : lists)
        {
            q.push({node->val, node});
        }
        while (!q.empty())
        {
            auto t = q.top();
            q.pop();
            tail->next = t.ptr;
            tail = tail->next;
            if (t.ptr->next)
            {
                q.push({t.ptr->next->val, t.ptr->next});
            }
        }
        return head->next;
    }
};
int main()
{
    Solution sol;
    // ListNode *l1 = new ListNode(3);
    // l1 = new ListNode(4, l1);
    // l1 = new ListNode(2, l1);
    // ListNode *l2 = new ListNode(9);
    // l2 = new ListNode(6, l2);
    // l2 = new ListNode(5, l2);
    // ListNode *head = sol.addTwoNumbers(l1,l2);
    // while (head!= nullptr)
    // {
    //     /* code */
    //     cout<<" "<<head->val<<endl;
    //     head= head->next;
    // }

    // string s="cbbd";
    // cout<<sol.longestPalindrome(s)<<endl;

    // int a[5] = {1,2,3,2,1};
    // vector<int> height(a,a+5);
    // cout<<sol.maxArea(height)<<endl;

    // string a[5] = {"1234","asd","1sa","122","1ew"};
    // vector<string> height(a,a+5);
    // cout<<sol.longestCommonPrefix(height)<<endl;

    // int a[6] = {-1,0,1,2,-1,-4};
    // vector<int> height(a,a+6);
    // vector<vector<int> > ans = sol.threeSum(height);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for(int j = 0; j < ans[0].size(); j++)
    //         cout << ans[i][j] << " ";
    //     cout << endl;
    // }

    // int a[3] = {0,1,2};
    // vector<int> height(a,a+3);
    // cout<<sol.threeSumClosest(height,0)<<endl;

    // cout << sol.isValid("((") << endl;

    // ListNode *l1 = new ListNode(4);
    // // l1 = new ListNode(2, l1);
    // // l1 = new ListNode(1, l1);
    // ListNode *l2 = new ListNode(4);
    // // l2 = new ListNode(3, l2);
    // // l2 = new ListNode(1, l2);
    // ListNode *ans = sol.mergeTwoLists(l1, l2);
    // while (ans != nullptr)
    // {
    //     cout << ans->val << " #" << endl;
    //     ans = ans->next;
    // }
}