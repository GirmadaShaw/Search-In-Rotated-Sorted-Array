/*
There is an integer array nums sorted in ascending order (with distinct values).Prior to being passed to your function,
nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2}, target = 4;
    // int arr[] = {4,5,6,7,0,1,2}, target = 3 ;
    // int arr[] = {0}, target = 0 ;
    int size = sizeof(arr) / sizeof(int);

    int start = 0, flag = 0, end = size - 1, mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (arr[mid] == target)
        {

            flag = 1;
            std ::cout << "Found at: " << mid;
            break;
        }

        else if (arr[start] <= arr[mid])
        {
            if (target >= arr[start] && target <= arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        else if (target >= arr[mid] && target <= arr[end])
            start = mid + 1;
        else
            end = mid - 1;

        mid = start + ((end - start) / 2);
    }
    if (flag == 0)
        std ::cout << "Element not present";
}