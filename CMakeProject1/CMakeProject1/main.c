//
// Created by 33275 on 2023/6/12.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
 链串的基本操作的实现
 1. 初始化链串
 2. 销毁链串
 3. 清空链串
 4. 判断链串是否为空
 5. 获取链串的长度
 6. 获取链串中指定位置的元素
 7. 获取链串中指定元素的位置
 8. 在链串的指定位置插入元素
 9. 在链串的指定位置删除元素
 10. 在链串的指定位置替换元素
 11. 遍历链串
 12. 链串的复制
 13. 链串的连接
 14. 链串的比较
 15. 链串的截取
 16. 链串的查找
 17. 链串的替换
 18. 链串的插入
 19. 链串的删除
 20. 链串的反转
 21. 链串的排序
 22. 链串的去重
 23. 链串的合并
 24. 链串的交集
 25. 链串的并集
 26. 链串的差集
 27. 链串的对称差
 28. 链串的子串
 29. 链串的子序列
*/

// 定义链串的数据类型
typedef struct Node {
    int data;
    struct Node* next;
} Node, * LinkString;


// 1、初始化链串
void InitLinkString(LinkString* linkString) {
    *linkString = (LinkString)malloc(sizeof(Node));
    (*linkString)->next = NULL;
}

// 2、销毁链串
void DestroyLinkString(LinkString* linkString) {
    LinkString p = *linkString;
    while (p) {
        LinkString q = p->next;
        free(p);
        p = q;
    }
    *linkString = NULL;
}

// 3、清空链串
void ClearLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        LinkString q = p->next;
        free(p);
        p = q;
    }
    linkString->next = NULL;
}

// 4、判断链串是否为空
int IsEmptyLinkString(LinkString linkString) {
    return linkString->next == NULL;
}

