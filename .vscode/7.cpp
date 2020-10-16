/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
class Solution {
public:
    int reverse(int x) {
        int tem=x;int result=0;int k=0;
        int max=pow(2,30)-1+pow(2,30);
        int min=-pow(2,31);
        max=max/10;
        min=min/10;
        while(tem)
        {
            int k=tem%10;
            tem=tem/10;
            if(result>max||(result==max&&k>7))
            return 0;
            if(result<min||(result==min&&k<-8))
            return 0;
            result=result*10+k;
        }
        return result;
    }
};
/*
class Solution {
public:
    int reverse(int x) {
        long result=0;
        while(x){
            result = result * 10 + (x % 10);
            x = x / 10;
        }
        // long border = 0x7fffffff;
        // return (result<border && (result > -1 * (border + 1))) ? result : 0;
        return (int)result==result ? (int)result:0;
    }
};

*/