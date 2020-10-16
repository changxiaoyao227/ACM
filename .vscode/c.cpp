#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//提供一对一的hash
        vector<int> b(2,-1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                b[0]=a[target-nums[i]];
                b[1]=i;
                break;
            }
            a[nums[i]]=i;//反过来放入map中，用来获取结果下标
        }
        return b;
    };
};
int main(){
    Solution s;
    vector<int> nums;int target=9;
    nums.push_back(2);nums.push_back(7);
    nums.push_back(11);nums.push_back(13);
   vector<int> a=s.twoSum(nums,target);  
   cout<<"{"; 
   for(int i=0;i<a.size();i++)
    {
       cout<<a[i];
    }
    cout<<"}";
    return 0;
}