//
// Created by 33275 on 2023/6/12.
//

#include <stdio.h>
#include <malloc.h>
#include <gtk/gtk.h>


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
    char data;
    struct Node *next;
} Node, *LinkString;


// 1、初始化链串
void InitLinkString(LinkString *linkString) {
    *linkString = (LinkString) malloc(sizeof(Node));
    (*linkString)->next = NULL;
}

// 2、销毁链串
void DestroyLinkString(LinkString *linkString) {
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

// 6、获取链串中指定位置的元素
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

// 8、在链串的指定位置插入元素
void InsertLinkStringElement(LinkString linkString, int index, char element) {
    int i = 0;
    LinkString p = linkString;
    while (p && i < index) {
        i++;
        p = p->next;
    }
    if (p) {
        LinkString q = (LinkString) malloc(sizeof(Node));
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

// 12、链串的复制
void CopyLinkString(LinkString linkString, LinkString *copyLinkString) {
    InitLinkString(copyLinkString);
    LinkString p = linkString->next;
    LinkString q = *copyLinkString;
    while (p) {
        LinkString r = (LinkString) malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
    }
}

// 13、链串的连接 两个链串连接成一个新的链串 
void ConcatLinkString(LinkString linkString1, LinkString linkString2, LinkString *concatLinkString) {
    InitLinkString(concatLinkString);
    LinkString p = linkString1->next;
    LinkString q = *concatLinkString;
    while (p) {
        LinkString r = (LinkString) malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
    }
    p = linkString2->next;
    while (p) {
        LinkString r = (LinkString) malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
    }
}

// 14、链串的比较
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
    return GetLinkStringLength(linkString1) - GetLinkStringLength(linkString2);
}

// 15、链串的截取,从指定位置开始截取指定长度的子串,并返回子串
void SubLinkString(LinkString linkString, int index, int length, LinkString *subLinkString) {
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
        LinkString r = (LinkString) malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
        i++;
    }
}

// 16、链串的查找
int IndexLinkString(LinkString linkString, LinkString findLinkString) {
    LinkString p = linkString->next;
    LinkString q = findLinkString->next;
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

// 17、链串的替换 将链串中的findLinkString替换为replaceLinkString
void ReplaceLinkString(LinkString linkString, LinkString findLinkString, LinkString replaceLinkString) {
    LinkString p = linkString->next;
    LinkString q = findLinkString->next;
    LinkString r = replaceLinkString->next;
    while (p) {
        if (p->data == q->data) {
            LinkString s = p;
            LinkString t = q;
            while (s && t && s->data == t->data) {
                s = s->next;
                t = t->next;
            }
            if (!t) {
                LinkString u = p;
                LinkString v = r;
                while (u && v) {
                    u->data = v->data;
                    u = u->next;
                    v = v->next;
                }
            }
        }
        p = p->next;
    }
}

// 18、链串的插入
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
            LinkString r = (LinkString) malloc(sizeof(Node));
            r->data = q->data;
            r->next = p->next;
            p->next = r;
            p = r;
            q = q->next;
        }
    }
}

// 19、链串的删除
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

// 20、链串的反转
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

