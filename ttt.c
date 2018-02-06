#include <stdio.h>

char a[9]={'0','1','2','3','4','5','6','7','8'};
int n;

void main()
{
    char p1[10],p2[10];
    char p='X',q='O';
    int w=-1;
    
    printf("LETS PLAY TIC TAC TOE\n");
    printf("Enter player'X' name\n");
    scanf("%s",&p1);
    printf("Enter player'O' name\n");
    scanf("%s",&p2);
    
    printf("You need to enter number of any box\n");
    play();
    
    
    while(w!=1 || w!=0)
    {
        printf("%s ki turn\n",p1);
        scanf("%d",&n);
        a[n]=p;
        play();
        w=check();
        if(w==0 || w==1)
        {
            printf("%s ki Jeet\n",p1);
            break;
        }
        else
        {
            printf("%s ki turn\n",p2);
            scanf("%d",&n);
            a[n]=q;
            play();
            w=check();
            if(w==0 || w==1)
            {
                printf("%s ki Jeet\n",p2);
                break;
            }
        }
    }
    
}

int check()
{
    if( (n==0||n==3||n==6) && (a[n]==a[n+1]&&a[n+1]==a[n+2]) )
        return 1;
    else if( (n==1||n==4||n==7) && (a[n]==a[n-1]&&a[n]==a[n+1]) )
        return 1;
    else if( (n==2||n==5||n==8) && (a[n]==a[n-1]&&a[n-1]==a[n-2]) )
        return 1;
    else if( (n==0||n==1||n==2) && (a[n]==a[n+3]&&a[n+3]==a[n+6]) )
        return 1;
    else if( (n==3||n==4||n==5) && (a[n]==a[n-3]&&a[n+3]==a[n]) )
        return 1;
    else if( (n==6||n==7||n==8) && (a[n]==a[n-3]&&a[n-3]==a[n-6]) )
        return 1;
    else if((a[0]==a[4]&&a[4]==a[8])||(a[2]==a[4]&&a[4]==a[6]))
        return 1;
    else if(a[0]!='0' && a[1]!='1' && a[2]!='2' && a[3]!='3' && a[4]!='4' && a[5]!='5' && a[6]!='6' && a[7]!='7' && a[8]!='8')
        return 0;
    else
        return -1;
}

void play()
{
    printf(" %c | %c | %c \n",a[0],a[1],a[2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",a[3],a[4],a[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",a[6],a[7],a[8]);
}