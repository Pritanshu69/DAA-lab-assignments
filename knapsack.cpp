#include<iostream>
#include<vector>    
#include<algorithm>
using namespace std;

struct  Item
{
    int value;
    int weight;
};

int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}
// Test the function with an example
int main() {
    int capacity, numItems;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }

    int maxTotalValue = knapsack(capacity, items);

    cout << "The maximum total value that can be put in the knapsack is: " << maxTotalValue << endl;

    return 0;
}