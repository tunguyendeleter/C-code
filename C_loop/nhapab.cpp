#include <stdio.h>
#include <conio.h>

int main()
{
    int a, b;

    /*
    vong thu nhat diem bat dau
    vong thu hai diem ket thuc => add diem ket thuc vao diem bat dau truoc do
    check diem bat dau la so chinh phuong,...
    */
    do
    {
        printf("\nNhap a: ");
        scanf("%d", &a);
    } while (a < 0);
    do
    {
        printf("\nNhap b: ");
        scanf("%d", &b);
    } while (b < a);
    int sohientai;
    int demchinhphuong = 0;
    int demnguyento = 0;
    int demsodoi = 0;
    for (int i = a; i <= b; i++)
    {
        sohientai = i;
        for (int j = i; j <= b; j++)
        {
            if (i != j)
            {
                sohientai *= 10;
                sohientai += j;
            }
            for (int k = 1; k < sohientai; k++)
            {
                if (k * k == sohientai)
                {
                    demchinhphuong++;
                    break;
                }
            }
            for (int k = 2; k < sohientai; k++)
            {
                if (sohientai % k == 0)
                {
                    demnguyento++;
                    break;
                }
            }
            int temp = sohientai;
            int sodoi = 0;
            while (temp > 0)
            {
                sodoi *= 10;
                sodoi += temp % 10;
                temp /= 10;
            }
            if (sodoi == sohientai)
            {
                demsodoi++;
            }
        }
    }
    printf("\nSo doi la: %d", demsodoi);
    printf("\nSo chinh phuong la: %d", demchinhphuong);
    printf("\nSo nguyen to la: %d", demnguyento);

    getch();
    return 0;
}