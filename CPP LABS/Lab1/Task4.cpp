#include <iostream>
#include <cstdlib>

int get_max_area(int *arr, int n) {
    int max_area = 0;

    for (int i = 0; i < n - 1; i++) { // Change the condition for i
        for (int j = i + 1; j < n; j++) { // Change the condition for j
            max_area = std::max(max_area, (j - i) * std::min(arr[i], arr[j]));
        }
    }

    return max_area;
}

int main() {
    int heights[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    std::cout << get_max_area(heights, 9) << std::endl;

    return 0;
}
