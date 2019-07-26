#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<ctime>
using namespace std;
void output(int b[][25],int& sc)
{
	int o,p;
              for(o=0;o<25;o++)
              {
                  for(p=0;p<25;p++)
                  {
                    if (b[o][p]==0) cout<<" ";                                   
                    if ((b[o][p]!=0)&&(b[o][p]<500)) cout<<char(219);
                    if (b[o][p]==1000) cout<<"#";
                    if ((b[o][p]==500)&&(o!=0)) cout<<"$";
                  }
                  cout<<endl;       
              }    
            cout<<"Score : "<<sc;
}
int main()
{
    ifstream myfile("wall.txt");
    int a[25][25],i,l,o,p,f=0,k,xt,yt,xh,yh,m,r1,r2,b,sc=0,d,z=0,r,g,v;
    //a is array for map
    //xh,yh,xt,yt are for save snake's head and tail position
    //z,f are flags for lose and fruit
    //r,g are for random
    //m is for snake's lenght
    string s; 
    char c;
    //cin speed
    cout<<"Choose speed(1-300)"<<endl;
    cin>>v;
    v=301-v;
    srand(time(0));
    //Load wall part
    for(o=0;o<25;o++)
    {
        for(p=0;p<25;p++)
       {
            a[o][p]=0;
            if ((o==24)||(p==24)) a[o][p]=1000;
       }       
    }
    for(o=0;o<25;o++)
    {
        myfile>>s;
        for(p=0;p<25;p++)
       {
           if (s[p]=='1') a[o][p]=1000;
       }       
    }
    b=3;
    system("cls");
	//Snake's first size     
    for(p=1;p<=b;p++)
    {
       a[10][p]=p;
    }
    i=1;
    l=b;
    m=l;
    c='d';
    //Move while
    while(f!=1)
    {
       for(i=1;i<=m;i++)
       {
       	      //For make snake,used array of int, this array has snake's bits as integer form  
              for(o=0;o<25;o++)
              {
                  for(p=0;p<25;p++)
                  {
                     if(a[o][p]==i){xt=p; yt=o;}
                  }       
              }
              for(o=0;o<25;o++)
              {
                  for(p=0;p<25;p++)
                  {
                     if(a[o][p]==l){xh=p; yh=o;}
                  }       
              }
              //Moving part
              //In this part snake's tail go on snake's head to move
              if (c=='d')
              {
              	  //"ifs" for lose and gameover!
                  if (a[yh][xh+1]==1000) { f=1; break;}       
                  if ((xh==23)||((a[yh][xh+1]<500)&&(a[yh][xh+1]!=0))){ f=1; break;}  
				  //(m++) is for adding snake's lenght     
                  if (a[yh][xh+1]==500) {m++; sc=sc+10;z=0;}
                  //Move array's number bit 
                  if (xh!=24){ a[yt][xt]=0; a[yh][xh+1]=i;}
              }
              if (c=='w')
              {
                  if (a[yh-1][xh]==1000) { f=1; break;}
                  if ((yh==0)||((a[yh-1][xh]<500)&&(a[yh-1][xh]!=0))){ f=1; break;}
                  if (a[yh-1][xh]==500) {m++; sc=sc+10;z=0;}
                  if (yh!=0){a[yt][xt]=0; a[yh-1][xh]=i;}
              }
              if (c=='a')
              {
                  if (a[yh][xh-1]==1000) { f=1; break;}
                  if ((xh==0)||((a[yh][xh-1]<500)&&(a[yh][xh-1]!=0))){ f=1; break;} 
                  if (a[yh][xh-1]==500) {m++; sc=sc+10; z=0;}
                  if (xh!=0){a[yt][xt]=0; a[yh][xh-1]=i;}
              }
              if (c=='s')
              {
                  if (a[yh+1][xh]==1000) { f=1; break;}
                  if ((yh==23)||((a[yh+1][xh]<500)&&(a[yh+1][xh]!=0))){ f=1; break;} 
                  if (a[yh+1][xh]==500) {m++; sc=sc+10;z=0;}       
                  if(yh!=24){a[yt][xt]=0; a[yh+1][xh]=i;}    
              }
              l=i;
              if (kbhit()) c=getch();
              //Output is function for cout map and score
              output(a,sc);
              Sleep(v);
              //Random fruit part
              for(o=0;o<25;o++)
              {
                    for(p=0;p<25;p++)
                   {
                   	       r=rand()% 25;
                   	       g=rand()% 25;
                           if ((z==0)&&(a[r][g]==0)) {a[r][g]=500; z=1;}

                   }       
              }
              sc=sc+1;
              system("cls");
       } 
    } 
    cout<<"Game Over"<<endl<<"Your score : "<<sc<<endl;  
    system("Pause");
}


