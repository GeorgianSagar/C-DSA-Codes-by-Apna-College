#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Function to create a linked list from an array
ListNode *createLinkedList(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}; // Input list
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode *head = createLinkedList(arr, size);

    // Find the middle node
    Solution sol;
    ListNode *middle = sol.middleNode(head);

    // Print the middle node and onward
    cout << "Middle Node and onward: ";
    printLinkedList(middle);

    return 0;
}
