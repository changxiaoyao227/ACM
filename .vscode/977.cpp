/*
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]

*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> b;
        for(int i=0;i<A.size();i++)
        {
            int k=A[i]*A[i];
            b.push_back(k);
        }
        sort(b.begin(),b.end());
        return b;
    }
};
//更好应该用到数组本身是递减的特性
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        std::vector<int> ans(A.size());
        
        int i = 0, j = size-1;
        while (i <= j)
        {
            if (abs(A[i]) < abs(A[j]))
            {
                ans[j-i] = A[j]*A[j];
                j--;
            }
            else
            {
                ans[j-i] = A[i]*A[i];
                i++;
            }
        }

        return ans;
    }
};