// 5、获取链串的长度
int GetLinkStringLength(LinkString linkString) {
    int length = 0;
    LinkString p = linkString->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 6、获取链串中指定下标的元素
char GetLinkStringElement(LinkString linkString, int index) {
    int i = 0;
    LinkString p = linkString->next;
    while (p && i < index) {
        i++;
        p = p->next;
    }
    if (p) {
        return p->data;
    }
    return '\0';
}

// 7、获取链串中指定元素的位置
int GetLinkStringIndex(LinkString linkString, char element) {
    int index = 0;
    LinkString p = linkString->next;
    while (p) {
        if (p->data == element) {
            return index;
        }
        index++;
        p = p->next;
    }
    return -1;
}

// 8、在链串的指定位置插入元素 从0开始 0表示在第一个元素前插入 1表示在第一个元素后插入
void InsertLinkStringElement(LinkString linkString, int index, char element) {
    int i = 0;
    LinkString p = linkString;
    while (p && i < index) {
        i++;
        p = p->next;
    }
    if (p) {
        LinkString q = (LinkString)malloc(sizeof(Node));
        q->data = element;
        q->next = p->next;
        p->next = q;
    }
}

// 9、在链串的指定位置删除元素
void DeleteLinkStringElement(LinkString linkString, int index) {
    int i = 0;
    LinkString p = linkString;
    while (p && i < index) {
        i++;
        p = p->next;
    }
    if (p && p->next) {
        LinkString q = p->next;
        p->next = q->next;
        free(q);
    }
}

// 10、在链串的指定位置替换元素
void ReplaceLinkStringElement(LinkString linkString, int index, char element) {
    int i = 0;
    LinkString p = linkString->next;
    while (p && i < index) {
        i++;
        p = p->next;
    }
    if (p) {
        p->data = element;
    }
}

// 11、遍历链串
void TraverseLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

// 12、链串的复制 用一个新的链串来存储原链串的数据
void CopyLinkString(LinkString linkString, LinkString* copyLinkString) {
    InitLinkString(copyLinkString);
    LinkString p = linkString->next;
    LinkString q = *copyLinkString;
    while (p) {
        LinkString r = (LinkString)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
    }
}

// 13、链串的连接 两个链串连接成一个新的链串 
void ConcatLinkString(LinkString linkString1, LinkString linkString2, LinkString* concatLinkString) {
    InitLinkString(concatLinkString);
    LinkString p = linkString1->next;
    LinkString q = *concatLinkString;
    while (p) {
        LinkString r = (LinkString)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
    }
    p = linkString2->next;
    while (p) {
        LinkString r = (LinkString)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
    }
}

// 14、链串内容的比较
int CompareLinkString(LinkString linkString1, LinkString linkString2) {
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    while (p && q) {
        if (p->data != q->data) {
            return p->data - q->data;
        }
        p = p->next;
        q = q->next;
    }
    if (p) {
        return 1;
    }
    if (q) {
        return -1;
    }
    return 0;
}

// 15、链串的截取,从指定位置开始截取指定长度的子串,并返回子串
void SubLinkString(LinkString linkString, int index, int length, LinkString* subLinkString) {
    InitLinkString(subLinkString);
    LinkString p = linkString->next;
    LinkString q = *subLinkString;
    int i = 0;
    while (p && i < index) {
        i++;
        p = p->next;
    }
    i = 0;
    while (p && i < length) {
        LinkString r = (LinkString)malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
        i++;
    }
}

// 16、链串的查找 判断输入的链串是否是原链串的子串 如果是 返回子串的位置 否则返回-1
int IndexLinkString(LinkString linkString, LinkString subLinkString) {
    LinkString p = linkString->next;
    LinkString q = subLinkString->next;
    int index = 0;
    while (p) {
        if (p->data == q->data) {
            LinkString r = p;
            LinkString s = q;
            while (r && s && r->data == s->data) {
                r = r->next;
                s = s->next;
            }
            if (!s) {
                return index;
            }
        }
        index++;
        p = p->next;
    }
    return -1;
}

// 17、链串的替换 将链串1中指定的长度替换成输入的链串 替换的位置是从start开始的长度为length的子串
void ReplaceLinkString(LinkString linkString, int start, int length, LinkString replaceLinkString) {
    LinkString p = linkString;
    int i = 0;
    while (p && i < start) {
        i++;
        p = p->next;
    }
    if (p) {
        LinkString q = replaceLinkString->next;
        while (q) {
            LinkString r = (LinkString)malloc(sizeof(Node));
            r->data = q->data;
            r->next = p->next;
            p->next = r;
            p = r;
            q = q->next;
        }
        i = 0;
        while (p && i < length) {
            LinkString q = p->next;
            p->next = q->next;
            free(q);
            i++;
        }
    }
}

// 18、链串的插入 将insertLinkString插入到linkString的start位置
void InsertLinkString(LinkString linkString, int start, LinkString insertLinkString) {
    LinkString p = linkString;
    int i = 0;
    while (p && i < start) {
        i++;
        p = p->next;
    }
    if (p) {
        LinkString q = insertLinkString->next;
        while (q) {
            LinkString r = (LinkString)malloc(sizeof(Node));
            r->data = q->data;
            r->next = p->next;
            p->next = r;
            p = r;
            q = q->next;
        }
    }
}

// 19、链串的删除 从start位置开始删除length个字符
void DeleteLinkString(LinkString linkString, int start, int length) {
    LinkString p = linkString;
    int i = 0;
    while (p && i < start) {
        i++;
        p = p->next;
    }
    if (p) {
        LinkString q = p->next;
        i = 0;
        while (q && i < length) {
            i++;
            LinkString r = q;
            q = q->next;
            free(r);
        }
        p->next = q;
    }
}

// 20、链串的反转 将链串反转
void ReverseLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    LinkString q = NULL;
    while (p) {
        LinkString r = p->next;
        p->next = q;
        q = p;
        p = r;
    }
    linkString->next = q;
}

