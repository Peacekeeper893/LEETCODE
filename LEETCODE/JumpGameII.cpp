#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}


class Solution {
public:
    int jump(vector<int>& nums) {

        int maxReachable = 0;
        int curr_end = 0;
        int jump = 0;

        for(int i =0;i<nums.size() - 1;i++)
        {
            maxReachable = max(maxReachable , nums[i]+i);

            if(curr_end == i)
            {
                curr_end = maxReachable;
                jump++;

            }
        }

        return jump;
        
    }
};