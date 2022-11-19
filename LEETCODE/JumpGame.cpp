#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0 or n == 1)
            return true;

        vector<bool> dp(n + 1, false);

        if (nums[0] > 0)
            dp[0] = true;

        for (int i = 1; i < n - 1; i++)
        {
            if (dp[i - 1] == true and nums[i] >= 1)
                dp[i] = true;
        }

        return dp[n - 2];
    }
};

/*
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int reach = 0;

        int curr_end = 0;
        for(int i =  0;i<n;i++)
        {
            reach = max(reach , nums[i]+i);

            if(i == curr_end)
                curr_end = reach;
        }

        return curr_end>=nums.size()-1;
        
    }
};
*/