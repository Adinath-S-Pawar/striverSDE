#include<iostream>
using namespace std;
/*
Problem Statement: Given an array of non-negative integers representation elevation of ground. 
Your task is to find the water that can be trapped after rain .

*/
int main()
{
    return 0;
}
/*
Time Complexity: O(n) because the two pointers traverse the array only once, each pointer moving inward and covering the entire array in total linear time.

Space Complexity: O(1) as only constant extra space is used for pointers and variables, regardless of input size.*/
long long getTrappedWater(long long* arr, int n) {
    // 2 pointers
    int left = 0;
    int right = n-1;

    //var to track max ht at left and right
    int leftmax = 0;
    int rightmax = 0;

    long long totalwater = 0;

    while(left <= right)
    {
        //process smaller bar
        if(arr[left <= arr[right]])
        {
            //update leftmax for higher building
            if(arr[left] >= leftmax)
            {
                leftmax = arr[left];
            }
            else
            {
                //water can be stored since large building at left
                totalwater += leftmax - arr[left];
            }
            left++;
        }
        else
        {
            //update maxright for higher building
            if(arr[right] >= rightmax)
            {
                rightmax = arr[right];
            }
            else
            {
                //water can be stored since large building at left
                totalwater += rightmax - arr[right];
            }
            right--;
        }
    }

    return totalwater;
}