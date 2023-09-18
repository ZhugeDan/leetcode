//    
1. 两数之和
提示
简单
17.7K
相关企业
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = NULL;
    *returnSize = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans = (int*)malloc(2 * sizeof(int));
                if (ans == NULL) {
                    // 处理内存分配失败的情况
                    return NULL;
                }
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }

    return NULL; // 未找到符合条件的结果
}

//想用哈希表改进，结果失败了。chatgpt改代码帮助了我很多。
