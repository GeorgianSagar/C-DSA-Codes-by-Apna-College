#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // stock Prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // solution
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for (int i = 0; i < price.size(); i++)
    {
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}