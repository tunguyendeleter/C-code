#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;

// trả về vị trí của node con trái có index là idx, index con trái = 2 * index + 1
int Left(int idx)
{
    int kq = 2 * idx + 1;
    if (kq < 0 || kq > 14) // kích thước của cây đầy đủ là 15: 4 mức
    {
        return -1;
    }
    return kq;
}
// trả về vị trí của node con phải có index là idx, index con phải = 2 * index + 2
int Right(int idx)
{
    int kq = 2 * idx + 2;
    if (kq < 0 || kq > 14) // kích thước của cây đầy đủ là 15: 4 mức
    {
        return -1;
    }
    return kq;
}
// tìm cha của một node với index của node đó
int TimCha(int idx)
{
    if (idx % 2 == 0)
    {
        return idx / 2 - 1; // néu index là chẵn: index / 2 - 1
    }
    return idx / 2; // néu index là lẻ: index / 2
}

// Bước 4: nhập dữ liệu vào cây
void NhapDuLieuNode(vector<char> &a, char *str)
{
    fflush(stdin);
    char data;
    printf("\nNhap du lieu node %s: ", str);
    scanf("%c", &data);
    a.push_back(data);
}

/*
nhập data cho cây nhị phân sử dụng queue
*/
void TaoCay(char *&a)
{
    // cấp phát phần tử cho cây: mức cây k
    int k;
    int len;
    do
    {
        printf("\nNhap so muc cho cay day du: ");
        scanf("%d", &k);
        if (k < 0)
        {
            printf("\nSo muc khong hop le");
        }
    } while (k < 0);
    len = pow(2.0, k);
    a = (char *)malloc(sizeof(char) * len);
    // khởi tạo giá trị ban đầu cho các phần tử của cây
    for (int i = 0; i < len - 1; i++)
    {
        a[i] = '?';
    }
    a[len - 1] = '\0';
    // cập nhật root
    fflush(stdin);
    printf("\nNhap node root: ");
    scanf("%c", &a[0]);
    // chọn số lượng con, con trái, con phải
    queue<int> q; // sử dụng queue lưu index để trỏ trực tiếp tới root cha
    q.push(0);
    // cập nhật node con
    while (!q.empty())
    {
        int idx_temp = q.front();
        printf("\nvi tri node = %d", idx_temp);
        q.pop();
        int SoCon;
        do
        {
            printf("\nNhap so luong con cho node %c: ", a[idx_temp]);
            scanf("%d", &SoCon);
            if (SoCon < 0 || SoCon > 2)
            {
                printf("\nSo luong chi tu 0 - 2");
                fflush(stdin);
            }
        } while (SoCon < 0 || SoCon > 2);
        if (SoCon == 1)
        {
            char luachon;
            do
            {
                fflush(stdin);
                printf("\nNhap node con trai hay con phai: ");
                scanf("%c", &luachon);
                if (luachon != 'r' && luachon != 'R' && luachon != 'l' && luachon != 'L')
                {
                    printf("\nNhap con trai: 'l' or 'L'");
                    printf("\nNhap con phai: 'r' or 'R'");
                }
            } while (luachon != 'r' && luachon != 'R' && luachon != 'l' && luachon != 'L');
            fflush(stdin);
            if (luachon == 'l' || luachon == 'L') // con trái: 2*idx + 1
            {
                printf("\nNhap node con trai: ");
                scanf("%c", &a[idx_temp * 2 + 1]);
                q.push(idx_temp * 2 + 1);
            }
            else // con phải: 2*idx + 2
            {
                printf("\nNhap node con phai: ");
                scanf("%c", &a[idx_temp * 2 + 2]);
                q.push(idx_temp * 2 + 2);
            }
        }
        else if (SoCon == 2)
        {
            fflush(stdin);
            printf("\nNhap node con trai: ");
            scanf("%c", &a[idx_temp * 2 + 1]);
            q.push(idx_temp * 2 + 1);

            fflush(stdin);
            printf("\nNhap node con phai: ");
            scanf("%c", &a[idx_temp * 2 + 2]);
            q.push(idx_temp * 2 + 2);
        }
    }
}

/*
duyệt theo chiều rộng, thutu = 1: trái -> phải, else: phải -> trái
*/
void DuyetTheoChieuRong(char a[], int thutu = 1)
{
    queue<int> q;
    int len = strlen(a);
    if (len == 0)
    {
        return;
    }
    q.push(0);
    while (!q.empty()) // lặp lại liên tục khi hàng đợi còn phần tử
    {
        int idx_temp = q.front();
        q.pop();
        if (thutu == 1)
        {
            if (idx_temp * 2 + 1 >= 0 && idx_temp * 2 + 1 < len)
            {
                q.push(Left(idx_temp));
            }
            if (idx_temp * 2 + 2 >= 0 && idx_temp * 2 + 2 < len)
            {
                q.push(Right(idx_temp));
            }
        }
        else
        {
            if (idx_temp * 2 + 2 >= 0 && idx_temp * 2 + 2 < len)
            {
                q.push(Right(idx_temp));
            }
            if (idx_temp * 2 + 1 >= 0 && idx_temp * 2 + 1 < len)
            {
                q.push(Left(idx_temp));
            }
        }
        if (a[idx_temp] != '?')
        {
            printf("%c", a[idx_temp]);
        }
    }
}

