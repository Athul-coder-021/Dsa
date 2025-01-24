#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int getTotalOfferPeriods(const std::vector<int>& sales) {
    int n = sales.size();
    int count = 0;

    // Iterate over each starting index `i`
    for (int i = 0; i < n - 2; ++i) {
        std::deque<int> maxDeque;  // To store indices of max elements for inner range [i+1, j-1]
        int minBoundary = sales[i];  // Initialize the minimum boundary as sales[i]

        // Iterate over each ending index `j`
        for (int j = i + 2; j < n; ++j) {
            minBoundary = std::min(minBoundary, sales[j]);

            // Maintain deque to get max in range [i+1, j-1]
            if (!maxDeque.empty() && maxDeque.front() < i + 1) {
                maxDeque.pop_front();  // Remove elements out of range
            }
            while (!maxDeque.empty() && sales[maxDeque.back()] <= sales[j - 1]) {
                maxDeque.pop_back();  // Maintain max elements in the range
            }
            maxDeque.push_back(j - 1);

            int maxMiddle = sales[maxDeque.front()];

            // Check if the offer period condition is satisfied
            if (minBoundary > maxMiddle) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    std::vector<int> sales = {3, 2, 8, 6};  // Example input
    std::cout << "Total Offer Periods: " << getTotalOfferPeriods(sales) << std::endl;
    return 0;
}
