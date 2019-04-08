# 耗时48ms，击败94%的选手， 内存一般，只击败50%+
# 主要思想 动规，单独处理了尾巴上相同的字符


class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) < 2:
            return 0
        same_len = 1
        
        div_cnt = [0]
        last_palindrome_list = []
        for idx in xrange(1, len(s)):
            cur_palindrome_list = []
            if s[idx] == s[idx - 1]:
                cur_same_len = same_len + 1
            else:
                cur_same_len = 1
                cur_palindrome_list.append(1)
                if same_len > 1 and idx - 1 - same_len >=0 and s[idx -1 - same_len] == s[idx]:
                    cur_palindrome_list.append(same_len + 2)
                                
            for p in last_palindrome_list:
                if idx - 1 - p >= 0:
                    if s[idx - 1 - p] == s[idx]:
                        cur_palindrome_list.append(p + 2)
            
            div_cur = div_cnt[idx - 1]
            if cur_same_len == idx + 1:
                div_cur = -1
        
            for sl in xrange(2, cur_same_len + 1):
                if div_cnt[idx - sl] < div_cur:
                    div_cur = div_cnt[idx - sl]
            for p in cur_palindrome_list:
                if p == idx + 1:
                    div_cur = -1
                if div_cnt[idx - p] < div_cur:
                    div_cur = div_cnt[idx - p]
            div_cur += 1
            div_cnt.append(div_cur)
            # print div_cnt, same_len, cur_same_len, last_palindrome_list, cur_palindrome_list
            same_len = cur_same_len
            last_palindrome_list = cur_palindrome_list
        return div_cnt[-1]
