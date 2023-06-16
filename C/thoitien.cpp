#include <stdio.h>
#include <conio.h>
#define namtramngan 500000
#define haitramngan 200000
#define mottramngan 100000
#define namchucngan 50000
#define haichucngan 20000
#define motchucngan 10000
#define namngan 5000
#define haingan 2000
#define motngan 1000
#define namtram 500


int main()
{
    int mondo, tientra, tienthoi;
    do
    {
        printf("\nNhap so tien mon do: ");
        scanf("%d", &mondo);
    } while (mondo < 0);
    do
    {
        printf("\nNhap so tien phai tra: ");
        scanf("%d", &tientra);
    } while (tientra < mondo);
    tienthoi = tientra - mondo;
    while (tienthoi > 0)
    {
        if (tienthoi >= namtramngan)
        {
            int soto = tienthoi / namtramngan;
            tienthoi -= soto*namtramngan;
            printf("\n%d to nam tram ngan", soto);
        }
        if (tienthoi >= haitramngan)
        {
            int soto = tienthoi / haitramngan;
            tienthoi -= soto*haitramngan;
            printf("\n%d to hai tram ngan", soto);
        }
        if (tienthoi >= mottramngan)
        {
            int soto = tienthoi / mottramngan;
            tienthoi -= soto*mottramngan;
            printf("\n%d to mot tram ngan", soto);
        }
        if (tienthoi >= namchucngan)
        {
            int soto = tienthoi / namchucngan;
            tienthoi -= soto*namchucngan;
            printf("\n%d to nam chuc ngan", soto);
        }
        if (tienthoi >= haichucngan)
        {
            int soto = tienthoi / haichucngan;
            tienthoi -= soto*haichucngan;
            printf("\n%d to hai chuc ngan", soto);
        }
        if (tienthoi >= motchucngan)
        {
            int soto = tienthoi / motchucngan;
            tienthoi -= soto*motchucngan;
            printf("\n%d to mot chuc ngan", soto);
        }
        if (tienthoi >= namngan)
        {
            int soto = tienthoi / namngan;
            tienthoi -= soto*namngan;
            printf("\n%d to nam ngan", soto);
        }
        if (tienthoi >= haingan)
        {
            int soto = tienthoi / haingan;
            tienthoi -= soto*haingan;
            printf("\n%d to hai ngan", soto);
        }
        if (tienthoi >= motngan)
        {
            int soto = tienthoi / motngan;
            tienthoi -= soto*motngan;
            printf("\n%d to mot ngan", soto);
        }
        if (tienthoi >= namtram)
        {
            int soto = tienthoi / namtram;
            tienthoi -= soto*namtram;
            printf("\n%d to nam tram", soto);
        }
        
    }
    

    getch();
    return 0;
}