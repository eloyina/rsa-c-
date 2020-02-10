#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;
bool esprimo(int n)
{
 int i=2;
 int d=int((sqrt(n)));
 while(i<=d){
  if(n%i==0)return false;
  i++;
 }
 return true;
}

int primo(int max)
{
 int num=rand()%max;//retorna los valores al azar mi random
 while(!esprimo(num))
  num++;
 return num;
}

int* camBase(int n,int base)//numero ingresado y la base
{
 int max=1;
 int* dig=new int[max];
 int i=max;
 while(n>0)
 {
  dig[i]=n%base;
  n/=base;
  i--;
 }
 return dig;
}

int expModZ(int a,int n,int z)
{
 int result = 1;
 int x= a % z;
 while(n>0)
 {
  if(n%2==1)
   result = (result*x)%z;
  x=(x*x)%z;
  n=(n/2);
 }
 return result;
}

class Euclides
{
 public:
 int x,y;
 int s,t;
 int mcd;
 int invMod;
void euclides (int a, int b)

{
    int r = a%b;
    while(r>=0)
    {
        if(r==0)
        if(r>b/2) r = b-r;
        a=b;
        b=r;
        r=a%b;
   }

void mcdEu()
{
int a=x,b=y;
      int tmp;
      while (b) {
            tmp = b;
            b = a % b;
            a = tmp;
      }
      mcd=a;
}
 void EuclidesExt(){

int a; int b;
 int u=1;
     int g =a;
     int x = 0;
     int y =b;

     while(2)
     {
         if(y==0)
         {
           int v=(g-(a*u))/b;
           //cout<<g<<" "<<u<<" "<<v<<endl;
           //if(u<0) u=b+u;
         
         }
         int t = g%y;
         int q =g/y;
         int s = u-(q*x);
         u = x;
         g=y;
         x=s;
         y=t;
    
   }
  }

};
class clave
{
 public:
 int x,y;
 public:

 clave(int x2,int y2){
  x=x2;
  y=y2;
 }

 void imprimir()
 {
  cout<<"("<<x<<","<<y<<")"<<endl;
 }
 };
class RSA
{
private:

 long int p,q;
 long int N,r;//variable de respuesta
 long double d;
long double e;
 clave* publica;
 clave* privada;
char* cadenaC;
int* cadenaCh;
public:
 RSA(){
  //p=primo(100);
  long int p;
        cout<<"ingrese el primer numero"<<endl;
        cin>>p;
  //q=primo(100);
  long int q;
  cout<<"ingrese el segundo numero"<<endl;
        cin>>q;
    N=p*q;//multiplicacion
  cout<<"1er paso multiplicarlos entre ambos N -> "<<N<<endl;

        r=(p-1)*(q-1);
  cout<<"2do paso restar-1 a cada uno y multiplicarlos DELTA N->  "<<r<<endl;
  cout<<"ingrese el inverso del numero: "<<r<<endl;
    e=13;//primo(fiN);
        cout<<"El numero e "<<e<<endl;
  Euclides euclides(e,r);
  euclides.EuclidesExt();
         d=euclides.invMod;
  //cout<<"EL numero principal es: "<<d<<endl;
  cout<<"la clave privada es"<<d<<","<<N<<endl;
        cout<<"la clave publica es"<<e<<","<<N<<endl;
 cout<<"ingrese mensaje a cifrar"<<endl;
cadenaC= new char[200];
cin.get();
cin.getline(cadenaC,200);//lea espacios una linea entera
 }

void codificar()
{     long int bloque;
     if(N>bloque)
     {
    cadenaCh=new int [200];
    int i=0;
    for(;cadenaC[i];i++)
{
  cout<<codifique(cadenaC[i])<<endl;
  cadenaCh[i]=codifique(cadenaC[i]);

     }
     cadenaCh[i]=-1;

}


 void imprimir()
 {

 }


char intToChar(int a)
{
          return (char) a;
}



char* arrayToWord(int* w,int a){
     int i;
     char *conv = new char[a];
     for(i = 0 ; w[i]!='\0' ; i++){
           conv[i] = intToChar(w[i]);
     }

     return conv;
}

 long double codifique(char a)
 {
    int p= (int)a;
    long double q= expModZ(p,e,N);
    return q;
}



char decodifique(int i)
{
    long double q= expModZ(i,d,N);
    cout<<q<<endl;
    return q;

}

void Decodificar()
{
  int i=0;
  for(;cadenaCh[i]!=-1;i++)
{
    //cout<<cadenaCh[i];
  cout<<decodifique(cadenaCh[i])<<endl;

     }

}
/*
int firma(int hash,int d,int N)
{
    if(N>hash)
    {
    x= expModZ(hash,d,N);
    if(x==hash)
    return 0;
    }
     return x ;
 }
 */
};
/*

 int exponencial(char*a)
{
    int tam=strlen(a);
    int exponencial2=0;
    for(int i=0;i<tam;i++)
    {
          if(a[i]=='A' a[i]=10;
          // cout<<"entroo2";
        if(a[i]=='B') a[i]=11;
        if(a[i]=='C') a[i]=12;
        if(a[i]=='D') a[i]=13;
        if(a[i]=='E') a[i]=14;
        if(a[i]=='F') a[i]=15;

      exponencial2 = exponencial2+((pow(16,i))*(a[i]));
        //a++;
    }

     return exponencial2;
}
*/


int main()
{

 RSA prueva;
 prueva.imprimir();
 prueva.codificar();
 prueva.Decodificar();
 //cout<<exponencial("F3");

  system("PAUSE");
   return EXIT_SUCCESS;

}
