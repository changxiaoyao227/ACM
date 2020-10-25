#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int pre;int i=0,j;int max=0;
        if(A.size()<3)
        return 0;
        while(i<A.size()-2){
            while(A[i]>=A[i+1]&&i<A.size()-1)
            i++;
            int f1=0,f2=0;
            pre=i;
            j=pre+1;
            while(A[pre]<A[j]&&j<A.size())
            {
                pre++;j++;f1=1;
            }
            if(A[pre]==A[j]&&j<A.size())
            {   i=j;
                continue;
            }
            while(A[pre]>A[j]&&j<A.size()){
                pre++;j++;f2=1;
            }
            if((f1+f2)==2)
            max=((pre-i+1)>max)?pre-i+1:max;
            i=pre;
        }
        return max;
    }
};
class Solution {
public://最快的解法~
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        int res = 0,i = 0;
        while(i < n){
            int temp = i;
            if(temp+1 < n && nums[temp] < nums[temp+1]){
                while(temp+1 < n && nums[temp] < nums[temp+1]) temp++;
                if(temp+1 < n && nums[temp] > nums[temp+1]){
                    while(temp+1 < n && nums[temp] > nums[temp+1]) temp++;
                    res = max(res,temp-i+1);
                }
            }
            i = max(temp,i+1);
        }
        return res;
    }
};
int main(){
    vector<int> A;Solution s;
    A.push_back(2);A.push_back(0);A.push_back(2);A.push_back(0);
    int m=s.longestMountain(A);
    cout<<m<<endl;
    return 0;
}
