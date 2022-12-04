#include<bits/stdc++.h>
using namespace std;


int main()
{
    

    return 0;
}
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        vector<long long> runningsum;
        long long sum = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            runningsum.push_back(sum);
        }

        vector<long long> diff;

        for (int i = 0; i < n;i++)
        {
            if(n - i -1 > 0 )
                diff.push_back(abs((runningsum[i] / (i + 1)) - (sum - runningsum[i]) / (n - i - 1)));
            else
                diff.push_back(abs((runningsum[i] / (i + 1)) ));
        }

        long long min_so_far = LONG_MAX;
        int res = n-1;

        for (int i = n - 1;i>=0 ; i--)
        {
            if(diff[i] <= min_so_far)
            {
                min_so_far = diff[i];
                res = i;
            }
        }
        return res;
    }
};