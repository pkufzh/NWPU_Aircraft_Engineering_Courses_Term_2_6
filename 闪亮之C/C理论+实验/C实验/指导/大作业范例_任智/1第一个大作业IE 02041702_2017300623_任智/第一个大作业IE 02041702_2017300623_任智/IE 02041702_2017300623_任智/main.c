#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define NUM 10
int n,m;
int game[NUM][NUM];
int saved1[NUM][NUM];
int saved2[NUM][NUM];
void generate()
{
    srand((unsigned)time(NULL));
    int i,j;
    int judge[NUM][NUM];
    int flag=0;
    memset(judge,0,NUM*NUM*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(!game[i][j])
            {
                judge[i][j]=1;
                flag=1;
            }
        }
    }
    if(!flag) return;
    while(1)
    {
        int ir=rand()%n;
        int jr=rand()%n;
        if(judge[ir][jr])
        {
            game[ir][jr]=2;
            return;
        }
    }
}
void show()
{
    int i,j,k;
    system("cls");
    printf("\n  * ");
    for(k=0;k<3*(n+1)-2;k++)
    {
        printf("* ");
    }
    for(i=0;i<n;i++)
    {
        printf("*\n  *");
        for(k=0;k<6*(n+1)-3;k++)
        {
            printf(" ");
        }
        printf("*\n  *");
        for(j=0;j<n;j++)
        {
            if(game[i][j])
            {
                printf("%5d ",game[i][j]);
            }
            else
            {
                printf("    - ");
            }
        }
        printf("   ");
        printf("*\n  *");
        for(k=0;k<6*(n+1)-3;k++)
        {
            printf(" ");
        }
    }
    printf("*\n  * ");
    for(k=0;k<3*(n+1)-2;k++)
    {
        printf("* ");
    }
    printf("*\n\n");
    printf(" Select the direction to move\n");
    printf("(W-up/A-left/S-down/D-right/R-return)\n");
}
int move()
{
    char dir;
    dir=getch();
    int flag=-1;
    if(dir>='a'&&dir<='z')
    {
        dir-=32;
    }
    if(dir=='W')
    {
        int i,j,k;
        for(j=0;j<n;j++)
        {
            for(i=0;i<n-1;i++)
            {
                for(k=1;k<n-i;k++)
                {
                    if(game[i+k][j]!=0&&game[i][j]!=game[i+k][j])
                    {
                        break;
                    }
                    if(game[i][j]!=0&&game[i][j]==game[i+k][j])
                    {
                        game[i][j]*=2;
                        game[i+k][j]=0;
                        i+=k;
                        flag=1;
                    }
                }
            }
            for(i=n-2;i>=0;i--)
            {
                if(game[i][j]==0)
                {
                    int ii;
                    for(ii=i;ii<n-1;ii++)
                    {
                        game[ii][j]=game[ii+1][j];
                        if(game[ii][j]!=0)
                        {
                            flag=1;
                        }
                    }
                    game[n-1][j]=0;
                }
            }
        }
    }
    else if(dir=='A')
    {
        int i,j,k;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                for(k=1;k<n-j;k++)
                {
                    if(game[i][j+k]!=0&&game[i][j]!=game[i][j+k])
                    {
                        break;
                    }
                    if(game[i][j]!=0&&game[i][j]==game[i][j+k])
                    {
                        game[i][j]*=2;
                        game[i][j+k]=0;
                        j+=k;
                        flag=1;
                    }
                }
            }
            for(j=n-2;j>=0;j--)
            {
                if(game[i][j]==0)
                {
                    int jj;
                    for(jj=j;jj<n-1;jj++)
                    {
                        game[i][jj]=game[i][jj+1];
                        if(game[i][jj]!=0)
                        {
                            flag=1;
                        }
                    }
                    game[i][n-1]=0;
                }
            }
        }
    }
    else if(dir=='S')
    {
        int i,j,k;
        for(j=0;j<n;j++)
        {
            for(i=n-1;i>=1;i--)
            {
                for(k=1;k<=i;k++)
                {
                    if(game[i-k][j]!=0&&game[i][j]!=game[i-k][j])
                    {
                        break;
                    }
                    if(game[i][j]!=0&&game[i][j]==game[i-k][j])
                    {
                        game[i][j]*=2;
                        game[i-k][j]=0;
                        i-=k;
                        flag=1;
                    }
                }
            }
            for(i=1;i<n;i++)
            {
                if(game[i][j]==0)
                {
                    int ii;
                    for(ii=i;ii>0;ii--)
                    {
                        game[ii][j]=game[ii-1][j];
                        if(game[ii][j]!=0)
                        {
                            flag=1;
                        }
                    }
                    game[0][j]=0;
                }
            }
        }
    }
    else if(dir=='D')
    {
        int i,j,k;
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>=1;j--)
            {
                for(k=1;k<=j;k++)
                {
                    if(game[i][j-k]!=0&&game[i][j]!=game[i][j-k])
                    {
                        break;
                    }
                    if(game[i][j]!=0&&game[i][j]==game[i][j-k])
                    {
                        game[i][j]*=2;
                        game[i][j-k]=0;
                        j-=k;
                        flag=1;
                    }
                }
            }
            for(j=1;j<n;j++)
            {
                if(game[i][j]==0)
                {
                    int jj;
                    for(jj=j;jj>0;jj--)
                    {
                        game[i][jj]=game[i][jj-1];
                        if(game[i][jj]!=0)
                        {
                            flag=1;
                        }
                    }
                    game[i][0]=0;
                }
            }
        }
    }
    else if(dir=='R')
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                game[i][j]=saved1[i][j];
            }
        }
        return 0;
    }
    else
    {
        move();
    }
    if(flag==-1)
    {
        move();
    }
    return 1;
}
void save()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            saved1[i][j]=saved2[i][j];
            saved2[i][j]=game[i][j];
        }
    }
}
void begin()
{
    memset(game,0,NUM*NUM*sizeof(int));
    memset(saved1,0,NUM*NUM*sizeof(int));
    memset(saved2,0,NUM*NUM*sizeof(int));
    system("cls");
    printf("Welcome to 2048!\n");
    printf("Please select the size:\n");
    printf("(Input a number between 2 and 6)\n");
    while(scanf("%d",&n))
    {
        if(n<2||n>6)
        {
            printf("Wrong input!\n");
            printf("Please input again:");
        }
        else
        {
            break;
        }
    }
    printf("Please select the difficulty:\n");
    printf("(Input a number which is the pow of 2)\n");
    while(scanf("%d",&m))
    {
        int flag=0;
        unsigned i;
        for(i=2;i<2147483647;i*=2)
        {
            if(i==m)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            printf("Wrong input!\n");
            printf("Please input again:");
        }
        else
        {
            break;
        }
    }
}
int win()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(game[i][j]==m)
            {
                printf("\nYou win!\n");
                return 1;
            }
        }
    }
    return 0;
}
int lose()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(game[i][j]==0)
            {
                return 0;
            }
            if(game[i][j]==game[i-1][j])
            {
                return 0;
            }
            if(game[i][j]==game[i][j-1])
            {
                return 0;
            }
            if(game[i][j]==game[i][j+1])
            {
                return 0;
            }
            if(game[i][j]==game[i+1][j])
            {
                return 0;
            }
        }
    }
    printf("\nYou lose!\n");
    return 1;
}
int again()
{
    printf("Again?(Y/N):");
    char aga;
    fflush(stdin);
    scanf("%c",&aga);
    if(aga=='Y'||aga=='y')
    {
        return 1;
    }
    else if(aga=='N'||aga=='n')
    {
        return -1;
    }
    else
    {
        printf("Wrong input!\n");
        return again();
    }
}
int main()
{
    void generate();
    void show();
    int move();
    void save();
    void begin();
    int win();
    int lose();
    int again();
    while(1)
    {
        begin();
        generate();
        generate();
        show();
        save();
        while(1)
        {
            save();
            if(move())
            {
                generate();
            }
            show();
            if(win()||lose())
            {
                break;
            }
        }
        if(again()==-1)
        {
            break;
        }
    }
    system("pause");
    return 0;
}
