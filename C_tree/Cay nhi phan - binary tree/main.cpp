/*
Bước 1: khai báo cấu trúc dữ liệu cây nhị phân
Bước 2: khởi tạo cây
Bước 3: tạo Node trong cây
Bước 4: nhập dữ liệu vào cây
Bước 5: những xử lý cần có trên cây
Bước 6: giải phong cây
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

// Bước 1: khai báo cấu trúc dữ liệu cây
struct Node
{
    char Data;
    struct Node *Left, *Right;
};
typedef struct Node NODE;
// Bước 2: khởi tạo cây
void Init(NODE *&Root)
{
    Root = NULL;
}
// Bước 3: tạo Node trong cây
NODE *GetNode(char x) // x là dữ liệu nhập vào
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL) // kiểm tra cấp phát thành công
    {
        return NULL;
    }
    p->Data = x;
    p->Left = p->Right = NULL;
    return p;
}
// Bước 4: nhập dữ liệu vào cây
void NhapDuLieuNode(NODE *&node, char *str)
{
    fflush(stdin);
    char data;
    printf("\nNhap du lieu node %s: ", str);
    scanf("%c", &data);
    node = GetNode(data);
}

void TaoCay(NODE *&Root)
{
    // nhập node gốc
    NhapDuLieuNode(Root, "root");
    queue<NODE *> q;
    q.push(Root);
    // nhập node con sử dụng queue
    while (!q.empty())
    {
        NODE *temp = q.front();
        q.pop();
        int SoCon;
        do
        {
            printf("\nNhap so con cua node %c (0 hay 1 hay 2): ", temp->Data);
            scanf("%d", &SoCon);
            if (SoCon < 0 || SoCon > 2)
            {
                printf("\nSo con chi co the 0 hay 1 hay 2");
            }
        } while (SoCon < 0 || SoCon > 2);
        if (SoCon == 1)
        {
            char RL;
            do
            {
                fflush(stdin);
                printf("\nBan muon nhap con trai - L hay con right - R: ");
                scanf("%c", &RL);
                if (RL != 'L' && RL != 'R' && RL != 'l' && RL != 'r')
                {
                    printf("\nChi nhap l or L cho con left, r or R cho con right");
                }
            } while (RL != 'L' && RL != 'R' && RL != 'l' && RL != 'r');
            NODE *node;
            if (RL == 'l' || RL == 'L')
            {
                NhapDuLieuNode(node, "trai");
                temp->Left = node;
            }
            else
            {
                NhapDuLieuNode(node, "phai");
                temp->Right = node;
            }
            q.push(node);
        }
        else if (SoCon == 2)
        {
            NODE *r, *l;
            NhapDuLieuNode(l, "trai");
            temp->Left = l;
            q.push(l);

            NhapDuLieuNode(r, "phai");
            temp->Right = r;
            q.push(r);
        }
    }
}

int main()
{

    // Bước 4: nhập dữ liệu vào cây
    NODE *Root;
    TaoCay(Root);
    /*===========================*/
    printf("\n%c", Root->Data);
    printf("\n%c", Root->Left->Data);
    printf("\n%c", Root->Right->Data);
    printf("\n%c", Root->Left->Left->Data);
    printf("\n%c", Root->Left->Right->Data);
    printf("\n%c", Root->Right->Left->Data);
    printf("\n%c", Root->Right->Right->Data);

    printf("\n%c", Root->Left->Left->Left->Data);
    printf("\n%c", Root->Left->Left->Right->Data);

    printf("\n%c", Root->Left->Right->Right->Data);

    printf("\n%c", Root->Right->Left->Left->Data);
    printf("\n%c", Root->Right->Right->Right->Data);

    return 0;
}
