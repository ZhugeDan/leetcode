4. 寻找两个正序数组的中位数
困难
6.8K
相关企业
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

//没有用二分查找，以后再来探索吧
//
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    int new[len];
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        //有一个不满足就退出
        if (nums1[i] < nums2[j]) {
            new[k++] = nums1[i++];
        } else {
            new[k++] = nums2[j++];
        }
    }

    while (i < nums1Size) {
        new[k++] = nums1[i++];
    }

    while (j < nums2Size) {
        new[k++] = nums2[j++];
    }

    double median;
    if (len % 2 == 0) {
        median = (new[len / 2 - 1] + new[len / 2]) / 2.0;
    } else {
        median = new[len / 2];
    }
    //浮点式除法： 被除数可以是整数形式，但如果你想要获得一个浮点数结果并保留小数部分，那么至少其中一个操 作数（被除数或除数）必须是浮点数形式。当除数和被除数都是整数时，整数除法将执行，它将返回一个整数结果并舍弃小数部分。例如：

    return median;
}

