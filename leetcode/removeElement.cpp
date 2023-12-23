//给你一个数组 nums 和一个值 val，你需要移除所有数值等于 val 的元素，并返回移除后数组的新长度。

//暴力解法
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int removeElement(vector<int>& nums, int val){
        int size = nums.size();
        for (int i = 0; i < size; i++){
            if(nums[i] == val){
                for (int j = i + 1; j < size; j++){
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }
};


/**
* 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/
class Solution2 {
public:
    int removeElement2(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   
    }
};

int main(){
    int a[] = {-1, 0, 3, 5, 9, 12, 9, 10};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int val = 9;
    Solution2 solution;
    cout << solution.removeElement2(nums, val) << endl;
}
