//
// Created by 33275 on 2023/6/12.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
 �����Ļ���������ʵ��
 1. ��ʼ������
 2. ��������
 3. �������
 4. �ж������Ƿ�Ϊ��
 5. ��ȡ�����ĳ���
 6. ��ȡ������ָ��λ�õ�Ԫ��
 7. ��ȡ������ָ��Ԫ�ص�λ��
 8. ��������ָ��λ�ò���Ԫ��
 9. ��������ָ��λ��ɾ��Ԫ��
 10. ��������ָ��λ���滻Ԫ��
 11. ��������
 12. �����ĸ���
 13. ����������
 14. �����ıȽ�
 15. �����Ľ�ȡ
 16. �����Ĳ���
 17. �������滻
 18. �����Ĳ���
 19. ������ɾ��
 20. �����ķ�ת
 21. ����������
 22. ������ȥ��
 23. �����ĺϲ�
 24. �����Ľ���
 25. �����Ĳ���
 26. �����Ĳ
 27. �����ĶԳƲ�
 28. �������Ӵ�
 29. ������������
*/

// ������������������
typedef struct Node {
    int data;
    struct Node* next;
} Node, * LinkString;


// 1����ʼ������
void InitLinkString(LinkString* linkString) {
    *linkString = (LinkString)malloc(sizeof(Node));
    (*linkString)->next = NULL;
}

// 2����������
void DestroyLinkString(LinkString* linkString) {
    LinkString p = *linkString;
    while (p) {
        LinkString q = p->next;
        free(p);
        p = q;
    }
    *linkString = NULL;
}

// 3���������
void ClearLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        LinkString q = p->next;
        free(p);
        p = q;
    }
    linkString->next = NULL;
}

// 4���ж������Ƿ�Ϊ��
int IsEmptyLinkString(LinkString linkString) {
    return linkString->next == NULL;
}

