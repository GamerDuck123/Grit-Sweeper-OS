#include "util.h"
#include "screen.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "timer.h"
#include "font.h"
#include "system.h"
#include "keyboard.h"
#include "fpu.h"

u8 *SCREEN = (u8 *) 0xA0000;
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT)
#define HEIGHT 10
#define WIDTH 10
#define MINES_TOTAL 5

// int END_GAME = 0;
// int BOARD[10][10];
// int CLICKED_BOARD[10][10];

// void initializeBoard(){
//     for (int i = 0; i < HEIGHT; i++){
//         for (int j = 0; j < WIDTH; j++){
//             BOARD[i][j] = 0;
//         }
//     }

//     int mines = 0;
//     int i = 0;
//     int j = 0;
//     do {
//         i = rand()%(HEIGHT);
//         j = rand()%(WIDTH);
//         if (BOARD[i][j] != -1) {
//             BOARD[i][j] = -1;
//             mines++;
//         }
//     } while(mines < MINES_TOTAL);
    
//     int yy = 1;
//     int xx = 1;
//     while(xx < WIDTH) {
//         while(yy < HEIGHT) {
//             if (BOARD[yy][xx] != -1 && (yy != 0 && (yy - 1) < HEIGHT) && (yy + 1) < HEIGHT && (xx != 0 && (xx - 1) < WIDTH) && (xx + 1) < WIDTH) {
//                 if(BOARD[yy-1][xx-1] == -1) {BOARD[yy][xx]++;}
//                 if((BOARD[yy-1][xx] == -1)) {BOARD[yy][xx]++;}
//                 if((BOARD[yy][xx-1] == -1)) {BOARD[yy][xx]++;}
//                 if((BOARD[yy-1][xx+1] == -1)) {BOARD[yy][xx]++;}
//                 if((BOARD[yy+1][xx-1] == -1)) {BOARD[yy][xx]++;}
//                 if((BOARD[yy+1][xx] == -1)) {BOARD[yy][xx]++;}
//                 if((BOARD[yy][xx+1] == -1)) {BOARD[yy][xx]++;}
//                 if((BOARD[yy+1][xx+1] == -1)) {BOARD[yy][xx]++;}
//             }
//             yy++;
//         }
//         yy = 1;
//         xx++;
//     }
// }
    

// void renderBoard(){
//     for (int i = 0; i < HEIGHT; i++){
//         for (int j = 0; j < WIDTH; j++){
//             if (BOARD[i][j] != 0) {draw(BOARD[i][j]);}
//             else if (BOARD[i][j] == 9) {draw(" X ");}
//             else {draw("0");}
//         }
//         draw("\n");
//     }
// }

// void draw(char value) {

// }

// void checkValue(int x, int y) {
//     if (BOARD[y][x] == -1) {
//         endGame();
//     } else if (BOARD[y][x] == 0) {
//         CLICKED_BOARD[y][x] = 9;
//     } else {
//         CLICKED_BOARD[y][x] = BOARD[y][x];
//     }
// }

// void endGame() {
//     END_GAME = 1;
// }

// void gameLoop()  {
//     while (END_GAME != 1) {
//         int x, y;
//         draw("\nEnter the x value, then a space, then the y value:");
//         scanf("%d %d", &x, &y);  
//         draw("%d %d\n");
//         checkValue(x, y);
//     }
    
//     for (int i = 0; i < HEIGHT; i++){free(BOARD[i]);} 
//     free(BOARD);
//     draw("Game ended");
// }

void _main(u32 magic) {
    memset(SCREEN, 0x32, SCREEN_SIZE);
   // idt_init();
   // isr_init();
   // fpu_init();
   // irq_init();
    screen_init();
   // timer_init();
   // keyboard_init();
    for (;;) {}
    // for (int i = 0; i < HEIGHT; i++){
    //     for (int j = 0; j < WIDTH; j++){
    //         CLICKED_BOARD[i][j] = 0;
    //     }
    // }
    // initializeBoard();
    // gameLoop();
}
