

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
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

//vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//
//    vector<int> result;
//
//    for (int num : nums1) {// iterate over nums1 using range-based for loop
//
//        int nextGreater = -1; // default if no greater is found
//        bool found = false;
//
//        for (int n : nums2) { // iterate over nums2
//
//            if (found && n > num) { // once we found the num in nums2, check for next greater
//                nextGreater = n;
//                break;
//            }
//
//            if (n == num) {
//                found = true; // mark that we've found num in nums2
//            }
//
//        }
//
//        result.push_back(nextGreater);
//    }
//
//    return result;
//}



vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { //pass in numbers by reference

    unordered_map<int, int> nextGreater;  // map next greater

    stack<int> st;  // monotonic decreasing stack

    for (int n : nums2) {   //loop through nums2
        
        while (!st.empty() && n > st.top()) {   // while the stack is not empty and current n is greater than the top of stack

            nextGreater[st.top()] = n;  // found the next greater

            st.pop();
        }

        st.push(n);

    }

    // remaining stack elements have no next greater
    while (!st.empty()) {

        nextGreater[st.top()] = -1; // assign -1 to each of the stack elements

        st.pop(); // pop the element from the stack

    }

    vector<int> result;

    for (int num : nums1) {  // loop through nums1

        result.push_back(nextGreater[num]); //push the value of each into result

    }

    return result;
}


int main() {

    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };


    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Result: ";

    for (int n : result) { 
        cout << n << " ";
    }

    cout << endl;

    return 0;

}

