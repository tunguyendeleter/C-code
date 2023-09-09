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

/*
nhập data cho cây nhị phân sử dụng queue
*/
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

// Bước 5: những xử lý cần có trên cây
/*
duyệt theo chiều rộng, thutu = 1: trái -> phải, else: phải -> trái
*/
void DuyetTheoChieuRong(NODE *Root, int thutu = 1)
{
    if (Root == NULL)
    {
        return;
    }
    queue<NODE *> q;
    q.push(Root);
    while (!q.empty()) // lặp lại liên tục khi hàng đợi còn phần tử
    {
        NODE *temp = q.front();
        q.pop();
        if (thutu == 1)
        {
            if (temp->Left != NULL)
            {
                q.push(temp->Left);
            }
            if (temp->Right != NULL)
            {
                q.push(temp->Right);
            }
        }
        else
        {
            if (temp->Right != NULL)
            {
                q.push(temp->Right);
            }
            if (temp->Left != NULL)
            {
                q.push(temp->Left);
            }
        }
        printf("%4c", temp->Data);
    }
}
/*
duyệt Preorder, thứ tự = 1: (node left right), khác 1: (node right left)
*/
void PreOrder(NODE *Root, int thutu = 1)
{
    if (thutu == 1)
    {
        if (Root != NULL)
        {
            printf("%4c", Root->Data);
            PreOrder(Root->Left, thutu);
            PreOrder(Root->Right, thutu);
        }
    }
    else
    {
        if (Root != NULL)
        {
            printf("%4c", Root->Data);
            PreOrder(Root->Right, thutu);
            PreOrder(Root->Left, thutu);
        }
    }
}
/*
duyệt InOrder, thứ tự = 1: (left node right), khác 1: (right node left)
*/
void InOrder(NODE *Root, int thutu = 1)
{
    if (thutu == 1)
    {
        if (Root != NULL)
        {
            InOrder(Root->Left, thutu);
            printf("%4c", Root->Data);
            InOrder(Root->Right, thutu);
        }
    }
    else
    {
        if (Root != NULL)
        {
            InOrder(Root->Right, thutu);
            printf("%4c", Root->Data);
            InOrder(Root->Left, thutu);
        }
    }
}
/*
duyệt PostOrder, thứ tự = 1: (left right node), khác 1: (right left node)
*/
void PostOrder(NODE *Root, int thutu = 1)
{
    if (thutu == 1)
    {
        if (Root != NULL)
        {
            PostOrder(Root->Left, thutu);
            PostOrder(Root->Right, thutu);
            printf("%4c", Root->Data);
        }
    }
    else
    {
        if (Root != NULL)
        {
            PostOrder(Root->Right, thutu);
            PostOrder(Root->Left, thutu);
            printf("%4c", Root->Data);
        }
    }
}
/*
đếm tổng các node trên cây
*/
void DemTongCacNodeTrenCay(NODE *Root, int &dem)
{
    if (Root != NULL)
    {
        dem++;
        DemTongCacNodeTrenCay(Root->Left, dem);
        DemTongCacNodeTrenCay(Root->Right, dem);
    }
}

// Bước 6: giải phong cây
void RemoveAll(NODE *&Root)
{
    if (Root != NULL)
    {
        RemoveAll(Root->Left);
        RemoveAll(Root->Right);
        free(Root);
        Root = NULL;
    }
}

int main()
{

    // Bước 4: nhập dữ liệu vào cây
    NODE *Root = GetNode('A');
    NODE *B = GetNode('B');
    NODE *C = GetNode('C');
    NODE *D = GetNode('D');
    NODE *E = GetNode('E');
    NODE *F = GetNode('F');
    NODE *G = GetNode('G');
    NODE *H = GetNode('H');
    NODE *I = GetNode('I');
    NODE *J = GetNode('J');
    NODE *K = GetNode('K');
    NODE *L = GetNode('L');
    Root->Left = B;
    Root->Right = C;
    B->Left = D;
    B->Right = E;
    C->Left = F;
    C->Right = G;
    D->Left = H;
    D->Right = I;
    E->Right = J;
    F->Left = K;
    G->Right = L;

    // TaoCay(Root);
    /*===========================*/
    printf("\nDuyet theo chieu rong: \n");
    DuyetTheoChieuRong(Root);
    printf("\nDuyet truoc: \n");
    PreOrder(Root);
    printf("\nDuyet giua: \n");
    InOrder(Root);
    printf("\nDuyet sau: \n");
    PostOrder(Root);
    int dem = 0;
    DemTongCacNodeTrenCay(Root, dem);
    printf("\nTong cac node tren cay: %d", dem);
    RemoveAll(Root);

    printf("\nDuyet theo chieu rong: \n");
    DuyetTheoChieuRong(Root);
    printf("\nDuyet truoc: \n");
    PreOrder(Root);
    printf("\nDuyet giua: \n");
    InOrder(Root);
    printf("\nDuyet sau: \n");
    PostOrder(Root);


    return 0;
}