// 21、链串的排序
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
            } else {
                r = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

// 23、链串的合并
void MergeLinkString(LinkString linkString1, LinkString linkString2, LinkString *mergeLinkString) {
    InitLinkString(mergeLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *mergeLinkString;
    while (p && q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        } else {
            s->data = q->data;
            q = q->next;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
    while (q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = q->data;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
}

// 24、链串的交集 两个链串的交集是指由两个链串中共同元素组成的链串
void IntersectionLinkString(LinkString linkString1, LinkString linkString2, LinkString *intersectionLinkString) {
    InitLinkString(intersectionLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *intersectionLinkString;
    while (p && q) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            LinkString s = (LinkString) malloc(sizeof(Node));
            s->data = p->data;
            s->next = NULL;
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
}

// 25、链串的并集
void UnionLinkString(LinkString linkString1, LinkString linkString2, LinkString *unionLinkString) {
    InitLinkString(unionLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *unionLinkString;
    while (p && q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        } else if (p->data > q->data) {
            s->data = q->data;
            q = q->next;
        } else {
            s->data = p->data;
            p = p->next;
            q = q->next;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
    while (q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = q->data;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
}

// 26、链串的差集
void DifferenceLinkString(LinkString linkString1, LinkString linkString2, LinkString *differenceLinkString) {
    InitLinkString(differenceLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *differenceLinkString;
    while (p && q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        } else {
            p = p->next;
            q = q->next;
            continue;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
}

// 27、链串的对称差
void SymmetricDifferenceLinkString(LinkString linkString1, LinkString linkString2,
                                   LinkString *symmetricDifferenceLinkString) {
    InitLinkString(symmetricDifferenceLinkString);
    LinkString p = linkString1->next;
    LinkString q = linkString2->next;
    LinkString r = *symmetricDifferenceLinkString;
    while (p && q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        } else if (p->data > q->data) {
            s->data = q->data;
            q = q->next;
        } else {
            p = p->next;
            q = q->next;
            continue;
        }
        s->next = NULL;
        r->next = s;
        r = s;
    }
    while (p) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
    while (q) {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = q->data;
        s->next = NULL;
        r->next = s;
        r = s;
        q = q->next;
    }
}

// 28、链串的子串
// 从链串中截取一段连续的子串 从第position个字符开始截取长度为length的子串 1<=position<=length <=链串长度 用subStringLinkString返回
void SubStringLinkString(LinkString linkString, int position, int length, LinkString *subStringLinkString) {
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
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
}

// 29、链串的子序列
// 从链串中截取一段不连续的子串 从第position个字符开始截取长度为length的子串 1<=position<=length <=链串长度 用subSequenceLinkString返回
void SubSequenceLinkString(LinkString linkString, int position, int length, LinkString *subSequenceLinkString) {
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
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = p->data;
        s->next = NULL;
        r->next = s;
        r = s;
        p = p->next;
    }
}

// 创建链串
void CreateLinkString(LinkString *pNode) {
    InitLinkString(pNode);
    LinkString r = *pNode;
    char c;
    while ((c = getchar()) != '\n') {
        LinkString s = (LinkString) malloc(sizeof(Node));
        s->data = c;
        s->next = NULL;
        r->next = s;
        r = s;
    }

}

// 打印链串
void PrintLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        printf("%c", p->data);
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
    // 选择编码为utf8
    system("chcp 65001");


    while (1) {

        LinkString linkString1;
        LinkString linkString2;
        // 创建链串
        printf("请输入你要操作的链串：\n");
        printf("请输入链串1：");
        CreateLinkString(&linkString1);
        printf("请输入链串2：");
        CreateLinkString(&linkString2);

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
        switch (choice) {
            case 1:
                // 1、初始化链串
                InitLinkString(&linkString1);
                InitLinkString(&linkString2);
                printf("链串已初始化！\n");
                break;
            case 2:
                // 2、销毁链串
                DestroyLinkString(&linkString1);
                DestroyLinkString(&linkString2);
                printf("链串已销毁！\n");
                break;
            case 3:
                // 3、清空链串
                ClearLinkString(linkString1);
                ClearLinkString(linkString2);
                printf("链串已清空！\n");
                break;
            case 4:
                // 4、判断链串是否为空
                if (IsEmptyLinkString(linkString1)) {
                    printf("链串1为空！\n");
                } else {
                    printf("链串1不为空！\n");
                }
                if (IsEmptyLinkString(linkString2)) {
                    printf("链串2为空！\n");
                } else {
                    printf("链串2不为空！\n");
                }
                break;
            case 5:
                // 5、获取链串的长度
                printf("链串1的长度为：%d\n", GetLinkStringLength(linkString1));
                printf("链串2的长度为：%d\n", GetLinkStringLength(linkString2));
                break;
            case 6:
                // 6、获取链串中指定位置的元素
                printf("请输入要获取元素的位置：");
                scanf("%d", &index);
                char e;
                if (GetLinkStringElement(linkString1, index)) {
                    printf("链串1中第%d个元素为：%c\n", index, e);
                } else {
                    printf("获取元素失败！\n");
                }
                if (GetLinkStringElement(linkString2, index)) {
                    printf("链串2中第%d个元素为：%c\n", index, e);
                } else {
                    printf("获取元素失败！\n");
                }
                break;
            case 7:
                // 7、获取链串中指定元素的位置
                printf("请输入要获取元素的位置：");
                scanf("%d", &index);
                if (GetLinkStringIndex(linkString1, 'a')) {
                    printf("链串1中元素a的位置为：%d\n", index);
                } else {
                    printf("获取元素失败！\n");
                }
                if (GetLinkStringIndex(linkString2, 'a')) {
                    printf("链串2中元素a的位置为：%d\n", index);
                } else {
                    printf("获取元素失败！\n");
                }
                break;
            case 8:
                // 8、在链串的指定位置插入元素
                printf("请输入要插入元素的位置：");
                scanf("%d", &index);
                InsertLinkStringElement(linkString1, index, 'a');
                printf("链串1中插入元素成功！\n");
                InsertLinkStringElement(linkString2, index, 'a');
                printf("链串2中插入元素成功！\n");
                break;
            case 9:
                // 9、在链串的指定位置删除元素
                printf("请输入要删除元素的位置：");
                scanf("%d", &index);
                DeleteLinkStringElement(linkString1, index);
                printf("链串1中删除元素成功！\n");
                DeleteLinkStringElement(linkString2, index);
                printf("链串2中删除元素成功！\n");
                break;
            case 10:
                // 10、在链串的指定位置替换元素
                printf("请输入要替换元素的位置：");
                scanf("%d", &index);
                ReplaceLinkStringElement(linkString1, index, 'a');
                printf("链串1中替换元素成功！\n");
                ReplaceLinkStringElement(linkString2, index, 'a');
                printf("链串2中替换元素成功！\n");
                break;
            case 11:
                // 11、遍历链串
                TraverseLinkString(linkString1);
                TraverseLinkString(linkString2);
                break;
            case 12:
                // 12、链串的复制
            {
                LinkString linkString3;
                CopyLinkString(linkString3, &linkString1);
            }
                printf("链串1已复制到链串3！\n");
                break;
            case 13:
                // 13、链串的连接
            {
                LinkString linkString3 = g_nullify_pointer;
                ConcatLinkString(linkString1, linkString2, &linkString3);
            }
                printf("链串1已连接到链串2！\n");
                break;
            case 14:
                // 14、链串的比较
                if (CompareLinkString(linkString1, linkString2)) {
                    printf("链串1与链串2相等！\n");
                } else {
                    printf("链串1与链串2不相等！\n");
                }
                break;
            case 15:
                // 15、链串的截取
                SubLinkString(linkString1, 1, 3, &linkString2);
                printf("链串1已截取！\n");
                break;
            case 16:
                // 16、链串的查找
                if (IndexLinkString(linkString1, linkString2)) {
                    printf("链串2是链串1的子串！\n");
                } else {
                    printf("链串2不是链串1的子串！\n");
                }
                break;
            case 17:
                // 17、链串的替换
            {
                LinkString linkString3;
                ReplaceLinkString(linkString1, linkString2, linkString3);
            }
                printf("链串1已替换为链串2！\n");
                break;
            case 18:
                // 18、链串的插入
                InsertLinkString(linkString1, 1, linkString2);
                printf("链串2已插入到链串1！\n");
                break;
            case 19:
                // 19、链串的删除
                DeleteLinkString(linkString1, 1, 3);
                printf("链串1已删除！\n");
                break;
            case 20:
                // 20、链串的反转
                ReverseLinkString(linkString1);
                printf("链串1已反转！\n");
                break;
            case 21:
                // 21、链串的排序
                SortLinkString(linkString1);
                printf("链串1已排序！\n");
                break;
            case 22:
                // 22、链串的去重
                DeduplicateLinkString(linkString1);
                printf("链串1已去重！\n");
                break;
            case 23:
                // 23、链串的合并
            {
                LinkString linkString3 = NULL;
                MergeLinkString(linkString1, linkString2, &linkString3);
            }
                printf("链串1已合并！\n");
                break;
            case 24:
                // 24、链串的交集
            {
                LinkString linkString3 = NULL;
                IntersectionLinkString(linkString1, linkString2, &linkString3);
            }
                printf("链串1已交集！\n");
                break;
            case 25:
                // 25、链串的并集
            {
                LinkString linkString3 = NULL;
                UnionLinkString(linkString1, linkString2, &linkString3);
            }
                printf("链串1已并集！\n");
                break;
            case 26:
                // 26、链串的差集
            {
                LinkString linkString3 = NULL;
                DifferenceLinkString(linkString1, linkString2, &linkString3);
            }
                printf("链串1已差集！\n");
                break;
            case 27:
                // 27、链串的对称差
            {
                LinkString linkString3 = NULL;
                SymmetricDifferenceLinkString(linkString1, linkString2, &linkString3);
            }
                printf("链串1已对称差！\n");
                break;
            case 28:
                // 28、链串的子串
                SubStringLinkString(linkString1, 1, 3, &linkString2);
                printf("链串1已截取！\n");
                break;
            case 29:
                // 29、链串的子序列
                SubSequenceLinkString(linkString1, 1, 3, &linkString2);
                printf("链串2是链串1的子序列！\n");
                break;
            case 0:
                // 0、退出
                printf("欢迎下次再使用本系统！\n");
                break;
            default:
                printf("输入有误，请重新输入！\n");
                break;
        }
    }

    return 0;
}