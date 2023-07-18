int countStudents(vector<int> &arr, int pages)
{
    int students = 1;
    long long totalpages = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (totalpages + arr[i] <= pages)
        {
            totalpages = totalpages + arr[i];
        }
        else
        {
            students++;
            totalpages = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}