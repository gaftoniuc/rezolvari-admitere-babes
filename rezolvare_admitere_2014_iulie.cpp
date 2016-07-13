/*Fie sirul X=(1,2,3,4,2,5,6,2,3,7,8,2,4,9,3,10,2,5,11,12,2,3,4,6,13...) obtinut din sirul numerelor
naturale nenule prin inserarea dupa fiecare numar a divizorilor sai proprii.Scrieti un program care citeste
de la tastatura un numar natural n (2<n<9), construieste o matrice A cu n linii si n coloane, formata
din cifre in felul urmator:
-un element a(ij) al matricei de deasupra diagonalei secundare va fi ultima cifra a numarului de pe pozitia
n^2+i+j din sirul X.
-un element a(ij) al matricei de sub diagonala secundara va fii prima cifra a numarului de pe pozitia
n^2+i+j din sirul X.
un element situat pe diagonala secundara a matricei pe linia i va fi cifra maxima a numarului de pe pozitia
n^2+i^2 din sirul X.
si apoi pentru fiecare coloana a matricei A se afiseaza cel mai mare numar zecimal format din cifrele de pe coloana
respectiva*/
#include <iostream>
#define usi unsigned int
using namespace std;
int divizor(usi sir_generat[], usi dimensiune_sir_generat)
{
    usi i=1, j=1;
    while(j<=dimensiune_sir_generat)
    {
        sir_generat[j++]=i; //primul element este numarul propriu-zis
        for(usi divizor=2; divizor<i; divizor++)
            if(i%divizor==0)
                sir_generat[j++]=divizor; //completam sirul cu divizorii sai
        i++; //incrementam elementul
    }
}
int prima_cifra(usi numar)
{
    if(numar<9)
        return numar;
    else
    {
        while(numar>9)
            numar/=10;
    }
    return numar;
}
int ultima_cifra(usi numar)
{
    return numar%10;
}
int cifra_maxima(int numar)
{
    int maxim=-1;
    while(numar>0)
    {
        if(numar%10>maxim)
        {
            maxim=numar%10;
        }

        numar=numar/10;
    }
    return maxim;
}
int construirea_matricei(usi matrice_initala[9][9], usi sir_generat[], usi dimensiune_matrice)
{
    for(usi i=1;i<=dimensiune_matrice;i++)
    {
        for(usi j=1;j<=dimensiune_matrice;j++)
        {
            //daca elementul este situat deasupra diagonalei principale
            if(i+j<dimensiune_matrice+1)
                matrice_initala[i][j]=ultima_cifra(sir_generat[dimensiune_matrice*dimensiune_matrice+i+j]);
            //daca elementul este situat sub diagonala principala
            if(i+j>dimensiune_matrice+1)
                matrice_initala[i][j]=prima_cifra(sir_generat[dimensiune_matrice*dimensiune_matrice+i+j]);
            //daca elementul este pe diagonala secundara
            if(i+j==dimensiune_matrice+1)
                matrice_initala[i][j]=cifra_maxima(sir_generat[dimensiune_matrice*dimensiune_matrice+i*i]);
        }
    }
}
int construire_numar(usi matrice_initala[9][9], usi dimensiune_matrice)
{
    usi frecventa[10]={0}; //declaram un vector de frecventa
    for(usi i=1;i<=dimensiune_matrice;i++)
    {
        for(usi j=1;j<=dimensiune_matrice;j++)
            frecventa[matrice_initala[j][i]]++; //generam frecventa cifrelor
        for(usi i=9;i>=1;i--) //elementele din vectorul de frecventa sunt sortate crescator, vom parcurge vectorul descrescator pentru a afisa cifrele
            while(frecventa[i]>0) //daca o cifra se repeta, o afisam
            {
                cout<<i;
                frecventa[i]--; //decrementam frecventa cifrei afisate
            }
        }
       cout<<" ";
    }
}


int main()
{
    usi dimensiune_matrice, dimensiune_sir, matrice_initala[9][9];
    cin>>dimensiune_matrice;
    dimensiune_sir=2*(dimensiune_matrice*dimensiune_matrice); //marimea sirului generat
    usi sir_generat[dimensiune_sir+1]; //marimea sirului generat
    divizor(sir_generat,dimensiune_sir);
    construirea_matricei(matrice_initala,sir_generat,dimensiune_matrice);
    construire_numar(matrice_initala,dimensiune_matrice);
}
