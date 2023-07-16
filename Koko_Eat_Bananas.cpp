#include <bits/stdc++.h>
int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int Hours)
{
    int totalHours = 0;
    for (int i = 0; i < v.size(); i++)
    {
        totalHours += ceil((double)v[i] / (double)Hours);
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1, high = findMax(v);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalHour = calculateTotalHours(v, mid);
        if (totalHour <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}