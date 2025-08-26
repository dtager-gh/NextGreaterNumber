// NextGreaterNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        // For each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int nextGreater = -1; // default if no greater is found

            // Find where num is in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    // Look to the right of nums2[j] for next greater
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > num) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    break; // stop after we locate num in nums2
                }
            }

            result.push_back(nextGreater);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Result: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
