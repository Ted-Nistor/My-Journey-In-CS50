class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        pref = ''
        for i in range(1,len(strs),1):
            for j in range(len(strs)):
                if strs[i-1][j] == strs[i][j]:
                    pref += strs[i -1][j]
        return pref









