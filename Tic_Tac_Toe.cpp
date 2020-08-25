#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
void display(int a[3][3])
{

    int i=0,j=0;
    cout<<"-------------------\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==10)
                cout<<"|  X  ";
            else if(a[i][j]==0)
                cout<<"|  O  ";
            else
                cout<<"|  "<<a[i][j]<<"  ";
        }
        cout<<"|\n";
        cout<<"-------------------\n";
    }

}
void update(int a[3][3],int ch,int p)
{
    int c=0,i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c++;
            if(ch==c)
            {
                if(p==0)
                {
                    a[i][j]=10;
                }
                else
                    a[i][j]=0;
            }

        }
    }
}
int check(int a[3][3])
{
    int i,j,l=0,counter=0,b=0,d1=0,d2=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==10)
                l++;
            else if(a[i][j]==0)
                b++;
            if(a[i][j]==10 && i==j)
                d1++;
            else if(a[i][j]==0 && i==j)
                d2++;
        }
        if(l==3||b==3 || d1==3 || d2==3)
        {
            counter++;
            break;
        }
        b=0;
        l=0;

    }
    l=0;
    b=0;
    d1=0;
    d2=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[j][i]==10)
                l++;
            else if(a[j][i]==0)
                b++;
            if(a[i][j]==10 && i+j==2)
                d1++;
            else if(a[i][j]==0 && i+j==2)
                d2++;
        }
        if(l==3||b==3 ||d1==3 || d2==3)
        {
            counter++;
            break;
        }
        l=0;
        b=0;
    }
    if(counter>0)
        return 1;
    else if(counter==0)
        return 0;
    else
        return -1;
}
int main()
{
    int n=1,a[3][3],i,j,c=1,p=0,ch=0,win;
    char p1[40],p2[40];
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
        a[i][j]=n;
        n++;
    }
    cout<<"\t***Hello to the infamous game of Tic-Tac-Toe***\n";
    cout<<"Player 1 Enter your name :";
    gets(p1);
    cout<<"Player 2 Enter your name :";
    gets(p2);
    cout<<"\n\tLet's start off with showing you the Matrix\n";
    display(a);
    cout<<"\n\tYou have to enter the number involving 1-9 describing where you want to add your X or O\n";
    cout<<p1<<" is assigned O and "<<p2<<" is assigned X.\n ";

    while(c!=-1)
    {
        if(p==0)
        {
            cout<<p1<<" Enter your choice :";
            cin>>ch;
            p=1;
        }
        else
        {
            cout<<p2<<" Enter your choice :";
            cin>>ch;
            p=0;
        }
        update(a,ch,p);
        display(a);
        win=check(a);
        if(win==0)
            c++;
        else if(win==1)
        {
            if(p==1)
                cout<<p1<<"  won the game.\n\t\t CONGRATULATIONS\n\n\n\n\n";
            else
                cout<<p2<<"  won the game.\n\t\t CONGRATULATIONS\n\n\n\n\n";
            c=-1;
        }
        else if(win==-1)
        {
            cout<<"Nobody won, well tried!";
        }
    }
getch();
}
