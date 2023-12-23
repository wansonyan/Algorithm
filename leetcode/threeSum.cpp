/*
 * @Descripttion: 
 * @version: 
 * @Author: vansson
 * @Date: 2023-10-19 19:28:55
 * @LastEditors: vansson
 * @LastEditTime: 2023-10-19 19:46:51
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    int n = nums.size();
    if(n < 3){
        return result;
    }

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++){
        map[nums[i]]++;
    }

    for (int i = 0; i < n; i++){
        if(map[nums[i]] > 1){
            continue;
        }

        int left = i + 1, right = n - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){
                result.push_back({nums[i], nums[left], nums[right]});
                map[nums[left]]--;
                map[nums[right]]++;
                left++;
                right--;
            }else if(sum < 0){
                left++;
            }else{
                right--;
            }
        }
    }

    sort(result.begin(), result.end());
    auto last = unique(result.begin(), result.end());
    result.erase(last, result.end());

    return result;
}

int main(){
    vector<int> nums;
    int x;
    while(cin >> x && x != -9999){
        nums.push_back(x);
    }

    vector<vector<int>> result = threeSum(nums);

    for(auto& triplet : result){
        for(int num : triplet){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}