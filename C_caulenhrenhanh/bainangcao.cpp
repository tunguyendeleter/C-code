#include <stdio.h>
#include <conio.h>
#define TIEN 30000

int main()
{
    float giobd, phutbd, giokt, phutkt, phutvang;
    float gio, phut;
    float donvi = TIEN / 3 / 60;
    printf("\nNhap gio bat dau: ");
    scanf("%f", &giobd);
    if (giobd < 8 || giobd > 24)
    {
        printf("\nGio bat dau khong hop le !");
        return 0;
    }
    printf("\nNhap phut bat dau: ");
    scanf("%f", &phutbd);
    printf("\nNhap gio ket thuc: ");
    scanf("%f", &giokt);
    if (giobd < 8 || giobd > 24)
    {
        printf("\nGio ket thuc khong hop le !");
        return 0;
    }
    printf("\nNhap phut ket thuc: ");
    scanf("%f", &phutkt);

    if (giobd > giokt || (giobd == giokt && phutbd > phutkt))
    {
        printf("\nThoi gian bat dau khong duoc lon hon thoi gian ket thuc !");
        return 0;
    }
    if (giobd < giokt && phutbd < phutkt)
    {
        gio = giokt - giobd;
        phut = phutkt - phutbd;
    }
    else
    {
        gio = giokt - giobd - 1;
        phut = 60 - (giobd - giokt);
    }

    if (giobd >= 8 && giobd <=17)
    {
        phutvang = (17 - giobd)*60 - phutbd;
    }

    if (giobd >= 8 && giobd < 14)
    {
        if (gio < 3)
        {
            float thanhtoan = (donvi * 0.9) * (gio * 60 + phut);
            printf("\nSo tien phai tra la: %f", thanhtoan);
        }
        else
        {
            float thanhtoan = (donvi * 0.6) * (3 * 60 + phut);
            thanhtoan = (donvi * 0.9) * (gio * 60 + phut);
            printf("\nSo tien phai tra la: %f", thanhtoan);
        }
    }

    getch();
    return 0;
}