/*
duyệt Preorder, thứ tự = 1: (node left right), khác 1: (node right left)
*/
void PreOrder(char *a, int thutu = 1, int x = 0)
{
    if (thutu == 1)
    {
        if (x >= 0 && x < strlen(a))
        {
            if (a[x] != '?')
            {
                printf("%c", a[x]);
            }
            PreOrder(a, thutu, x * 2 + 1);
            PreOrder(a, thutu, x * 2 + 2);
        }
    }
    else
    {
        if (x >= 0 && x < strlen(a))
        {
            if (a[x] != '?')
            {
                printf("%c", a[x]);
            }
            PreOrder(a, thutu, x * 2 + 2);
            PreOrder(a, thutu, x * 2 + 1);
        }
    }
}

/*
duyệt InOrder, thứ tự = 1: (left node right), khác 1: (right node left)
*/
void InOrder(char *a, int thutu = 1, int x = 0)
{
    if (thutu == 1)
    {
        if (x >= 0 && x < strlen(a))
        {
            InOrder(a, thutu, x * 2 + 1);
            if (a[x] != '?')
            {
                printf("%c", a[x]);
            }
            InOrder(a, thutu, x * 2 + 2);
        }
    }
    else
    {
        if (x >= 0 && x < strlen(a))
        {
            InOrder(a, thutu, x * 2 + 2);
            if (a[x] != '?')
            {
                printf("%c", a[x]);
            }
            InOrder(a, thutu, x * 2 + 1);
        }
    }
}

/*
duyệt PostOrder, thứ tự = 1: (left right node), khác 1: (right left node)
*/
void PostOrder(char *a, int thutu = 1, int x = 0)
{
    if (thutu == 1)
    {
        if (x >= 0 && x < strlen(a))
        {
            PostOrder(a, thutu, x * 2 + 1);
            PostOrder(a, thutu, x * 2 + 2);
            if (a[x] != '?')
            {
                printf("%c", a[x]);
            }
        }
    }
    else
    {
        if (x >= 0 && x < strlen(a))
        {
            PostOrder(a, thutu, x * 2 + 2);
            PostOrder(a, thutu, x * 2 + 1);
            if (a[x] != '?')
            {
                printf("%c", a[x]);
            }
        }
    }
}

/*
đếm tổng các node trên cây
*/
void DemTongCacNodeTrenCay(char *a, int &dem, int x = 0)
{
    if (x >= 0 && x < strlen(a))
    {
        if (a[x] != '?')
        {
            dem++;
        }
        DemTongCacNodeTrenCay(a, dem, x * 2 + 1);
        DemTongCacNodeTrenCay(a, dem, x * 2 + 2);
    }
}

int main()
{
    // char *a;
    // TaoCay(a);
    // printf("\n%s", a);
    // int k = 4; // có 4 mức
    char *a = (char *)malloc((pow(2.0, 4)) * sizeof(char)); // cấp phát 16 phần từ: dư 1 phần tử '\0' kết thúc chuỗi
    a[0] = 'A';
    a[1] = 'B';
    a[2] = 'C';
    a[3] = 'D';
    a[4] = 'E';
    a[5] = 'F';
    a[6] = 'G';
    a[7] = 'H';
    a[8] = 'I';
    a[9] = '?';
    a[10] = 'J';
    a[11] = 'K';
    a[12] = '?';
    a[13] = '?';
    a[14] = 'L';
    a[15] = '\0';
    printf("\nDuyet theo chieu rong: \n");
    DuyetTheoChieuRong(a);
    printf("\nDuyet truoc: \n");
    PreOrder(a);
    printf("\nDuyet giua: \n");
    InOrder(a);
    printf("\nDuyet sau: \n");
    PostOrder(a);
    int dem = 0;
    DemTongCacNodeTrenCay(a, dem);
    printf("\nTong cac node tren cay: %d", dem);
    free(a); // giai phong cay

    // printf("\nDuyet sau: \n");
    // PostOrder(a);

    // printf("\nRoot = %c", a[0]);
    // printf("\nRoot->left = %c", a[Left(0)]);
    // printf("\nRoot->right = %c", a[Right(0)]);

    // printf("\nRoot->left->left = %c", a[Left(Left(0))]);
    // printf("\nRoot->left->right = %c", a[Right(Left(0))]);

    // printf("\nRoot->left->right->right = %c", a[Right(Right(Left(0)))]);
    // printf("\nRoot->left->right->left = %c", a[Left(Right(Left(0)))]);
    // printf("\nRoot->left->left->left = %c", a[Left(Left(Left(0)))]);
    // if (Left(Left(Left(Left(0)))) != -1)
    // {
    //     printf("\nRoot->left->left->left->left = %c", a[Left(Left(Left(Left(0))))]);
    // }

    // int idx = 6;
    // if (TimCha(idx) == -1)
    // {
    //     printf("\nNode %c khong co cha", a[idx]);
    // }
    // else
    // {
    //     printf("\nCha cua node %c la %c", a[idx], a[TimCha(idx)]);
    // }

    return 0;
}