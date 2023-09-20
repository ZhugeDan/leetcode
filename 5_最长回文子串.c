5. 最长回文子串
提示
中等
6.8K
相关企业
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 

char* longestPalindrome(char* s){

        // int len = strlen(s);
        int len = strlen(s);
        if(len <= 1)    return s;

        int start =0;//用来记录最长回文子串的起始位置
        int maxlen = 1;//最长回文子串长度

        //dp创建一个二维数组，dp[i][j]=1表示s串从i到j为满足回文子串
        int dp[len][len];
        memset(dp,0,sizeof(dp));//初始化dp矩阵，sizeof确保整个矩阵都为零

        for(int i=0;i<len;i++){
                dp[i][i]=1;//单个子串肯定是回文子串
        }

        for(int i = 0; i<len-1;i++){
                if (s[i] == s[i+1]){
                        dp[i][i+1] = 1;
                        start = i;
                        maxlen = 2;
                }

        }

        for(int currlen = 3;currlen<=len; currlen++)
                for(int i= 0;i<=len -currlen +1;i++){
                        int j= currlen +i -1;
                        if(s[i] == s[j] && dp[i+1][j-1]){//只有首尾字符相同，且两端各删除一个字符，>仍是回文子串
                                dp[i][j] = 1;
                                start = i;
                                maxlen =currlen;
                        }
                }

        char* result = (char *)malloc(maxlen +1);//字符串以'\0'收尾，但是函数strlen不计入'\0'
        strncpy(result,s+start,maxlen);//strncpy 函数用于复制字符串的一部分到目标字符数组中，并指定要复制的字符数。
        //strcpy 函数用于将一个字符串完全复制到另一个字符串中，直到遇到源字符串的结尾字符 '\0'。它的原型如下：
        result[maxlen] = '\0';

        return result;

}

