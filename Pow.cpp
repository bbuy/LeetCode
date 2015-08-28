
Pow(x, n) Total Accepted: 61133 Total Submissions: 228771 My Submissions
Question  Solution





Implement pow(x, n).



Show Tags


Show Similar Problems





Have you met this question in a real interview?
Yes

No



Discuss


class Solution {
public:
    double Pow_NoSign(double x, int n)
    {
        if(n == 1)
        return x;

        double half = myPow(x, n/2);
        if(n%2 == 0)
        return half * half;
        else
        return half * half * x;
    }
    double myPow(double x, int n) {
        if(n == 0)
        return 1;

        bool sign = n<0?true:false;
        return sign?1/Pow_NoSign(x, -1*n):Pow_NoSign(x, n);
    }
};
