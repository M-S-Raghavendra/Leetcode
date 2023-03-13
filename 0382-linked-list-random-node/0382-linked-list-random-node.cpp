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
private:
    ListNode* head;
    vector<int> a;
    int n;
public:
    Solution(ListNode* head) {
        this->head = head;
        for(ListNode* cur=head;cur!=NULL;cur=cur->next)
        {
            a.push_back(cur->val);
        }
        n = a.size();
    }
    
    int getRandom() {
        int index = rand()%n;
        return a[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */