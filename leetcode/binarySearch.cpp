/*
 * @Descripttion: 
 * @version: 
 * @Author: vansson
 * @Date: 2023-12-23 15:35:48
 * @LastEditors: vansson
 * @LastEditTime: 2023-12-23 16:22:01
 */

//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int binarySearch(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target){
                right = middle - 1;
            }else if(nums[middle] < target){
                left = middle + 1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};

int main(){
    int a[] = {-1, 0, 3, 5, 9, 12};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int target = 9;
    Solution solution;
    cout << solution.binarySearch(nums, target) << endl;
}