// 5����ȡ�����ĳ���
int GetLinkStringLength(LinkString linkString) {
    int length = 0;
    LinkString p = linkString->next;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 6����ȡ������ָ���±��Ԫ��
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

// 7����ȡ������ָ��Ԫ�ص�λ��
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

// 8����������ָ��λ�ò���Ԫ�� ��0��ʼ 0��ʾ�ڵ�һ��Ԫ��ǰ���� 1��ʾ�ڵ�һ��Ԫ�غ����
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

// 9����������ָ��λ��ɾ��Ԫ��
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

// 10����������ָ��λ���滻Ԫ��
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

// 11����������
void TraverseLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

// 12�������ĸ��� ��һ���µ��������洢ԭ����������
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

// 13������������ �����������ӳ�һ���µ����� 
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

// 14���������ݵıȽ�
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

// 15�������Ľ�ȡ,��ָ��λ�ÿ�ʼ��ȡָ�����ȵ��Ӵ�,�������Ӵ�
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

// 16�������Ĳ��� �ж�����������Ƿ���ԭ�������Ӵ� ����� �����Ӵ���λ�� ���򷵻�-1
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

// 17���������滻 ������1��ָ���ĳ����滻����������� �滻��λ���Ǵ�start��ʼ�ĳ���Ϊlength���Ӵ�
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

// 18�������Ĳ��� ��insertLinkString���뵽linkString��startλ��
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

// 19��������ɾ�� ��startλ�ÿ�ʼɾ��length���ַ�
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

// 20�������ķ�ת ��������ת
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

// 21������������ �������е��ַ�����ASCII���С��������
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

// 22��������ȥ��
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

// 23�������ĺϲ� ���������������ϲ�Ϊһ����������
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

// 24�������Ľ��� �������������Ľ���
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

// 25�������Ĳ��� �������������Ĳ��� ���������е��ַ����ظ�
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

// 26�������Ĳ �������������Ĳ ���������е��ַ����ظ� ���������е��ַ�����ASCII���С��������
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

// 27�������ĶԳƲ�
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

// 28���������Ӵ�
// �������н�ȡһ���������Ӵ� �ӵ�position���ַ���ʼ��ȡ����Ϊlength���Ӵ� 1<=position<=length <=�������� ��subStringLinkString����
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

// 29��������������
// �������н�ȡһ�β��������Ӵ� �ӵ�position���ַ���ʼ��ȡ����Ϊlength���Ӵ� 1<=position<=length <=�������� ��subSequenceLinkString����
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

// ��������
void CreateLinkString(LinkString* pNode) {
    InitLinkString(pNode);
    LinkString r = *pNode;
    char c;
    //char append[100];
    while ((c = getchar()) != '\n') {

        LinkString s = (LinkString)malloc(sizeof(Node));

        // �����C���϶��Ż�ո񣬾Ͱ������cƴ�ӳ�һ���ַ���
        if (c != ',' && c != ' ' && c != "��") {
            //strcat(append, &c);
            //TODO ƴ���ַ���
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

// ��ӡ����
void PrintLinkString(LinkString linkString) {
    LinkString p = linkString->next;
    while (p) {
        printf("%c,", p->data);
        p = p->next;
    }
    printf("\n");
}

// �˳�����
void Exit() {
    printf("�������˳���\n");
    exit(0);
}


int main() {
    //// ѡ�����Ϊutf8
    //system("chcp 65001");


    while (1) {
        LinkString linkString1 = NULL;
        LinkString linkString2 = NULL;

        // ѡ�����
        int choice;
        printf(" 1. ��ʼ������\n"
            " 2. ��������\n"
            " 3. �������\n"
            " 4. �ж������Ƿ�Ϊ��\n"
            " 5. ��ȡ�����ĳ���\n"
            " 6. ��ȡ������ָ��λ�õ�Ԫ��\n"
            " 7. ��ȡ������ָ��Ԫ�ص�λ��\n"
            " 8. ��������ָ��λ�ò���Ԫ��\n"
            " 9. ��������ָ��λ��ɾ��Ԫ��\n"
            " 10. ��������ָ��λ���滻Ԫ��\n"
            " 11. ��������\n"
            " 12. �����ĸ���\n"
            " 13. ����������\n"
            " 14. �����ıȽ�\n"
            " 15. �����Ľ�ȡ\n"
            " 16. �����Ĳ���\n"
            " 17. �������滻\n"
            " 18. �����Ĳ���\n"
            " 19. ������ɾ��\n"
            " 20. �����ķ�ת\n"
            " 21. ����������\n"
            " 22. ������ȥ��\n"
            " 23. �����ĺϲ�\n"
            " 24. �����Ľ���\n"
            " 25. �����Ĳ���\n"
            " 26. �����Ĳ\n"
            " 27. �����ĶԳƲ�\n"
            " 28. �������Ӵ�\n"
            " 29. ������������\n");
        printf(" 0���˳�\n");
        printf("������Ҫ�����ı�ţ�");
        scanf("%d", &choice);

        int index;
        LinkString linkString3;
        switch (choice) {
        case 1:
            // ��������
            printf("��������Ҫ��ʼ����������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 1����ʼ������
            InitLinkString(&linkString1);
            printf("�����ѳ�ʼ����\n");
            goto again;
        case 2:
            printf("��������Ҫ���ٵ�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 2����������
            DestroyLinkString(&linkString1);
            printf("���������٣�\n");
            goto again;
        case 3:
            printf("��������Ҫ��յ�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 3���������
            ClearLinkString(linkString1);
            printf("��������գ�\n");
            goto again;
        case 4:
            printf("��������Ҫ�ж��Ƿ�Ϊ�յ�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 4���ж������Ƿ�Ϊ��
            if (IsEmptyLinkString(linkString1)) {
                printf("����1Ϊ�գ�\n");
            }
            else {
                printf("����1��Ϊ�գ�\n");
            }
            goto again;
        case 5:
            printf("��������Ҫ��ȡ���ȵ�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 5����ȡ�����ĳ���
            printf("����1�ĳ���Ϊ��%d\n", GetLinkStringLength(linkString1));
            goto again;
        case 6:
            printf("��������Ҫ��ȡԪ�ص�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 6����ȡ������ָ���±��Ԫ��
            printf("������Ҫ��ȡԪ�ص��±꣺");
            scanf("%d", &index);
            printf("����1���±�Ϊ%d��Ԫ��Ϊ��%c\n", index, GetLinkStringElement(linkString1, index));
            goto again;
        case 7:
            printf("��������Ҫ��ȡԪ�ص�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 7����ȡ������ָ��Ԫ�ص�λ��
            printf("������Ҫ��ȡԪ�ص�λ�ã�");
            char element;
            int index;
            scanf("%d", &element);
            index = GetLinkStringIndex(linkString1, element);
            if (index == -1) {
                printf("��ȡԪ��ʧ�ܣ�\n");
            }
            else {
                printf("����1��Ԫ�ص�λ��Ϊ��%d\n", index);
            }
            goto again;
        case 8:
            printf("��������Ҫ����Ԫ�ص�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 8����������ָ��λ�ò���Ԫ��
            printf("��0��ʼ 0��ʾ�ڵ�һ��Ԫ��ǰ���� 1��ʾ�ڵ�һ��Ԫ�غ����\n");
            printf("������Ҫ����Ԫ�ص�λ�ã�");
            scanf("%d", &index);
            getchar();
            printf("������Ҫ�����Ԫ�أ�");
            scanf("%c", &element);
            InsertLinkStringElement(linkString1, index, element);
            printf("����1�в���Ԫ�سɹ�������������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            goto again;
        case 9:
            printf("��������Ҫɾ��Ԫ�ص�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 9����������ָ��λ��ɾ��Ԫ��
            printf("������Ҫɾ��Ԫ�ص�λ�ã�");
            scanf("%d", &index);
            DeleteLinkStringElement(linkString1, index);
            printf("����1��ɾ��Ԫ�سɹ���ɾ���������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            goto again;
        case 10:
            printf("��������Ҫ�滻Ԫ�ص�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 10����������ָ��λ���滻Ԫ��
            printf("������Ҫ�滻Ԫ�ص�λ�ã�");
            scanf("%d", &index);
            getchar();
            printf("������Ҫ�滻��Ԫ�أ�");
            scanf("%c", &element);
            ReplaceLinkStringElement(linkString1, index, element);
            printf("����1���滻Ԫ�سɹ����滻�������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            goto again;
        case 11:
            printf("��������Ҫ������������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 11����������
            TraverseLinkString(linkString1);
            goto again;
        case 12:
            printf("��������Ҫ���Ƶ�������\n");
            getchar();
            CreateLinkString(&linkString1);
            // 12�������ĸ���
            CopyLinkString(linkString1, &linkString3);
            printf("����1�Ѹ��Ƶ�����3������3Ϊ��\n");
            // ��ӡ����
            PrintLinkString(linkString3);
            goto again;
        case 13:
            printf("��������Ҫ���ӵ�����������\n");
            printf("����������1��");
            getchar();
            CreateLinkString(&linkString1);
            printf("����������2��");
            getchar();
            CreateLinkString(&linkString2);
            // 13������������
            ConcatLinkString(linkString1, linkString2, &linkString3);
            printf("����1�����ӵ�����2�����Ӻ������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            goto again;
        case 14:
            printf("��������Ҫ�Ƚϵ�����������\n");
            printf("����������1��");
            CreateLinkString(&linkString1);
            printf("����������2��");
            CreateLinkString(&linkString2);
            // 14�������ıȽ�
            if (!CompareLinkString(linkString1, linkString2)) {
                printf("����1������2��ȣ�\n");
            }
            else {
                printf("����1������2����ȣ�\n");
            }
            goto again;
        case 15:
            printf("��������Ҫ��ȡ��������\n");
            CreateLinkString(&linkString1);
            // 15�������Ľ�ȡ
            printf("������Ҫ��ȡ����������ʼλ�úͳ��ȣ�");
            int start, length;
            scanf("%d %d", &start, &length);
            SubLinkString(linkString1, start, length, &linkString3);
            printf("����1�ѽ�ȡ����ȡ�������Ϊ��\n");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 16:
            printf("��������Ҫ������������");
            getchar();
            CreateLinkString(&linkString1);
            // 16�������Ĳ���
            printf("������Ҫ���������ҵ��Ӵ���");
            getchar();
            CreateLinkString(&linkString3);
            if (IndexLinkString(linkString1, linkString3) == -1) {
                printf("�����������Ӵ���\n");
            }
            else {
                printf("���������Ӵ���\n");
            }
            goto again;
        case 17:
            printf("��������Ҫ�滻��������");
            getchar();
            CreateLinkString(&linkString1);
            // 17���������滻
            printf("������Ҫȥ�滻������");
            getchar();
            CreateLinkString(&linkString3);
            printf("������Ҫ�滻����1�Ӵ���λ�úͳ��ȣ�");
            scanf("%d %d", &start, &length);
            ReplaceLinkString(linkString1, start, length, linkString3);
            printf("����1���滻���滻�������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            getchar();
            goto again;
            break;
        case 18:
            // 18�������Ĳ���
            printf("������Ҫ�����������");
            getchar();
            CreateLinkString(&linkString3);
            printf("������Ҫ��������1��λ�ã�");
            scanf("%d", &index);
            InsertLinkString(linkString1, index, linkString3);
            printf("�Ѳ��뵽����1������������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            getchar();
            break;
        case 19:
            // 19��������ɾ��
            printf("������Ҫɾ����������λ�úͳ��ȣ�");
            scanf("%d %d", &index, &length);
            DeleteLinkString(linkString1, index, length);
            printf("����1��ɾ��ָ��Ƭ�Σ�ɾ���������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            getchar();
            break;
        case 20:
            // 20�������ķ�ת
            ReverseLinkString(linkString1);
            printf("����1�ѷ�ת����ת�������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            ReverseLinkString(linkString2);
            printf("����2�ѷ�ת����ת�������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString2);
            getchar();
            break;
        case 21:
            // 21������������
            SortLinkString(linkString1);
            printf("����1����������������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            SortLinkString(linkString2);
            printf("����2����������������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString2);
            getchar();
            break;
        case 22:
            // 22��������ȥ��
            DeduplicateLinkString(linkString1);
            printf("����1��ȥ�أ�ȥ�غ������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString1);
            DeduplicateLinkString(linkString2);
            printf("����2��ȥ�أ�ȥ�غ������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString2);
            getchar();
            break;
        case 23:
            // 23�������ĺϲ�
            MergeLinkString(linkString1, linkString2, &linkString3);
            printf("����1����2�Ѻϲ����ϲ��������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 24:
            // 24�������Ľ���
            IntersectLinkString(linkString1, linkString2, &linkString3);
            if (linkString3 == NULL) {
                printf("����1������2û�н�����\n");
                getchar();
                break;
            }
            printf("����1������2�����������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 25:
            // 25�������Ĳ���
            UnionLinkString(linkString1, linkString2, &linkString3);
            printf("����1������2�Ĳ���Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 26:
            // 26�������Ĳ
            DifferenceLinkString(linkString1, linkString2, &linkString3);
            printf("����1������2�ĲΪ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 27:
            SymmetricDifferenceLinkString(linkString1, linkString2, &linkString3);
            printf("����1������2�ĶԳƲΪ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 28:
            // 28���������Ӵ�
            printf("������Ҫ��ȡ������1��λ�úͳ��ȣ�");
            scanf("%d %d", &index, &length);
            SubStringLinkString(linkString1, index, length, &linkString3);
            printf("����1���Ӵ�Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 29:
            // 29��������������
            printf("������Ҫ��ȡ������1��λ�úͳ��ȣ�");
            scanf("%d %d", &index, &length);
            SubSequenceLinkString(linkString1, index, length, &linkString3);
            printf("����1��������Ϊ��");
            // ��ӡ����
            PrintLinkString(linkString3);
            getchar();
            break;
        case 0:
            // 0���˳�
            printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
            Exit();
            getchar();
            break;
        default:
            printf("�����������������룡\n");
            break;
        }
    again:
        printf("�Ƿ��������Y/N��");
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y') {
            continue;
        }
        else if (choice == 'N' || choice == 'n') {
            printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
            Exit();
            getchar();
            break;
        }
        else {
            printf("�����������������룡\n");
            goto again;
        }
    }

    return 0;
}