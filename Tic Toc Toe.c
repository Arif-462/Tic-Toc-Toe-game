#include<stdio.h>
#include<stdbool.h>
int iswin(int arr[][4], int n)
{
    for(int i=1; i<=n; i++)
    {
        if(arr[i][1]==arr[i][2] && arr[i][2]== arr[i][3] && arr[i][1]!=-1)
        {
            return arr[i][1];
        }
    }
    for(int j=1; j<=n; j++)
    {
        if(arr[1][j]==arr[2][j] && arr[2][j]== arr[3][j] && arr[1][j]!=-1)
        {
            return arr[1][j];
        }
    }
    if(arr[1][1]==arr[2][2]&& arr[2][2]==arr[3][3]&& arr[1][1]!=-1)
    {
        return arr[1][1];
    }
    if(arr[3][1]==arr[2][2]&&arr[2][2]==arr[1][3] && arr[3][1]!=-1)
    {
        return arr[3][1];
    }


    return -1;
}
void grid(int arr[][4], int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j]==-1)
            {
                printf(" ");
            }
            if(arr[i][j]==1)
                printf("X");
            if(arr[i][j]==2)
                printf("O");
            if(j<n)
            {
                printf("\t|\t");
            }
        }
        printf("\n");
        if(i<n)
            printf("___________________________________");
        printf("\n\n");
    }

}

void win_grid(int arr[][4], int n, int winer)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(arr[i][j]==winer)
            {
                if(arr[i][j]==1)
                {
                    printf("x");
                }
                else
                {
                    printf("o");
                }
            }
            else
            {
                printf(" ");
            }
            if(j<n)
            {
                printf("\t|\t");
            }
        }
        printf("\n");
        if(i<n)
            printf("___________________________________");
        printf("\n\n");
    }

}
int main()
{
    printf("Wellcome To Our Gaming Zone!!*Arif*!!\n");
    int i,j,n=3;
    int arr[4][4];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            arr[i][j]= -1;
        }
        printf("\n");
    }

    bool player1=true;
    bool player2=false;

    while(true)
    {
        grid(arr,n);
        if(player1==true)
        {

            int r,c;
            flag:
            printf("player 1 turn (x), Enter row and column : ");
            //printf("\n");
            scanf("%d %d", &r, &c);
            if(arr[r][c] != -1)
            {
                printf("Invalid row and column enter again\n");
                goto flag;
            }
            arr[r][c]= 1 ;
            player1=false;
            player2=true;
        }

        else
        {
            int r,c;
            start:
            printf("player 2 turn (o), Enter row and column : ");
            //printf("\n");
            scanf("%d %d", &r, &c);
            if(arr[r][c]!= -1)
            {
                printf("Invalid row and column Enter again\n");
                goto start;
            }
            arr[r][c]= 2 ;
            player2=false;
            player1=true;
        }
        printf("\n");

        if(iswin(arr,n)==1)
        {
            printf("Player 1 is win!!\n");
            break;
        }
        else if(iswin(arr,n)==2)
        {
            printf("Player 2 is win!!\n");
            break;
        }
    }
    printf("\n");
    win_grid(arr,n,iswin(arr,n));

    return 0;
}
