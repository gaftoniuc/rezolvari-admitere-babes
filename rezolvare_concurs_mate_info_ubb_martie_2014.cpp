/*Se citeşte de la tastatură o matrice pătratică A cu n linii și n coloane conținȃnd numere naturale (3 ≤ n ≤ 50, 1 ≤
ai,j ≤ 20000). Scrieţi un program care determină și apoi tipărește şirul X, conținȃnd ȋn ordine descrescătoare,
numerele „superprime” distincte, care apar ȋn triunghiul stȃng sau cel drept al matricei A. Șirul X se va construi
direct ordonat, fără a face ordonarea ulterioară. Ȋn cazul ȋn care șirul X este vid, se va tipări mesajul „Șirul este
vid”.
Un număr se numește „superprim” dacă toate prefixele sale sunt numere prime (de ex. 239 este
„superprim” deoarece 2, 23 și 239 sunt prime, dar numărul 241 nu este „superprim” deoarece 24 nu este prim).
Se vor scrie subprograme pentru:
a). citirea unei matrici pătratice
b). tipărirea unui şir
c). verificarea dacă un număr este prim
d). verificarea dacă un număr este „superprim”
e). inserarea unei valori ȋntr-un șir ordonat descrescător
f). construirea șirului X.*/
#include <iostream>
#include <fstream>
#define usi unsigned short int
using namespace std;

ifstream r("rezolvare_concurs_mate_info_ubb_martie_2014.txt");
void citire(usi a[][100], usi &n)
{
    r>>n;
    for(usi i=1;i<=n;i++)
        for(usi j=1;j<=n;j++)
            r>>a[i][j];
}
void afisare(usi sir[], usi dimensiune)
{
    if(dimensiune==0) //daca dimnensiunea nu a fost modificata pe parcursul rularii inseamna ca nu avem elemente eligibile
        cout<<"Sirul este vid";
    else //daca nu, afisam sirul final
    for(usi i=1; i<=dimensiune; i++)
        cout<<sir[i]<<" ";
}
int prim(int n)
{
    if(n<2) return 0; //daca n este mai mic decat doi nu este prim
    if(n==2) return 1; //daca n este egal cu doi el este prim
    if(n%2==0) return 0; // daca numarul este par si este diferit de doi vom returna 0 din start
    for(usi d=3;d*d<=n;d+=2) //toate numerele prime sunt impare (excluzand doi), deci divizorii sunt si ei impari
            if(n%d==0) return 0;
    return 1;
}
int superprim(usi n)
{
    usi temp=0, putere_cifre=1, numar_cifre=0, cif_superprim=0;
    temp=n;
    while(n!=0)
    {
        putere_cifre*=10; //ridicam 10 la puterea numarului de cifre pentru a efectua impartirile aferente
        numar_cifre++; //numaram cifrele
        n=n/10;
    }
    //verificam cazurile particulare de numere superprime
    //daca numarul are mai mult doua cifre
    if(numar_cifre>2)
    {
          if(prim(temp/(putere_cifre/10))) cif_superprim++;
          if(prim(temp/(putere_cifre/100))) cif_superprim++;
          if(prim(temp)) cif_superprim++;
    }
    //daca numarul este format dintr-o singura cifra atunci mai ramane sa verificam daca este prim
    if(numar_cifre==1) if(prim(temp)) return 1;
    //daca numarul are doar doua cifre
    if(numar_cifre==2)
    {
          if(prim(temp/(putere_cifre/10))) cif_superprim++;
          if(prim(temp)) cif_superprim++;
    }

    if(cif_superprim==numar_cifre) return 1;
    else return 0;
}
void inserare(usi sir_superprime[], usi &n, usi element)
{
    //incepem de la pozitia unu
    usi poz=1;
    //atat timp cat elementele din sir sunt mai mici ca elementul eligibil pentru inserare incrementam pozitia
    while(sir_superprime[poz]>element && poz<=n)
        poz++;
    //mutam toate elementele sirului la dreapta
    for(usi i=n;i>=poz;i++)
            sir_superprime[i]=sir_superprime[i+1];
    //inseram elementul cautat
    sir_superprime[poz]=element;
    //incrementam dimensiunea sirului final
    n++;
}
int cautare(usi x[], usi n, usi element)
{
    //verificam daca elementul exista deja in sirul cu elemente superprime
    usi ok=0;
    for(usi i=1; i<=n; i++)
        if(x[i]==element) ok=1;
    return ok;
}
void construire_sir(usi a[][100], usi n, usi x[], usi &nr_elemente_sir)
{
    nr_elemente_sir=0; //elementele sirului cu numere superprime
    for(usi i=1;i<=n;i++)
        for(usi j=1;j<=n;j++)
            if(((i>j) && i+j<n+1) || (i<j && i+j>n+1)) //verificam daca se afla intr-unul din cele doua triunghiuri
                if(superprim(a[i][j])==1 && cautare(x,nr_elemente_sir,a[i][j])==0) //verificam daca este superprim si daca exista deja in sirul final
                    inserare(x,nr_elemente_sir,a[i][j]); //daca nu exista si este superprim elementul va fi inserat descrescator

}
int main()
{
   usi matrice_initiala[100][100], sir_superprime[100], dimensiune_matrice, dimensiune_sir;
   citire(matrice_initiala, dimensiune_matrice); //citirea initiala a matricei
   construire_sir(matrice_initiala, dimensiune_matrice, sir_superprime, dimensiune_sir); //construirea sirului final
   afisare(sir_superprime, dimensiune_sir); //afisarea sirului final
}
