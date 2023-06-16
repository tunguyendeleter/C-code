#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n;
    int check=0;
    printf("\nNhap vao n: ");
    scanf("%d", &n);
    if (n<0)
    {
        check = 1;
        n *= -1;
    }
    if((int)log10(n) + 1 != 3){
        printf("\nso vua nhap khong phai so co 3 chu so ");
        return 0;
    }
    
    int hangtram = n/100;
    n = n%100;
    int hangchuc = n/10;
    n = n%10;
    int hangdonvi = n;
    if(check == 1){
        printf("\nAm ");
    }
    if(hangtram == 1){
        printf("\nMot tram ");
    }  
    else if(hangtram == 2){
        printf("\nHai tram ");
    }
    else if(hangtram == 3){
        printf("\nBa tram ");
    }
    else if(hangtram == 4){
        printf("\nBon tram ");
    }
    else if(hangtram == 5){
        printf("\nNam tram ");
    }
    else if(hangtram == 6){
        printf("\nSau tram ");
    }
    else if(hangtram == 7){
        printf("\nBay tram ");
    }
    else if(hangtram == 8){
        printf("\nTam tram ");
    }
    else{
        printf("\nChin tram ");
    }


    
    if(hangchuc == 1){
        printf("\nMuoi ");
    }  
    else if(hangchuc == 2){
        printf("\nHai muoi ");
    }
    else if(hangchuc == 3){
        printf("\nBa muoi ");
    }
    else if(hangchuc == 4){
        printf("\nBon muoi ");
    }
    else if(hangchuc == 5){
        printf("\nNam muoi ");
    }
    else if(hangchuc == 6){
        printf("\nSau muoi ");
    }
    else if(hangchuc == 7){
        printf("\nBay muoi ");
    }
    else if(hangchuc == 8){
        printf("\nTam muoi ");
    }
    else{
        printf("\nChin muoi ");
    }
    
    
    if(hangdonvi == 1){
        printf("\nMot ");
    }  
    else if(hangdonvi == 2){
        printf("\nHai");
    }
    else if(hangdonvi == 3){
        printf("\nBa");
    }
    else if(hangdonvi == 4){
        printf("\nBon");
    }
    else if(hangdonvi == 5){
        printf("\nNam");
    }
    else if(hangdonvi == 6){
        printf("\nSau");
    }
    else if(hangdonvi == 7){
        printf("\nBay");
    }
    else if(hangdonvi == 8){
        printf("\nTam");
    }
    else{
        printf("\nChin");
    }

    getch();
    return 0;
}