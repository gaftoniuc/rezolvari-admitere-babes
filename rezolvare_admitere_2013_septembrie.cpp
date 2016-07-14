/*Se cite�te un �ir X de numere naturale cu n elemente (1 ? n ? 500, 1 ? Xi ? 1000). Scrie�i un program care
determin� �irul Y de numere prime distincte, care figureaz� la puterea �nt�i �n cel pu�in o descompunere ?n factori
primi a unui num�r din ?irul X. Dac� nici un element al �irului X nu are un factor prim la puterea �nt�i, atunci se va
tip�ri mesajul �Sirul Y e vid.�
Se vor scrie subprograme pentru:
a). citirea unui �ir de numere naturale
b). tip�rirea unui �ir
c). generarea tuturor numerelor prime mai mici sau egale dec�t un num�r dat SAU verificarea dac� un num�r
este prim (?n func?ie de modalitatea de rezolvare aleas�)
d). verificarea dac� un num�r figureaz� la puterea �nt�i �n descompunerea unui num�r dat
e). construirea ?irului Y*/
#include <iostream>
using namespace std;
void citire(int sir_initial[], int &n)
{
    cout<<"n:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"x["<<i<<"]:";
        cin>>sir_initial[i];
    }
}
void afisare(int sir[], int marime_sir)
{
    if(marime_sir==0) cout<<"Sirul Y este vid"; //daca marimea sirului final este egala cu zero nu am gasit niciun divizor prim
    for(int i=1;i<=marime_sir;i++)
        cout<<sir[i]<<" ";
}
int prim(int n)
{
    if(n<2) return 0;
    if(n==2) return 1;
    for(int d=2;d*d<=n;d++)
        if(n%d==0) return 0;
    return 1;
}
//cautam in sirul cu elemente prime
int cautare(int sir_final[], int marime_sir_final, int element)
{
    int ok=0;
    for(int i=1;i<=marime_sir_final;i++) //daca elementul este gasit se returneaza 1, iar in daca se gaseste, returnam 0
        if(sir_final[i]==element) ok=1;
    return ok;
}
int generare_sir(int sir_initial[], int marime_sir_initial, int sir_final[], int &marime_sir_final)
{
    for(int i=1;i<=marime_sir_initial;i++)
        for(int j=2;j<=sir_initial[i];j++) //cautam toti divizorii unui element din sirul initial
            if(sir_initial[i]%j==0)
                if(prim(j)==1 && cautare(sir_final, marime_sir_final, j)==0) //daca elementul figureaza deja descompus la o putere prima il omitem si cautam alt divizor prim
                    sir_final[++marime_sir_final]=j; //daca nu exista in sirul final il adaugam, daca este unic.
}
int main()
{
    int sir_inital[500], sir_final[500], marime_sir_initial, marime_sir_final=0;
    citire(sir_inital, marime_sir_initial);
    generare_sir(sir_inital, marime_sir_initial, sir_final, marime_sir_final);
    afisare(sir_final,marime_sir_final);
}
