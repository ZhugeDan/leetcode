3. 无重复字符的最长子串
中等
9.6K
相关企业
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

int lengthOfLongestSubstring(char * s){

    int n = strlen(s);
    int char_set[128] = {0};
    // 用于存储字符出现的次数,{0}这种初始化方式，是数组里面全为零
    int start = 0,end = 0;// 滑动窗口的左右指针
    int max_length =0;// 最大子串长度

    while(end < n){
        //循环的尽头是遍历完整个数组
        if(char_set[(int)s[end]] == 0){
             // 如果字符没有出现过，将其标记为出现，用int强转成ASCII码
            char_set[(int)s[end]] = 1;
            max_length = (end - start +1) > max_length ? (end - start +1 ) : max_length;
            end++;
        }else{
            // 如果字符出现过，移动左指针直到窗口内不再有重复字符
            char_set[(int)s[start]] = 0;
            start++;
        }
    }
    return max_length;
}


