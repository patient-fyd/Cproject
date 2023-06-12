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

void CreateLinkString(LinkString *pNode);

void PrintLinkString(LinkString pNode);

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

// 13、链串的连接
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

// 15、链串的截取
void SubLinkString(LinkString linkString, int start, int length, LinkString *subLinkString) {
    InitLinkString(subLinkString);
    LinkString p = linkString->next;
    LinkString q = *subLinkString;
    int i = 0;
    while (p && i < start) {
        i++;
        p = p->next;
    }
    i = 0;
    while (p && i < length) {
        i++;
        LinkString r = (LinkString) malloc(sizeof(Node));
        r->data = p->data;
        r->next = NULL;
        q->next = r;
        q = r;
        p = p->next;
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

// 17、链串的替换
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

// 24、链串的交集
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
void SymmetricDifferenceLinkString(LinkString linkString1, LinkString linkString2, LinkString *symmetricDifferenceLinkString) {
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

//

int main(int argc, char *argv[]) {
    // 设置控制台编码为utf8
    system("chcp 65001");
    // 0、定义链串
    LinkString linkString1;
    LinkString linkString2;
    // 1、初始化链串
    InitLinkString(&linkString1);
    InitLinkString(&linkString2);
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *box;
    // 2、创建链串
    printf("请输入链串1：");
    CreateLinkString(&linkString1);
    printf("请输入链串2：");
    CreateLinkString(&linkString2);

    // 选择操作
    int choice;
    printf("请选择操作：\n");
    printf("1. 初始化链串\n"
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
           " 29. 链串的子序列");
    printf("0、退出\n");
    printf("请输入操作编号：");
    scanf("%d", &choice);

    // 执行操作





    return 0;
}

