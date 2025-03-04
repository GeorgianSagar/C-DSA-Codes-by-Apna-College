#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class with cycle detection and entry point finding
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }

        if (!isCycle)
            return NULL; // No cycle found

        // Reset slow to head and move both one step at a time
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow; // Cycle entry point
    }
};

// Function to create a linked list with a cycle
ListNode *createLinkedListWithCycle(vector<int> vals, int pos)
{
    if (vals.empty())
        return NULL;

    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    ListNode *cycleNode = NULL;

    for (int i = 1; i < vals.size(); i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;

        // Store the cycle connection point
        if (i == pos)
        {
            cycleNode = curr;
        }
    }

    // Create the cycle if pos is valid
    if (cycleNode)
    {
        curr->next = cycleNode;
    }

    return head;
}

int main()
{
    Solution sol;

    // Test case: head = [3,2,0,-4], pos = 1
    vector<int> vals = {3, 2, 0, -4};
    int pos = 1;

    ListNode *head = createLinkedListWithCycle(vals, pos);

    // Find the cycle entry point
    ListNode *cycleNode = sol.detectCycle(head);

    if (cycleNode)
    {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