// 21、链串的排序 将链串中的字符按照ASCII码从小到大排序
void SortLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        LinkString q = p->next;
        while (q) {
            if (p->data > q->data) {
                char temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

// 22、链串的去重
void DeduplicateLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        LinkString q = p->next;
        LinkString r = p;
        while (q) {
            if (p->data == q->data) {
                LinkString s = q;
                r->next = q->next;
                q = q->next;
                free(s);
            }
            else {
                r = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

// 23、链串的合并 将两个有序链串合并为一个有序链串
void MergeLinkString(LinkString linkString1, LinkString linkString2, LinkString* mergeLinkString) {
    InitLinkString(mergeLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *mergeLinkString;
    while (p && q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        }
        else {
            s->data = q->data;
            q = q->next;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
    while (q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = q->data;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
}

// 24、链串的交集 返回两个链串的交集
void IntersectLinkString(LinkString linkString1, LinkString linkString2, LinkString* intersectLinkString) {
    InitLinkString(intersectLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *intersectLinkString;
    while (p && q) {
        if (p->data < q->data) {
            p = p->next;
        }
        else if (p->data > q->data) {
            q = q->next;
        }
        else {
            LinkString s = (LinkString)malloc(sizeof(Node));
            s->data = p->data;
            s->next = NULL;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
}

// 25、链串的并集 返回两个链串的并集 两个链串中的字符不重复
void UnionLinkString(LinkString linkString1, LinkString linkString2, LinkString* unionLinkString) {
    InitLinkString(unionLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *unionLinkString;
    while (p && q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        }
        else if (p->data > q->data) {
            s->data = q->data;
            q = q->next;
        }
        else {
            s->data = p->data;
            p = p->next;
            q = q->next;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
    while (q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = q->data;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
}

// 26、链串的差集 返回两个链串的差集 两个链串中的字符不重复 两个链串中的字符按照ASCII码从小到大排序
void DifferenceLinkString(LinkString linkString1, LinkString linkString2, LinkString* differenceLinkString) {
    InitLinkString(differenceLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *differenceLinkString;
    while (p && q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        }
        else if (p->data > q->data) {
            q = q->next;
        }
        else {
            p = p->next;
            q = q->next;
            continue;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
}

// 27、链串的对称差
void SymmetricDifferenceLinkString(LinkString linkString1, LinkString linkString2,
    LinkString* symmetricDifferenceLinkString) {
    InitLinkString(symmetricDifferenceLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *symmetricDifferenceLinkString;
    while (p && q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        }
        else if (p->data > q->data) {
            s->data = q->data;
            q = q->next;
        }
        else {
            p = p->next;
            q = q->next;
            continue;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
    while (q) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = q->data;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
}

// 28、链串的子串
// 从链串中截取一段连续的子串 从第position个字符开始截取长度为length的子串 1<=position<=length <=链串长度 用subStringLinkString返回
void SubStringLinkString(LinkString linkString, int position, int length, LinkString* subStringLinkString) {
    InitLinkString(subStringLinkString);
    LinkString p = linkString->next;
    LinkString r = *subStringLinkString;
    int i = 1;
    while (p && i < position) {
        p = p->next;
        i++;
    }
    if (!p || i > position) {
        return;
    }
    for (int j = 0; j < length; ++j) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
}

// 29、链串的子序列
// 从链串中截取一段不连续的子串 从第position个字符开始截取长度为length的子串 1<=position<=length <=链串长度 用subSequenceLinkString返回
void SubSequenceLinkString(LinkString linkString, int position, int length, LinkString* subSequenceLinkString) {
    InitLinkString(subSequenceLinkString);
    LinkString p = linkString->next;
    LinkString r = *subSequenceLinkString;
    int i = 1;
    while (p && i < position) {
        p = p->next;
        i++;
    }
    if (!p || i > position) {
        return;
    }
    for (int j = 0; j < length; ++j) {
        LinkString s = (LinkString)malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
}

// 创建链串
void CreateLinkString(LinkString* pNode) {
    InitLinkString(pNode);
    LinkString r = *pNode;
    char c;
    //char append[100];
    while ((c = getchar()) != '\n') {

        LinkString s = (LinkString)malloc(sizeof(Node));

        // 输入的C不上逗号或空格，就把输入的c拼接成一个字符串
        if (c != ',' && c != ' ' && c != "，") {
            //strcat(append, &c);
            //TODO 拼接字符串
            s->data = c;
            s->next = NULL;
            r->next = s;
            r = s;
        }
        else {
            continue;
        }

    }

}

// 打印链串
void PrintLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        printf("%c,", p->data);
        p = p->next;
    }
    printf("\n");
}

// 退出程序
void Exit() {
    printf("程序已退出！\n");
    exit(0);
}


int main() {
    //// 选择编码为utf8
    //system("chcp 65001");


    while (1) {
        LinkString linkString1 = NULL;
        LinkString linkString2 = NULL;

        // 选择操作
        int choice;
        printf(" 1. 初始化链串\n"
            " 2. 销毁链串\n"
            " 3. 清空链串\n"
            " 4. 判断链串是否为空\n"
            " 5. 获取链串的长度\n"
            " 6. 获取链串中指定位置的元素\n"
            " 7. 获取链串中指定元素的位置\n"
            " 8. 在链串的指定位置插入元素\n"
            " 9. 在链串的指定位置删除元素\n"
            " 10. 在链串的指定位置替换元素\n"
            " 11. 遍历链串\n"
            " 12. 链串的复制\n"
            " 13. 链串的连接\n"
            " 14. 链串的比较\n"
            " 15. 链串的截取\n"
            " 16. 链串的查找\n"
            " 17. 链串的替换\n"
            " 18. 链串的插入\n"
            " 19. 链串的删除\n"
            " 20. 链串的反转\n"
            " 21. 链串的排序\n"
            " 22. 链串的去重\n"
            " 23. 链串的合并\n"
            " 24. 链串的交集\n"
            " 25. 链串的并集\n"
            " 26. 链串的差集\n"
            " 27. 链串的对称差\n"
            " 28. 链串的子串\n"
            " 29. 链串的子序列\n");
        printf(" 0、退出\n");
        printf("请输入要操作的编号：");
        scanf("%d", &choice);

        int index;
        LinkString linkString3;
        switch (choice) {
        case 1:
            // 创建链串
            printf("请输入你要初始化的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 1、初始化链串
            InitLinkString(&linkString1);
            printf("链串已初始化！\n");
            goto again;
        case 2:
            printf("请输入你要销毁的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 2、销毁链串
            DestroyLinkString(&linkString1);
            printf("链串已销毁！\n");
            goto again;
        case 3:
            printf("请输入你要清空的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 3、清空链串
            ClearLinkString(linkString1);
            printf("链串已清空！\n");
            goto again;
        case 4:
            printf("请输入你要判断是否为空的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 4、判断链串是否为空
            if (IsEmptyLinkString(linkString1)) {
                printf("链串1为空！\n");
            }
            else {
                printf("链串1不为空！\n");
            }
            goto again;
        case 5:
            printf("请输入你要获取长度的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 5、获取链串的长度
            printf("链串1的长度为：%d\n", GetLinkStringLength(linkString1));
            goto again;
        case 6:
            printf("请输入你要获取元素的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 6、获取链串中指定下标的元素
            printf("请输入要获取元素的下标：");
            scanf("%d", &index);
            printf("链串1中下标为%d的元素为：%c\n", index, GetLinkStringElement(linkString1, index));
            goto again;
        case 7:
            printf("请输入你要获取元素的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 7、获取链串中指定元素的位置
            printf("请输入要获取元素的位置：");
            char element;
            int index;
            scanf("%d", &element);
            index = GetLinkStringIndex(linkString1, element);
            if (index == -1) {
                printf("获取元素失败！\n");
            }
            else {
                printf("链串1中元素的位置为：%d\n", index);
            }
            goto again;
        case 8:
            printf("请输入你要插入元素的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 8、在链串的指定位置插入元素
            printf("从0开始 0表示在第一个元素前插入 1表示在第一个元素后插入\n");
            printf("请输入要插入元素的位置：");
            scanf("%d", &index);
            getchar();
            printf("请输入要插入的元素：");
            scanf("%c", &element);
            InsertLinkStringElement(linkString1, index, element);
            printf("链串1中插入元素成功！插入后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            goto again;
        case 9:
            printf("请输入你要删除元素的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 9、在链串的指定位置删除元素
            printf("请输入要删除元素的位置：");
            scanf("%d", &index);
            DeleteLinkStringElement(linkString1, index);
            printf("链串1中删除元素成功！删除后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            goto again;
        case 10:
            printf("请输入你要替换元素的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 10、在链串的指定位置替换元素
            printf("请输入要替换元素的位置：");
            scanf("%d", &index);
            getchar();
            printf("请输入要替换的元素：");
            scanf("%c", &element);
            ReplaceLinkStringElement(linkString1, index, element);
            printf("链串1中替换元素成功！替换后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            goto again;
        case 11:
            printf("请输入你要遍历的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 11、遍历链串
            TraverseLinkString(linkString1);
            goto again;
        case 12:
            printf("请输入你要复制的链串：\n");
            getchar();
            CreateLinkString(&linkString1);
            // 12、链串的复制
            CopyLinkString(linkString1, &linkString3);
            printf("链串1已复制到链串3！链串3为：\n");
            // 打印链串
            PrintLinkString(linkString3);
            goto again;
        case 13:
            printf("请输入你要连接的两个链串：\n");
            printf("请输入链串1：");
            getchar();
            CreateLinkString(&linkString1);
            printf("请输入链串2：");
            getchar();
            CreateLinkString(&linkString2);
            // 13、链串的连接
            ConcatLinkString(linkString1, linkString2, &linkString3);
            printf("链串1已连接到链串2！连接后的链串为：");
            // 打印链串
            PrintLinkString(linkString3);
            goto again;
        case 14:
            printf("请输入你要比较的两个链串：\n");
            printf("请输入链串1：");
            CreateLinkString(&linkString1);
            printf("请输入链串2：");
            CreateLinkString(&linkString2);
            // 14、链串的比较
            if (!CompareLinkString(linkString1, linkString2)) {
                printf("链串1与链串2相等！\n");
            }
            else {
                printf("链串1与链串2不相等！\n");
            }
            goto again;
        case 15:
            printf("请输入你要截取的链串：\n");
            CreateLinkString(&linkString1);
            // 15、链串的截取
            printf("请输入要截取的链串的起始位置和长度：");
            int start, length;
            scanf("%d %d", &start, &length);
            SubLinkString(linkString1, start, length, &linkString3);
            printf("链串1已截取！截取后的链串为：\n");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 16:
            printf("请输入你要被查找链串：");
            getchar();
            CreateLinkString(&linkString1);
            // 16、链串的查找
            printf("请输入要在链串查找的子串：");
            getchar();
            CreateLinkString(&linkString3);
            if (IndexLinkString(linkString1, linkString3) == -1) {
                printf("不是链串的子串！\n");
            }
            else {
                printf("是链串的子串！\n");
            }
            goto again;
        case 17:
            printf("请输入你要替换的链串：");
            getchar();
            CreateLinkString(&linkString1);
            // 17、链串的替换
            printf("请输入要去替换链串：");
            getchar();
            CreateLinkString(&linkString3);
            printf("请输入要替换链串1子串的位置和长度：");
            scanf("%d %d", &start, &length);
            ReplaceLinkString(linkString1, start, length, linkString3);
            printf("链串1已替换！替换后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            getchar();
            goto again;
            break;
        case 18:
            // 18、链串的插入
            printf("请输入要插入的链串：");
            getchar();
            CreateLinkString(&linkString3);
            printf("请输入要插入链串1的位置：");
            scanf("%d", &index);
            InsertLinkString(linkString1, index, linkString3);
            printf("已插入到链串1！插入后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            getchar();
            break;
        case 19:
            // 19、链串的删除
            printf("请输入要删除的链串的位置和长度：");
            scanf("%d %d", &index, &length);
            DeleteLinkString(linkString1, index, length);
            printf("链串1已删除指定片段！删除后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            getchar();
            break;
        case 20:
            // 20、链串的反转
            ReverseLinkString(linkString1);
            printf("链串1已反转！反转后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            ReverseLinkString(linkString2);
            printf("链串2已反转！反转后的链串为：");
            // 打印链串
            PrintLinkString(linkString2);
            getchar();
            break;
        case 21:
            // 21、链串的排序
            SortLinkString(linkString1);
            printf("链串1已排序！排序后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            SortLinkString(linkString2);
            printf("链串2已排序！排序后的链串为：");
            // 打印链串
            PrintLinkString(linkString2);
            getchar();
            break;
        case 22:
            // 22、链串的去重
            DeduplicateLinkString(linkString1);
            printf("链串1已去重！去重后的链串为：");
            // 打印链串
            PrintLinkString(linkString1);
            DeduplicateLinkString(linkString2);
            printf("链串2已去重！去重后的链串为：");
            // 打印链串
            PrintLinkString(linkString2);
            getchar();
            break;
        case 23:
            // 23、链串的合并
            MergeLinkString(linkString1, linkString2, &linkString3);
            printf("链串1链串2已合并！合并后的链串为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 24:
            // 24、链串的交集
            IntersectLinkString(linkString1, linkString2, &linkString3);
            if (linkString3 == NULL) {
                printf("链串1和链串2没有交集！\n");
                getchar();
                break;
            }
            printf("链串1和链串2交集后的链串为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 25:
            // 25、链串的并集
            UnionLinkString(linkString1, linkString2, &linkString3);
            printf("链串1与链串2的并集为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 26:
            // 26、链串的差集
            DifferenceLinkString(linkString1, linkString2, &linkString3);
            printf("链串1与链串2的差集为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 27:
            SymmetricDifferenceLinkString(linkString1, linkString2, &linkString3);
            printf("链串1与链串2的对称差集为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 28:
            // 28、链串的子串
            printf("请输入要截取的链串1的位置和长度：");
            scanf("%d %d", &index, &length);
            SubStringLinkString(linkString1, index, length, &linkString3);
            printf("链串1的子串为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 29:
            // 29、链串的子序列
            printf("请输入要截取的链串1的位置和长度：");
            scanf("%d %d", &index, &length);
            SubSequenceLinkString(linkString1, index, length, &linkString3);
            printf("链串1的子序列为：");
            // 打印链串
            PrintLinkString(linkString3);
            getchar();
            break;
        case 0:
            // 0、退出
            printf("欢迎下次再使用本系统！\n");
            Exit();
            getchar();
            break;
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    again:
        printf("是否继续？（Y/N）");
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y') {
            continue;
        }
        else if (choice == 'N' || choice == 'n') {
            printf("欢迎下次再使用本系统！\n");
            Exit();
            getchar();
            break;
        }
        else {
            printf("输入有误，请重新输入！\n");
            goto again;
        }
    }

    return 0;
}