#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int max1 = 0, max2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max1)
        {
            max2 = max1;
            max1 = v[i];
        }
        else if (v[i] > max2 && v[i] != max1) {
            max2 = v[i];
        }
    }

    int ans = max2 * max2;

    cout << "The answer is: " << ans;
}
