//#include "mainClasses.cpp"
#include<iostream>
using namespace std;


//#include <iostream>
//#include "mainFunctions.cpp"

//using namespace std;

class TicTac
{
  char GameBoard[4][4];
  public:
  TicTac();
  void setGameSpace();
  int result();

};

TicTac::TicTac()
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        GameBoard[i][j]='-';
}

void TicTac::setGameSpace()
{
   int i,row,col;
   for(i=0;i<4;i++)
   {
    cout<<"Round No: "<<i+1;
   cout<<"\nx Enter row = ";
   cin>>row;
   cout<<"\nx Enter column = ";
   cin>>col;
   GameBoard[row-1][col-1]='x';
   cout<<"\no Enter row = ";
   cin>>row;
   cout<<"\no Enter column = ";
   cin>>col;
   GameBoard[row-1][col-1]='o';
    }
}

//#include "mainClasses.cpp"
//using namespace std;
int TicTac::result()
{
    int i,j,xr,xc,ro,oc,dx=0,doo=0;

    for(i=0;i<4;i++)
    {
        xr=0;
        ro=0;
        xc=0;
        oc=0;
        for(j=0;j<4;j++)
        {
           if(GameBoard[i][j]=='x')
           ++xr;
           if(GameBoard[j][i]=='x')
           ++xc;
           if(i==j && GameBoard[i][j]=='x')
           ++dx;
           if(xr==4 ||xc==4|| dx==4)
           return 1;
           if(GameBoard[i][j]=='o')
           ++ro;
           if(GameBoard[j][i]=='o')
           ++oc;
           if(i==j && GameBoard[i][j]=='o')
           ++doo;
           if(ro==4||oc==4 || doo==4)
           return 2;

        }
    }
 return 0;
}

int main()
{
    int a;
 TicTac t;
 t.setGameSpace();
 a=t.result();
if(a==1)
cout<<"\nX wins the Game..";
else if(a==2)
cout<<"\nO wins the Game..";
else
cout<<"\nGame Ties...";
return 0;
}
