// Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int n = s.length();
        // cout<<n<<endl;
        if(n==1)return 1;
        int l =0;
        int r=0;
        int maxLen=0;
        while(r<n)
        {
            if(hash[s[r]]!=-1)//already once visisted
            {
                if(hash[s[r]]>=l)
                {
                    l = hash[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};