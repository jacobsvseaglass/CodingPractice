#include <cctype>
#include <string>
//https://neetcode.io/problems/is-palindrome?list=blind75
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        //Two pointers, one starting at the beginning, one starting at the end
        int p1 = 0;
        int p2 = s.length() - 1;
        
        //We are done once the pointers are past eachother
        while(p1 < p2)
        {
            //Skip past invalid characters for p1
            while(p1 < p2 && !validChar(s[p1]))
            {
                p1++;
            }

            //Skip past invalid characters for p2
            while(p2 > p1 && !validChar(s[p2]))
            {
                p2--;
            }

            //Exit if at any time the pointers value do not equal eachother
            if(tolower(s[p1]) != tolower(s[p2]))
                return false;

            p1++;
            p2--;
        }

        return true;
    }

    bool validChar(char c)
    {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
