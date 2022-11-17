#include<bits/stdc++.h>
using namespace std;


int main()
{
    printf("DONE");

    return 0;
}

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n + 1, -1);
        int res = nums[0];

        for (int i = 0; i < n; i++)
        {
            dp[i] = nums[i];
        }

        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i], dp[i - 1] + nums[i]);
            res = max(dp[i], res);
        }

        return res;
    }
};