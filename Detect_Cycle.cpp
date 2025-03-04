#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class with cycle detection
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
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

    // Check if the linked list has a cycle
    if (sol.hasCycle(head))
    {
        cout << "Cycle detected in the linked list." << endl;
    }
    else
    {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
