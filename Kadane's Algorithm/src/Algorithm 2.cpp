#include <bits/stdc++.h>
using namespace std;

int maxSubSum(int array[], int n)
{
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = max(best,sum);
        }
    }
    return best;
}

int main()
{
    int array[] =  {-3, 1, -8, 12, 0, -3, 5, -9, 4};
    int n = sizeof(array) / sizeof(array[0]);
    int max = maxSubSum(array, n);
    cout << "Maximum Sub-Array Sum: " << max;
    return 0;
}
