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
#include <time.h>
#include <math.h>
#include <string.h>
using namespace std;

// Bước 1: khai báo cấu trúc dữ liệu cây
struct Node
{
    int Data;
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
đếm số lượng các node trên cây
*/
int DemSoLuongCacNodeTrenCay_DeQuy(NODE *Root)
{
    if (Root == NULL)
    {
        return 0;
    }
    return 1 + DemSoLuongCacNodeTrenCay_DeQuy(Root->Left) + DemSoLuongCacNodeTrenCay_DeQuy(Root->Right);
}

void DemSoLuongCacNodeTrenCay_DeQuyDuoi(NODE *Root, int &dem) // hàm ko chạy 2 lần như stack
{
    if (Root != NULL)
    {
        dem++;
        DemSoLuongCacNodeTrenCay_DeQuyDuoi(Root->Left, dem);
        DemSoLuongCacNodeTrenCay_DeQuyDuoi(Root->Right, dem);
    }
}

int DemSoLuongCacNodeTrenCay_HuyDeQuy(NODE *Root)
{
    if (Root == NULL)
    {
        return 0;
    }
    queue<NODE *> q;
    q.push(Root);
    int dem = 0;
    while (!q.empty()) // lặp lại liên tục khi hàng đợi còn phần tử
    {
        dem++;
        NODE *temp = q.front();
        q.pop();
        if (temp->Left != NULL)
        {
            q.push(temp->Left);
        }
        if (temp->Right != NULL)
        {
            q.push(temp->Right);
        }
    }
    return dem;
}

/*
tính bậc của một node, kiểm tra các node con có tồn tại hay không
*/
int TinhBacCuaNode(NODE *node)
{
    int dem = 0;
    if (node->Left != NULL)
    {
        dem++;
    }
    if (node->Right != NULL)
    {
        dem++;
    }
    return dem;
}
/*
tính bậc của một cây, bậc của một cây là bậc cao nhất của các node trong cây
*/
void TinhBacCuaCay(NODE *root, int &max)
{
    if (root != NULL)
    {
        int bac = TinhBacCuaNode(root);
        if (max < bac)
        {
            max = bac;
            if (max == 2)
            {
                return;
            }
        }
        TinhBacCuaCay(root->Left, max);
        TinhBacCuaCay(root->Right, max);
    }
}

/*
tính chiều cao của cây
*/
int TinhChieuCao(NODE *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = TinhChieuCao(root->Left);
    int right = TinhChieuCao(root->Right);
    return left > right ? (left + 1) : (right + 1);
}

void TinhChieuCao_DeQuyDuoi(NODE *root, int &max, int level = 1)
{
    if (root != NULL)
    {
        if (max < level)
        {
            max = level;
        }
        TinhChieuCao_DeQuyDuoi(root->Left, max, level + 1);
        TinhChieuCao_DeQuyDuoi(root->Right, max, level + 1);
    }
}
/*
tìm xem node có tồn tại hay không, nếu có trả về độ sâu của node(mức của node đang đứng)
*/
void KiemTraNodeCoTonTai(NODE *root, int data, bool &check, int &dosau, int level)
{
    if (root != NULL && check == false) // thêm điều kiện dê ngưng toàn bộ quá trình đệ quy
    {
        // printf("%c ", root->Data);
        if (root->Data == data)
        {
            check = true;
            dosau = level;
            return; // tiết kiệm 2 lần chạy đệ quy bên dưới
        }
        level++;
        KiemTraNodeCoTonTai(root->Left, data, check, dosau, level);
        KiemTraNodeCoTonTai(root->Right, data, check, dosau, level);
    }
}

/*
viết hàm xuất tất cả các node trên tầng thứ k của cây
*/
void XuatTatCaCacNodeTangThuK(NODE *root, int k, int &dem, int level = 1)
{
    if (root != NULL && level <= k)
    {
        if (level == k)
        {
            printf("%c ", root->Data);
            dem++;
        }
        XuatTatCaCacNodeTangThuK(root->Left, k, dem, level + 1);
        XuatTatCaCacNodeTangThuK(root->Right, k, dem, level + 1);
    }
}
void XuatTatCaCacNodeTangThuK_HuyDeQuy_SuDungQueue(NODE *root, int k, int &dem)
{
    if (root == NULL)
    {
        return;
    }
    int docao = 1;
    queue<NODE *> q;
    queue<int> chieucao_q;
    q.push(root);
    chieucao_q.push(1);
    while (!q.empty())
    {
        NODE *temp = q.front();
        q.pop();
        docao = chieucao_q.front();
        chieucao_q.pop();
        if (docao == k)
        {
            printf("%c ", temp->Data);
            dem++;
        }

        if (temp->Left != NULL)
        {
            q.push(temp->Left);
            chieucao_q.push(docao + 1);
        }
        if (temp->Right != NULL)
        {
            q.push(temp->Right);
            chieucao_q.push(docao + 1);
        }
    }
}
void XuatTatCaCacNodeMoiTang(NODE *root)
{
    int sobac = TinhChieuCao(root);
    for (int i = 1; i <= sobac; i++)
    {
        int dem = 0;
        printf("\nTang %d:", i);
        XuatTatCaCacNodeTangThuK(root, i, dem);
        printf("=> count = %d", dem);
    }
}
void XuatTatCaCacNodeMoiTang_SuDungQueue(NODE *root)
{
    int sobac = 0;
    TinhChieuCao_DeQuyDuoi(root, sobac);
    for (int i = 1; i <= sobac; i++)
    {
        int dem = 0;
        printf("\nTang %d:", i);
        XuatTatCaCacNodeTangThuK_HuyDeQuy_SuDungQueue(root, i, dem);
        printf("=> count = %d", dem);
    }
}
void XuatTatCaCacNodeTheoDieuKien(NODE *root, char *str, int k, int level = 1)
{
    if (root != NULL)
    {
        bool check = false;
        if (!strcmp(str, "<")) // strcmp(str, "<") == 0
            check = (level < k);
        else if (!strcmp(str, "<="))
            check = (level <= k);
        else if (!strcmp(str, "=="))
            check = (level == k);
        else if (!strcmp(str, ">"))
            check = (level > k);
        else if (!strcmp(str, ">="))
            check = (level >= k);

        if (check)
        {
            printf("%c ", root->Data);
        }
        XuatTatCaCacNodeTheoDieuKien(root->Left, str, k, level + 1);
        XuatTatCaCacNodeTheoDieuKien(root->Right, str, k, level + 1);
    }
}
/*
viết hàm xuất tất cả các node trên cây theo thứ tự từ tầng 1 đến tầng k của cây(k là chiều cao của cây)
*/
void XuatTatCaCacNodeTuTang1DenK(NODE *root, int k, int &dem, int level = 1)
{
    if (root != NULL && level <= k)
    {
        if (level <= k)
        {
            printf("%c ", root->Data);
            dem++;
        }

        XuatTatCaCacNodeTuTang1DenK(root->Left, k, dem, level + 1);
        XuatTatCaCacNodeTuTang1DenK(root->Right, k, dem, level + 1);
    }
}

/*
viết hàm xuất tất cả các node trên cây theo thứ tự từ tầng 1 đến tầng k của cây(k là chiều cao của cây)
*/
void XuatTatCaCacNodeDuoiTangK(NODE *root, int k, int &dem, int level = 1)
{
    if (root != NULL)
    {
        if (level > k)
        {
            printf("%c ", root->Data);
            dem++;
        }

        XuatTatCaCacNodeDuoiTangK(root->Left, k, dem, level + 1);
        XuatTatCaCacNodeDuoiTangK(root->Right, k, dem, level + 1);
    }
}

/*
tạo cây đầy đủ được đánh số có mức k = n
*/
void TaoCayNhiPhanDayDu(NODE *&root, int k)
{
    int len = pow(2.0, k) - 1;
    queue<NODE *> q;
    q.push(root);
    while (true)
    {
        NODE *temp = q.front();
        q.pop();
        int data = temp->Data - 48;
        if (data * 2 > len)
        {
            break;
        }
        temp->Left = GetNode(data * 2 + 48);
        temp->Right = GetNode(data * 2 + 49);
        q.push(temp->Left);
        q.push(temp->Right);
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
    NODE *M = GetNode('M');
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
    L->Right = M;

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
    printf("\nTong cac node tren cay: %d", DemSoLuongCacNodeTrenCay_HuyDeQuy(Root));
    printf("\nBac cua node %c: %d", B->Data, TinhBacCuaNode(B));
    int max = 0;
    TinhBacCuaCay(Root, max);
    printf("\nBac cua cay: %d", max);
    int chieucao = 0;
    TinhChieuCao_DeQuyDuoi(Root, chieucao);
    printf("\nChieu cao cua cay %c: %d", Root->Data, chieucao);
    bool check = false;
    int dosau = 1;
    KiemTraNodeCoTonTai(Root, 'D', check, dosau, 1);
    if (check)
    {
        printf("\nNode co ton tai");
        printf("\nDo sau cua node la: %d", dosau);
    }
    else
    {
        printf("\nNode khong ton tai");
    }

    // XuatTatCaCacNodeMoiTang(Root);
    XuatTatCaCacNodeMoiTang_SuDungQueue(Root);
    char *str = "<";
    printf("\nCac node voi dieu kien \"%s\": ", str);
    XuatTatCaCacNodeTheoDieuKien(Root, str, 3);
    // int k = 3;
    // int dem2 = 0;
    // printf("\nCac node tu tang 1 den tang %d\n", k);
    // XuatTatCaCacNodeTuTang1DenK(Root, k, dem2);
    // printf("\nSo luong cac node tu tang 1 den k: %d", dem2);
    // int dem3 = 0;
    // printf("\nCac node tu tang %d xuong duoi\n", k);
    // XuatTatCaCacNodeDuoiTangK(Root, k, dem3);
    // printf("\nSo luong cac node duoi tang k: %d", dem3);
    // tạo cây nhị phân đầy đủ
    // NODE *root = GetNode('1');
    // int k = 7;
    // TaoCayNhiPhanDayDu(root, k);
    // clock_t start2 = clock();
    // for (int i = 0; i < 1000000000; i++)
    // {
    //     DemSoLuongCacNodeTrenCay_DeQuy(Root);
    // }
    // clock_t end2 = clock();
    // printf("\nDemSoLuongCacNodeTrenCay_DeQuy chay mat %lf giay", (double)(end2 - start2) / CLOCKS_PER_SEC);

    // clock_t start1 = clock();
    // int dem = 0;
    // for (int i = 0; i < 1000000000; i++)
    // {
    //     DemSoLuongCacNodeTrenCay_DeQuyDuoi(Root, dem);
    // }
    // clock_t end1 = clock();
    // printf("\nDemSoLuongCacNodeTrenCay_DeQuyDuoi chay mat %lf giay", (double)(end1 - start1) / CLOCKS_PER_SEC);

    // clock_t start3 = clock();
    // for (int i = 0; i < 1000000000; i++)
    // {
    //     DemSoLuongCacNodeTrenCay_HuyDeQuy(Root);
    // }
    // clock_t end3 = clock();
    // printf("\nDemSoLuongCacNodeTrenCay_HuyDeQuy chay mat %lf giay", (double)(end3 - start3) / CLOCKS_PER_SEC);

    RemoveAll(Root);
    return 0;
}
