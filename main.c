/*

    failed snake game: basically tried to write a snake game and failed miserably.
    not a total waste, as I have set up a resolution (20x20), set up basic multithreading,
    and even wrote in a fun little animation. feel free to add on to this if you so desire

    ...or not.


*/

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#define X_MAX 20
#define Y_MAX 20
#define GOODS '*'
#define SNAKE_BODY 'O'
#define WP 'w'
#define AP 'a'
#define SP 's'
#define DP 'd'

uint8_t chars[3]={WP,AP,SP,DP};

static uint8_t screen[20][20];

uint8_t x,y;

char decide;

char key_pressed;

void scrn_prnt();

void key_in();

void pressed(char key, uint16_t c, uint16_t d);

void first(){
    char meme=getchar();
    decide=meme;
}

int main()
{
    printf("wat$ the pa$$word?");
    first();

    if(decide=='w'){
    printf("now pre$enting: g00d: the m0vi3 (tm)");
    Sleep(3000);
    system("cls");
    static pthread_t cool, cool2;

    pthread_create(&cool,NULL,scrn_prnt,NULL);
    pthread_create(&cool2,NULL,key_in,NULL);

    pthread_join(cool,NULL);
    pthread_join(cool2, NULL);
    }//failed multithreading
    Sleep(500);
    printf("the end!!!1 m0ney now pls ty$$$$");
    Sleep(1000);
    system("cls");
    printf("d0n't worry, is just you're friendly neighborh00d\n\n");
    Sleep(2000);
    printf("PYRAMID $CHEME\n\n\n");
    Sleep(1000);
    system("cls");
    printf("written by the Control Alt Defeat (tm)\nPress enter to continue");
    getchar();
    return 0;
}
//c & d are x & y (fills in for x & y in scrn_draw)
void scrn_prnt(){
    uint8_t c,d,i;
    c=0;
    d=0;
    while(c<X_MAX && d<Y_MAX){
        c++;
        d++;
        scrn_draw(c,d,'O');
        system("cls");
        if(c==8 && d==8){
            scrn_draw(10,10,'m');
        }
    }
}



void key_in(){
    uint8_t keyin = getchar();//key pressd (w, a, s, or d control the snake (or would if I had finished this)
    key_pressed = keyin;
}

void scrn_draw(uint16_t a, uint16_t b, uint8_t letr){
    for(y=0;y<X_MAX;y++){//column
        for(x=0;x<Y_MAX;x++){//row
            screen[x][y]='.';//defines each element as a period
            if((x==a && y==b)&& letr!=NULL){//print statement
                screen[a][b]=letr;//fills an area specified by x and y with a character
                printf("%c  ",screen[a][b]);
            }else{
                printf("%c  ",screen[x][y]);//fills row with characters
            }
       }
       printf("\n");//newline after column
    }
    printf("\n\n\n\n\n");
    printf("%c",key_pressed);//for debug: prints the key you pressed :3
}

void pressed(char key, uint16_t c, uint16_t d)
{
    while(key_pressed==key){//failed function to control the snake
        scrn_draw(c,d,'O');
        system("cli");
    }
}
