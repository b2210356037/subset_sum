#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;

class Solution {
public:
    vector<int> subsetSum(vector<int>& nums, int target) {
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target + 1, false));
        dp[1][0] = true;
        vector<int> res;
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 1; j <= target; j++){
                if(j < nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if( j == nums[i-1]) dp[i][j] = true;
                else if(nums[i-1] < j){
                    dp[i][j] = max(dp[i-1][j - nums[i-1]], dp[i-1][j]);
                }
            }
        }

        //populate the result
        int i = nums.size();
        int j = target;
        while(i > 0 && j > 0){
            if(dp[i][j] == dp[i-1][j]){
                i--;
            }
            else{
                res.push_back(nums[i-1]);
                j -= nums[i-1];
                i--;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 7, 8, 10};
    int target = 11;
    for(auto x: s.subsetSum(nums, target)){
        cout << x << " ";
    }
    return 0;
}
