#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        int minRow = m, minCol = n;
        for (int i = 0; i < ops.size(); i++)
        {
            minRow = min(minRow, ops[i][0]);
            minCol = min(minCol, ops[i][1]);
        }
        return minRow * minCol;
    }
};