#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 1; i < n; i = i + 2)
        {
            nums[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};