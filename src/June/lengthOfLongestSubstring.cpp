class Solution {
public:
   int lengthOfLongestSubstring(string s) {
            if(s.size()<2) return s.size();
            int d=1, maxLen=1;
            unordered_map<char,int> map;
            map[s[0]]=0;
            for(int i=1;i<s.size();i++)
            {
                if(map.count(s[i])==0 || map[s[i]]<i-d)
                    d++;
                else
                    d= i- map[s[i]];
                map[s[i]]=i;
                if(d>maxLen)
                    maxLen = d;
            }
            return maxLen;
        }
};
