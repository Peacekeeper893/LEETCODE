#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*

    Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

    */

    return 0;
}

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        vector<int> res;
        stack<pair<int, int>> st; // {value , index}
        int n = temperatures.size();
        res.push_back(0);
        st.push({temperatures[n - 1], n - 1});

        for (int i = n - 2; i >= 0; i--)
        {
            auto p = st.top();

            int p1 = p.first;  // val;
            int p2 = p.second; // index;

            if (p1 > temperatures[i])
            {
                st.push({temperatures[i], i});
                res.push_back(1);
            }
            else
            {
                while (st.empty() == false and st.top().first <= temperatures[i])
                    st.pop();

                if (st.empty() == true)
                    res.push_back(0);
                else
                {
                    auto p = st.top();
                    res.push_back(p2 - i);
                }
                st.push({temperatures[i], i});
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};