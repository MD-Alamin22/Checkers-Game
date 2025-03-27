#include<stdio.h>
#include<string.h>

void display(char board[8][8])
{
    int i;
    printf("\n");
    for(i=0;i<8;)
    {
        printf("\n  -------------------------");
        printf("\n%d | %c| %c| %c| % c| %c| % c| %c| %c|",i + 1,board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5],board[i][6],board[i][7]);
        i++;
    }
    printf("\n  -------------------------");
    printf("\n    A  B  C  D  E  F  G  H");
}
int main()
{
    intro:;//level for calling

    char name1[25],name2[25],nhigh[25];
    int i,j,x,y,dir,pla,highscr=0,opp;
    char board[8][8],A,B,pos[2];

   for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            board[i][j]=' ';
    }
    printf("\t\t\t\t\t**WELCOME TO THE  CHECKERS GAME**\n\n\n");
    printf("\nEnter the name of the player-1:");
    scanf("%s",name1);
    printf("\nEnter the name of the player-2:");
    scanf("%s",name2);
    printf("\nThe rules are as usual...\n");
    printf("In the end,Higher scorer will wins the game...\n");
    printf("\n 'x'  'o' ");
    printf("\n\nEnter player-1 symbol:");
    scanf(" %c",&A);
    printf("\nEnter  player-2 symbol:");
    scanf(" %c",&B);
    if(A==B)
    {
        printf(" Both the symbols are same....Please try again....... \n\n");
        goto intro;
    }
    printf("\n THE GAME STARTS NOW...");
    char tick=A;
    char TICK=B;
    board[0][0]=B;board[0][2]=B;board[0][4]=B;board[0][6]=B;
    board[1][1]=B;board[1][3]=B;board[1][5]=B;board[1][7]=B;
    board[6][0]=A;board[6][2]=A;board[6][4]=A;board[6][6]=A;
    board[7][1]=A;board[7][3]=A;board[7][5]=A;board[7][7]=A;

    start:
    display(board);
    printf("\n player-1's (%c) turn...",A);
    printf("\n Enter position:");
    scanf("%s",pos);
    printf("\n");
    if(pos[0]== 'A')
        x=0;
    else if(pos[0]== 'B')
        x=1;
    else if(pos[0]== 'C')
        x=2;
    else if(pos[0]== 'D')
        x=3;
    else if(pos[0]== 'E')
        x=4;
    else if(pos[0]== 'F')
        x=5;
    else if(pos[0]== 'G')
        x=6;
    else if(pos[0]== 'H')
        x=7;
    else
    {
        printf("Enter again...");
        goto start;
    }
    if(pos[1]== '1')
        y=0;
    else if(pos[1]== '2')
        y=1;
    else if(pos[1]== '3')
        y=2;
    else if(pos[1]== '4')
        y=3;
    else if(pos[1]== '5')
        y=4;
    else if(pos[1]== '6')
        y=5;
    else if(pos[1]== '7')
        y=6;
    else if(pos[1]== '8')
        y=7;
    else
    {
        printf("Enter again...");
        goto start;
    }
    if(board[y][x]!=A)
    {
        printf("Enter again...");
        goto start;
    }
    printf("Which direction?\n1-upper left diagonal\n2-upper right diagonal\n3-lower left diagonal\n4-lower right diagonal\n");
    scanf(" %d",&dir);
    A=tick;
    B=TICK;

    //direction=1 indicates the upper left diagonal
    if(dir == 1)
    {
        if(x==0 || y==0)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y-1][x-1]==A)
        {
            printf("move invlaid!");
            goto start;
        }
        if(board[y - 1][x - 1]==' ')
        {
            board[y][x]=' ';
            board[--y][--x]=A;
            goto done1;
        }
        if(board[y - 1][x - 1]==B)
        {
            if(x<=1)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y - 2][x - 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y - 1][x - 1]=' ';
                y-=2;x-=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    if(dir==2)
    {
        if(x==7 || y==0)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y - 1][x + 1]==A)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y - 1][x + 1]==' ')
        {
            board[y][x]=' ';
            board[--y][++x]=A;
            goto done1;
        }
        if(board[y - 1][x + 1]==B)
        {
            if(x>=6)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y - 2][x + 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y - 1][x + 1]=' ';
                y-=2;x+=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    if(dir==3)
    {
        if(x==0 || y==7)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x - 1]==A)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x - 1]==' ')
        {
            board[y][x]=' ';
            board[++y][--x]=A;
            goto done1;
        }
        if(board[y + 1][x - 1]==B)
        {
            if(x<=1)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y + 2][x - 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y + 1][x - 1]=' ';
                y+=2;x-=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }
    if(dir==4)
    {
        if(x==7 || y==7)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x + 1]==A)
        {
            printf("move invalid!");
            goto start;
        }
        if(board[y + 1][x + 1]==' ')
        {
            board[y][x]=' ';
            board[++y][++x]=A;
            goto done1;
        }
        if(board[y + 1][x + 1]==B)
        {
            if(x>=6)
            {
                printf("move invalid!");
                goto start;
            }
            if(board[y + 2][x + 2]!=' ')
            {
                printf("move invalid!");
                goto start;
            }
            else
            {
                board[y][x]=' ';
                board[y + 1][x + 1]=' ';
                y+=2;x+=2;
                board[y][x]=A;
                goto done1;
            }
        }
    }


    done1:
        display(board);
        pla=0;opp=0;
        A=tick;
        B=TICK;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==A)
                    pla+=5;//score of player-1
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==B)
                    opp+=5;//score of player-2
            }
        }
        //displays the scores of the players after each moves
        printf("\n\t\t\t\tCurrent scores:");
        printf("\n\t\t\t\t%s = %d",name1,pla);
        printf("\n\t\t\t\t%s = %d",name2,opp);
        if(pla==0 || opp==0)
            goto end;
    printf("\n");
    printf("player-2's (%c) turn...",B);
    again:
            y = rand()%8;
            x = rand()%8;
        if(board[y][x]!=B)
            goto again;
            dir=(rand()%4)+1;
        if(board[y - 1][x - 1]==A && x>1 && y>1)
            dir=1;
        if(board[y - 1][x + 1]==A && x<6 && y>1)
            dir=2;
        if(board[y + 1][x - 1]==A && x>1 && y<6)
            dir=3;
        if(board[y + 1][x + 1]==A && x<6 && y<6)
            dir=4;
        A=tick;
        B=TICK;

        if(dir==1)
        {
            if(x==0 || y==0)
                goto again;
            if(board[y - 1][x - 1]==B)
                goto again;
            if(board[y - 1][x - 1]==' ')
            {
                board[y][x]=' ';
                board[--y][--x]=B;
                goto done2;
            }
            if(board[y - 1][x - 1]==A)
            {
                if(x<=1)
                    goto again;
                if(board[y - 2][x - 2]!=' ')
                    goto again;
                else
                {
                    board[y][x]=' ';
                    board[y - 1][x - 1]=' ';
                    y-=2;x-=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
        if(dir==2)
        {
            if(x==7 || y==0)
                goto again;
            if(board[y - 1][x + 1]==B)
                goto again;
            if(board[y - 1][x + 1]==' ')
            {
                board[y][x]=' ';
                board[--y][++x]=B;
                goto done2;
            }
            if(board[y - 1][x + 1]==A)
            {
                if(x>=6)
                    goto again;
                if(board[y - 2][x + 2]!=' ')
                    goto again;
                else
                {
                    board[y][x]=' ';
                    board[y - 1][x + 1]=' ';
                    y-=2;x+=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
        if(dir==3)
        {
            if(x==0 || y==7)
                goto again;
            if(board[y + 1][x - 1]==B)
                goto again;
            if(board[y + 1][x - 1]==' ')
            {
                board[y][x]=' ';
                board[++y][--x]=B;
                goto done2;
            }
            if(board[y + 1][x - 1]==A)
            {
                if(x>=1)
                    goto again;
                if(board[y + 2][x - 2]!=' ')
                    goto again;
                else
                {
                    board[y][x]=' ';
                    board[y + 1][x - 1]=' ';
                    y+=2;x-=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
        if(dir==4)
        {
            if(x==7 || y==7)
                goto again;
            if(board[y + 1][x + 1]==B)
                goto again;
            if(board[y + 1][x + 1]==' ')
            {
                board[y][x]=' ';
                board[++y][++x]=B;
                goto done2;
            }
            if(board[y + 1][x + 1]==A)
            {
                if(x>=6)
                    goto again;
                if(board[y + 2][x + 2]!=' ')
                    goto again;
                else
                {
                    board[y][x]=' ';
                    board[y + 1][x + 1]=' ';
                    y+=2;x+=2;
                    board[y][x]=B;
                    goto done2;
                }
            }
        }
    done2:
        display(board);

        pla=0;
        opp=0;
        A=tick;
        B=TICK;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==A)
                    pla+=5;
            }
        }
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(board[i][j]==B)
                    opp+=5;
            }
        }
        // displays the scores after each move.
        printf("\n\t\t\t\tCurrent scores:");
        printf("\n\t\t\t\t%s = %d",name1,pla);
        printf("\n\t\t\t\t%s = %d",name2,opp);
        if(pla==0 || opp==0)
            //if score of player-1 or player-2 is 0
            goto end;
        else
            goto start;
    end:
        if(pla>opp)
        {
            printf("\n\n");
            printf("\n%s's score:%d",name1,pla);
            printf("\n%s's score:%d",name2,opp);
            printf("\n%s won the game.....\n\n",name1);
        }
        if(pla<opp)
        {
            printf("\n\n");
            printf("\n%s's score:%d",name1,pla);
            printf("\n%s's score:%d",name2,opp);
            printf("\n%s won the game....\n\n",name2);
        }
        if(pla==opp)
        {
            printf("\n\n");
            printf("\n%s's score:%d",name1,pla);
            printf("\n%s's score:%d",name2,opp);
            printf("\nIt's a draw!!!!\\n\n\n");
    }
    getch();
    return 0;
}
