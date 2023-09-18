2. 两数相加
中等
10K
相关企业
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
	//边界条件不能丢
    struct ListNode *p = l1, *q = l2;
    struct ListNode *L = (struct ListNode*)malloc(sizeof(struct ListNode));
    L->next = NULL;
    int carry = 0;

    struct ListNode *current = L;
	//current 作为新建链表的活动指针
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
	//3元运算符,第一次没有注意到NULL的情况
        int sum = x + y + carry;
        carry = sum / 10;
	//carry记录进位
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        //结构体没有别名的话，malloc时也要打全struct
	//=右边第一个小括号里面struct ListNode 和‘*’之间有没有空格都能执行
	node->val = sum % 10;
        node->next = NULL;

        current->next = node;
        current = current->next;
	//注意题干明确指出了逆序，但不要下意识认为头插法。因为题干还有一句“原形式输出”
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
	//短链表到头不能继续走了。同理数组也要注意不能越界
    }

    if (carry > 0) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;

        current->next = node;
	//注意最后的进位，不能功亏一篑
    }

    return L->next;
    //这道题函数头传的链表是不带头结点，在新建L时，是带头结点，故返回Next
}
