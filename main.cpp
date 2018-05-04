#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

char map1[100],map2[100],map3[100];
int main()
{
    int poz=0,points=0,food1,food2,food3,wall;char player=43,food=219,wallf=99;
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        food1=rand()%80;
        food2=rand()%80;
        food3=rand()%80;
        wall=rand()%80;
        map2[food1]=food;
        map1[food2]=food;
        map2[food2]=wall;
        map2[wall]=wallf;
        map3[food3]=food;
        map2[food3]=wallf;
    }
    int start=clock();
    for(int i=0;i<80;i++)
        cout<<map1[i];
    cout<<"\n";
    for(int i=0;i<80;i++)
        cout<<map2[i];
    cout<<"\n";
    for(int i=0;i<80;i++)
        cout<<map3[i];
    while(1)
    {
        if(kbhit()==0)
        {
            char key=getch();
            if(key=='d')
            {
                if(map2[poz+1]==food)
                    points+=100;
                else if(map2[poz+1]==wallf)
                    points-=100;
                map2[poz]=' ';
                poz++;
                map2[poz]=player;
            }
            if(key=='a')
            {
                if(map2[poz-1]==food)
                    points+=100;
                else if(map2[poz-1]==wallf)
                    points-=100;
                map2[poz]=' ';
                poz--;
                map2[poz]=player;
            }
            if(key=='w')
            {
                map2[poz]=' ';
                poz++;
                if(map1[poz]==food)
                    points+=100;
                map1[poz]=player;
                system("cls");
                for(int i=0;i<80;i++)
                    cout<<map1[i];
                cout<<"\n";
                for(int i=0;i<80;i++)
                    cout<<map2[i];
                cout<<"\n";
                for(int i=0;i<80;i++)
                    cout<<map3[i];
                Sleep(100);
                map1[poz]=' ';
                poz++;
                map2[poz]=player;
            }
            if(poz>79)
                poz=0;
            if(poz<0)
                poz=79;
            if(points>800)
            {
                cout<<"Bravo,ai stil!";
                return 0;
            }
            int end=clock();
            if(end-start>50000)
            {
                cout<<"Time limit!";
                return 0;
            }
            system("cls");
            for(int i=0;i<80;i++)
                    cout<<map1[i];
                cout<<"\n";
                for(int i=0;i<80;i++)
                    cout<<map2[i];
                cout<<"\n";
                for(int i=0;i<80;i++)
                    cout<<map3[i];
        }
    }
    return 0;
}
