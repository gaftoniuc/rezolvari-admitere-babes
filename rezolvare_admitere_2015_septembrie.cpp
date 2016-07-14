/* Se citeşte un sir de numere naturale nenule, unde 1 < n < 200, 1 < xi < 30000. Un element xi
situat in sir pe pozitia i (1 < i < n-1) se numeste perfect dacă are cel putin o cifră comună cu toate elementele
situate in sir după el. Să se scrie un program care inserează in sirul X, după fiecare element care
este perfect, divizorii săi proprii (divizorii se vor considera in ordine descrescătoare). După modificarea sirului
X, se va construi sirul continand ordinea in care ar trebui afisate elementele sirului X pentru a
fi in ordine descrescătoare. La final, se va tipări sirul X in ordinea dată de O. */
#include <iostream>
#define ui unsigned int
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
void afisare(int sir[], int sir2[], int dimensiune)
{
    for(int i=1; i<=dimensiune; i++) //afisam sirul X in functie de sirul Y
        cout<<sir[sir2[i]]<<" ";
    cout<<"\n";
}
int numar_cifre(int numar)
{
    ui cifre=0;
    cifre++;
    while(numar!=0)
    {
        cifre++;
        numar/=10;
    }
    return cifre-1;
}
int numar_perfect(int numar1, int numar2) //verificam utilizand un vector de frecventa daca numerele au cel putin o cifra in comun
{
    int vector_cifre1[10]={0}, vector_cifre2[10]={0};
    ui n1, n2;
    n1=numar1;
    n2=numar2;
    for(int i=1;i<=numar_cifre(n1);i++)
    {
        vector_cifre1[(numar1)%10]=1;
        numar1/=10;
    }
    for(int i=1;i<=numar_cifre(n2);i++)
    {
         vector_cifre2[(numar2)%10]=1;
         numar2/=10;
    }
    for(int i=0;i<=9;i++)
    if(vector_cifre1[i]!=0 || vector_cifre2[i]!=0)
            if(vector_cifre1[i]==vector_cifre2[i]) return 1;
    return 0;
}
int nr_divizori(int numar)
{
     int divizori=0;
     for(int div=numar-1;div>=2;div--)
        if(numar%div==0) divizori++;
     return divizori;
}
void cifre_perfecte(int sir_initial[], int &marime_sir_initiala)
{
    int ok=0, aux, i, j, ls=0, ld=0, div, poz;
    for(i=1;i<=marime_sir_initiala;i++)
    {
        for(j=1;j<=marime_sir_initiala-1;j++)
        {
            if(numar_perfect(sir_initial[i],sir_initial[j])) //verificam secventele formate din numere care au cel putin o cifra identica
            {
                ok=1;
                ls=i; //memoram limita la stanga a secventei
                ld=j; //memoram limita la dreapta a secventei
            }
            else ok=0;
        }
    }
    aux=sir_initial[ls];
    poz=ld+1;
    for(div=sir_initial[ld]-1;div>=2;div--)
        if(sir_initial[ld]%div==0) sir_initial[poz++]=div; //generam sirul in functie de secventa cu divizorii numarului ce se afla pe pozitia limiteai la stanga
    sir_initial[poz]=aux; //memoram elementul care margineste superior secventa si il punem la sfarsitul modificarii acesteia
    marime_sir_initiala=marime_sir_initiala+nr_divizori(sir_initial[ls])+1; //marim dimensiunea sirului initial
}
int cautare(int x[], int n, int element)
{
    //verificam daca elementul exista deja in sirul cu elemente superprime
    int ok=0;
    for(int i=1; i<=n; i++)
        if(x[i]==element) ok=1;
    return ok;
}
void generare_o(int sir_secundar[], int sir_initial[], int marime_sir_initiala)
{
    int aux=0;
    for(int i=1;i<=marime_sir_initiala;i++) //generam sirul initial de pozitii
        sir_secundar[i]=i;
    for(int i=1;i<marime_sir_initiala;i++)
        for(int j=i+1;j<=marime_sir_initiala;j++)
            if(sir_initial[sir_secundar[i]]<sir_initial[sir_secundar[j]]) //modificam pozitiile in functie de valoarea pe care o au in sirul initial
            {
                aux=sir_secundar[i];
                sir_secundar[i]=sir_secundar[j];
                sir_secundar[j]=aux;
            }
}
int main()
{
    int x[100],y[100], n;
    citire(x,n);
    cifre_perfecte(x,n);
    generare_o(y, x ,n);
    afisare(x, y, n);
}
