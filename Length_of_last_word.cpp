class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int start = s.length()-1;
        while(s[start]==' '&&start>0)
            start--;
        for(int i = start;i>=0;i--)
        {
            if(s[i]==' ')
                break;
            else
                length++;
        }

        return length;
    }
};
