/**
Symulacja Driven Cavity flow. 
Implementacja symulacji płynu z użyciem 
modelu LBMTau1. Materiał do filmu: 
https://www.youtube.com/watch?v=AC-wGDglppo

Kod oraz metoda pochodzą z książki
Matyka, M., Symulacje Komputerowe w Fizyce, wydanie 2, Helion, Gliwice (2020)

oraz z artykułu:
Matyka, M., Dzikowski, M.
Memory-efficient Lattice Boltzmann Method for low Reynolds number flows
Computer Physics Communications 267, 108044 (2021)

Wrocław, 2021-06-10
**/
#include <iostream>
using namespace std;
#define L 50
float U[2][L][L], V[2][L][L], R[2][L][L]; 
int F[L][L];
const int ex[9]={0,1,0,-1,0,1,-1,-1,1};
const int ey[9]={0,0,1,0,-1,1,1,-1,-1};
const int inv[9]={0,3,4,1,2,7,8,5,6};
const float w[9]={4/9.,1/9.,1/9.,1/9.,1/9.,1/36.,1/36.,1/36.,
1/36.};
float U0=0.5;

void init()
{
 for(int i=0; i<L ; i++)  
 for(int j=0; j<L ; j++)  	  	
 {
  U[0][i][j]=V[0][i][j]=0;
  U[1][i][j]=V[1][i][j]=0;
  R[0][i][j]=R[1][i][j]=1;
  F[i][j]=0;
  
  if(j==0 or i==0 or i==L-1) F[i][j] = 1;
  if(j==L-1) U[0][i][j] = U[1][i][j] = U0;
 }
}

void LBMTau1(int c)
{
 float r,u,v,f;
 
 for(int i=0; i<L; i++)		
 for(int j=0; j<L-1; j++)
 if(F[i][j]==0)
 {	
  U[c][i][j]=V[c][i][j]=R[c][i][j]=0;

  for(int k=0; k<9; k++)
  {	
   int ip=i+ex[k], jp=j+ey[k], ik=inv[k];
 	
   if(F[ip][jp]==0)
   {
    r=R[1-c][ip][jp];
    u=U[1-c][ip][jp]/r;  
    v=V[1-c][ip][jp]/r; 
    
    f=w[ik]*r*(1-(3/2.)*(u*u+v*v)+3.*(ex[ik]*u+ey[ik]*v)
    +(9/2.)*(ex[ik]*u+ey[ik]*v)*(ex[ik]*u+ey[ik]*v));
   } 
   else
     f=w[ik]*R[1-c][i][j];

   R[c][i][j] += f;
   U[c][i][j] += ex[ik]*f;
   V[c][i][j] += ey[ik]*f;	  
  }	  
 }
}



int main(void)
{
    init();
    int c = 0;
    for(int step=0;step<1001;step++)
    {
        c=1-c;
        LBMTau1(c);  
        //cout << step << endl;
    }

     for(int i=0; i<L; i++)
     for(int j=0; j<L; j++)
     {
       cout << i << " " << j << " " << U[c][i][j] << " " << V[c][i][j] << endl;            
     }


 return 0;
}