

#include <iostream>
#include <vector>
using namespace std;

//vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//    vector<int> result;
//
//    // For each element in nums1
//    for (int i = 0; i < nums1.size(); i++) {
//        int num = nums1[i];
//        int nextGreater = -1; // default if no greater is found
//
//        // Find where num is in nums2
//        for (int j = 0; j < nums2.size(); j++) {
//            if (nums2[j] == num) {
//                // Look to the right of nums2[j] for next greater
//                for (int k = j + 1; k < nums2.size(); k++) {
//                    if (nums2[k] > num) {
//                        nextGreater = nums2[k];
//                        break;
//                    }
//                }
//                break; // stop after we locate num in nums2
//            }
//        }
//
//        result.push_back(nextGreater);
//    }
//
//    return result;
//};

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    vector<int> result;

    for (int num : nums1) {// iterate over nums1 using range-based for loop

        int nextGreater = -1; // default if no greater is found
        bool found = false;

        for (int n : nums2) { // iterate over nums2

            if (found && n > num) { // once we found the num in nums2, check for next greater
                nextGreater = n;
                break;
            }

            if (n == num) {
                found = true; // mark that we've found num in nums2
            }

        }

        result.push_back(nextGreater);
    }

    return result;
}

int main() {

    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };


    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Result: ";

    /*for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl; cout << endl;*/

    for (int n : result) {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}

