//Bomberman
#include <stdio.h>
#include<conio.h>
int checkboard(int row,int column,int board_size,char board[board_size][board_size])
{
    if(board[row][column]!=' ')
    {
        printf("Invalid input.Try again \n");    
        printf("%c",board[row][column]);
        return 1;
    }
    return 0;
}
void printboard(int board_size,char board[board_size][board_size])
{
    int i,j;
    for(i=0;i<board_size;i++)
    {
        for(j=0;j<board_size;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
void checkvillain_or_key(int board_size,char board[board_size][board_size],int row,int column)
{
    if(board[row][column]=='V')
    {
        clrscr();
        printf("You lose!");
        exit(0);
    }
    if(board[row][column]=='K')
    {
        clrscr();
        printf("You win!");
        exit(0);
    }
}
int main()
{
    int board_size;
    scanf("%d",&board_size);
    char board[board_size][board_size];
    int i,j;
    int bomb_flag=0;
    //draw the board;
    for(i=0;i<board_size;i++)
    {
        for(j=0;j<board_size;j++)
        {
            if((i==0)&&(j>=1))
            {
                board[i][j]=(char)64+j;
            }
            else if(((i==1)||(i==board_size-1))&&(j>=1))
            {
                board[i][j]='*';
            }
            else if(((j==1)||(j==board_size-1))&&(i>=1))
            {
                board[i][j]='*';
            }
            else if((j==0)&&(i>=1))
            {
                board[i][j]=(char)64+i;
            }
            else
            {
                board[i][j]=' ';
            }
        }
    }
        //fixed walls
        if(board_size<26)
        {
        board[4][4]='*';
        board[5][5]='*';
        board[3][4]='*';
        board[7][2]='*';
        board[6][4]='*';
        board[8][2]='*';
        board[2][6]='*';
        }
        if(board_size>10)
        {
        board[12][5]='*';
        board[15][8]='*';
        board[14][3]='*';
        board[11][7]='*';
        board[15][12]='*';
        }
    printboard(board_size,board);
    int check;
    char str[2];
    a:
    printf("Enter the player location \n");
    scanf("%s",str);
    int row=str[0]-64;
    int column=str[1]-64;
    check=checkboard(row,column,board_size,board);
    if(check==1)
    {
        goto a;
    }
    board[row][column]='P';
    char key_location[2];
    b:
    printf("\n Enter the key location \n");
    scanf("%s",key_location);
    row=key_location[0]-64;
    column=key_location[1]-64;
    check=checkboard(row,column,board_size,board);
    if(check==1)
    {
        goto b;
    }
    board[row][column]='K';
    printboard(board_size,board);
    printf("\n Enter the villain count\n ");
    int villain;
    scanf("%d",&villain);
    for(i=0;i<villain;i++)
    {
        char villain_location[2];
        c:
        printf("Enter the location of %d villain \n",i+1);
        scanf("%s",villain_location);
        row=villain_location[0]-64;
        column=villain_location[1]-64;
        check=checkboard(row,column,board_size,board);
        if(check==1)
        {
        goto c;
        }
        board[row][column]='V';
        printboard(board_size,board);
    }
    printf("\n Enter the BRICKS count \n");
    int bricks;
    scanf("%d",&bricks);
    for(i=0;i<bricks;i++)
    {
        char bricks_location[2];
        d:
        printf("Enter the location of %d Brick \n",i+1);
        scanf("%s",bricks_location);
        row=bricks_location[0]-64;
        column=bricks_location[1]-64;
        check=checkboard(row,column,board_size,board);
        if(check==1)
        {
        goto d;
        }
        board[row][column]='B';
        printboard(board_size,board);
    }
    //movement
    int bomb_row;
    int bomb_column;
    char key[10];
    row=str[0]-64;
    column=str[1]-64;
    while(1)
    {
    printf("Enter the direction Keys(W,A,S,D,Q,E,Z,C,X-To detonate or plant bomb) \n");
    scanf("%s",key);
    char temp=key[0];
    switch(temp)
    {
        case 'W':
                    if((board[row-1][column]==' ')||(board[row-1][column]=='V')||(board[row-1][column]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row-1,column);
                    board[row][column]=' ';
                    board[row-1][column]='P';
                    row=row-1;
                    printboard(board_size,board);
                    }
                    break;
        case 'A':
                    if((board[row][column-1]==' ')||(board[row][column-1]=='V')||(board[row][column-1]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row,column-1);
                    board[row][column]=' ';
                    board[row][column-1]='P';
                    column=column-1;
                    printboard(board_size,board);
                    }
                    break;
        case 'S':
                    if((board[row+1][column]==' ')||(board[row+1][column]=='V')||(board[row+1][column]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row+1,column);
                    board[row][column]=' ';
                    board[row+1][column]='P';
                    row=row+1;
                    printboard(board_size,board);
                    }
                    break;
        case 'D':
                    if((board[row][column+1]==' ')||(board[row][column+1]=='V')||(board[row][column+1]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row,column+1);
                    board[row][column]=' ';
                    board[row][column+1]='P';
                    column=column+1;
                    printboard(board_size,board);
                    }
                    break;
        case 'Q':
                    if((board[row-1][column-1]==' ')||(board[row-1][column-1]=='V')||(board[row-1][column-1]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row-1,column-1);
                    board[row][column]=' ';
                    board[row-1][column-1]='P';
                    row=row-1;
                    column=column-1;
                    printboard(board_size,board);
                    }
                    break;
        case 'E':
                    if((board[row-1][column+1]==' ')||(board[row-1][column+1]=='V')||(board[row-1][column+1]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row-1,column+1);
                    board[row][column]=' ';
                    board[row-1][column+1]='P';
                    column=column+1;
                    row=row-1;
                    printboard(board_size,board);
                    }
                    break;
        case 'Z':
                    if((board[row+1][column-1]==' ')||(board[row+1][column-1]=='V')||(board[row+1][column-1]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row+1,column-1);
                    board[row][column]=' ';
                    board[row+1][column-1]='P';
                    column=column-1;
                    row=row+1;
                    printboard(board_size,board);
                    }
                    break;
        case 'C':
                    if((board[row+1][column+1]==' ')||(board[row+1][column+1]=='V')||(board[row+1][column+1]=='K'))
                    {
                    checkvillain_or_key(board_size,board,row+1,column+1);
                    board[row][column]=' ';
                    board[row+1][column+1]='P';
                    column=column+1;
                    row=row+1;
                    printboard(board_size,board);
                    }
                    break;
        case 'X':   
                    printf("\n 1.Plant bomb \n 2.Detonate \n");
                    int choice=0;
                    scanf("%d",&choice);
                    if(choice==1)
                    {
                        if(bomb_flag==1)
                        {
                            printf("only one bomb can be planted!\n");
                        }
                        else
                        {
                        bomb_flag=1;
                        bomb_row=row;
                        bomb_column=column;
                        }                        
                    }
                    else if(choice==2)
                    {
                        bomb_flag=0;
                        if(board[bomb_row-1][bomb_column]=='P'||board[bomb_row][bomb_column-1]=='P'||board[bomb_row][bomb_column+1]=='P'||board[bomb_row+1][bomb_column]=='P')
                        {
                            clrscr();
                            printf("You lose");
                            exit(0);
                        }
                        board[bomb_row][bomb_column]=' ';
                        board[bomb_row-1][bomb_column]=' ';
                        board[bomb_row][bomb_column-1]=' ';
                        board[bomb_row][bomb_column+1]=' ';
                        board[bomb_row+1][bomb_column]=' ';
                        printboard(board_size,board);
                    }
                    break;
                
                    
    }
    if((bomb_flag==1)&&(board[bomb_row][bomb_column]!='P'))
    {
        board[bomb_row][bomb_column]='X';
        printboard(board_size,board);
    }
    }
    return 0;
}


