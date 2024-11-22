#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1072. Flip Columns For Maximum Number of Equal Rows
int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {

    int numCols = matrix[0].size();
    int maxIdenticalRows = 0;

    for (vector<int> &currentRow : matrix) {
        vector<int> flippedRow(numCols);
        int identicalRowCount = 0;

        for (int col = 0; col < numCols; col++) {
            flippedRow[col] = 1 - currentRow[col];
        }

        for (vector<int> compareRow : matrix) {
            if (compareRow == currentRow || compareRow == flippedRow) {
                identicalRowCount++;
            }
        }

        maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
    }

    return 0;
}

int classic_sliding_window(vector<int> &nums, int k) {

    int left = 0, curr = 0, answer = 0;

    for (int right = 0; right < (int)nums.size(); right++) {
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left];
            left++;
        }
        answer = max(answer, right - left + 1);
    }
    cout << answer << endl;

    return 0;
}

int longest_binary_string() {

    string s = "1101100111";

    int answer = 0;
    int left = 0;
    int curr = 0;

    for (int right = 0; right < s.length(); right++) {
        // constraint metric
        if (s[right] == '0') {
            curr++;
        }

        // restriction: subarray is invalid if it has more than one 0
        while (curr > 1) {
            if (s[left] == '0') {
                curr--;
            }
            left++;
        }
        answer = max(answer, right - left + 1);
    }

    return 0;
}

int number_of_subarrays(vector<int> nums, int k) {
    if (k <= 1) {
        return 0;
    }
    int answer = 0, left = 0, curr = 1;

    for (int right = 0; right < (int)nums.size(); right++) {
        curr *= nums[right];
        while (curr >= k) {
            curr /= nums[left];
            left++;
        }
        answer = right - left + 1;
    }
    return answer;
}

int fixed_length_sliding_window(vector<int> nums, int k) {

    int curr = 0;

    for (int i = 0; i < k; i++) {
        curr += nums[i];
    }

    int left = 0;
    int ans = curr;
    for (int right = k; right < (int)nums.size(); right++) {
        curr -= nums[left];
        left++;
        curr += nums[right];

        ans = max(ans, curr);
    }

    // or alternatively removing leftmost element is going to be
    // nums[right-k] because K is always constant
    // for (int i = k; i < length; i++){
    //  curr += nums[i] - nums[i-k];
    //  ans = max(ans, curr)
    // }
    return ans;
}

int main(int argc, char *argv[]) {

    vector<int> nums = {4, 3, 1, 23, 5, 6, 756, 2, 3, 4, 21, 3, 4, 5, 6};
    vector<vector<int>> matrix = {{0, 1}, {1, 1}};
    maxEqualRowsAfterFlips(matrix);

    return 0;
}
