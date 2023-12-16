/*****************************************************************************
* | File      	:   LCD_1in3_test.c
* | Author      :   Waveshare team
* | Function    :   1.3inch LCD  test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2021-08-20
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "LCD_Test.h"
#include "LCD_1in3.h"

#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int snake(void)
{

    DEV_Delay_ms(100);
    printf("LCD_1in3_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }
    DEV_SET_PWM(50);
    /* LCD Init */
    printf("1.3inch LCD demo...\r\n");
    LCD_1IN3_Init(HORIZONTAL);
    LCD_1IN3_Clear(WHITE);
    
    //LCD_SetBacklight(1023);
    UDOUBLE Imagesize = LCD_1IN3_HEIGHT * LCD_1IN3_WIDTH * 2;
    UWORD *BlackImage;
    if((BlackImage = (UWORD *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }
    // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
    Paint_NewImage((UBYTE *)BlackImage, LCD_1IN3.WIDTH, LCD_1IN3.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(WHITE);
    
    // /* GUI */
    printf("drawing...\r\n");
    // /*2.Drawing on the image*/
#if 0
    Paint_DrawPoint(2,1, BLACK, DOT_PIXEL_1X1,  DOT_FILL_RIGHTUP);//240 240
    Paint_DrawPoint(2,6, BLACK, DOT_PIXEL_2X2,  DOT_FILL_RIGHTUP);
    Paint_DrawPoint(2,11, BLACK, DOT_PIXEL_3X3, DOT_FILL_RIGHTUP);
    Paint_DrawPoint(2,16, BLACK, DOT_PIXEL_4X4, DOT_FILL_RIGHTUP);
    Paint_DrawPoint(2,21, BLACK, DOT_PIXEL_5X5, DOT_FILL_RIGHTUP);
    Paint_DrawLine( 10,  5, 40, 35, MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
    Paint_DrawLine( 10, 35, 40,  5, MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);

    Paint_DrawLine( 80,  20, 110, 20, CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawLine( 95,   5,  95, 35, CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);

    Paint_DrawRectangle(10, 5, 40, 35, RED, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    Paint_DrawRectangle(45, 5, 75, 35, BLUE, DOT_PIXEL_2X2,DRAW_FILL_FULL);

    Paint_DrawCircle(95, 20, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawCircle(130, 20, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);


    Paint_DrawNum (50, 40 ,9.87654321, &Font20,3,  WHITE,  BLACK);
    Paint_DrawString_EN(1, 40, "ABC", &Font20, 0x000f, 0xfff0);
    Paint_DrawString_CN(1,60, "��ӭʹ��",  &Font24CN, WHITE, BLUE);
    Paint_DrawString_EN(1, 100, "WaveShare", &Font16, RED, WHITE); 
    char str_width[256];
    char str_height[256];
    sprintf(str_width, "%d", LCD_1IN3.WIDTH);
    sprintf(str_height, "%d", LCD_1IN3.HEIGHT);
    Paint_DrawString_EN(1, 120, str_width, &Font16, RED, WHITE); 
    Paint_DrawString_EN(1, 140, str_height, &Font16, RED, WHITE); 

    // /*3.Refresh the picture in RAM to LCD*/
    LCD_1IN3_Display(BlackImage);
    DEV_Delay_ms(2000);

#endif
#if 0
     Paint_DrawImage(gImage_1inch3_1,0,0,240,240);
     LCD_1IN3_Display(BlackImage);
     DEV_Delay_ms(2000);
     

     
#endif
#if 1

    uint8_t keyA = 15; 
    uint8_t keyB = 17; 
    uint8_t keyX = 19; 
    uint8_t keyY = 21;

    uint8_t up = 2;
	uint8_t down = 18;
	uint8_t left = 16;
	uint8_t right = 20;
	uint8_t ctrl = 3;
   

    SET_Infrared_PIN(keyA);    
    SET_Infrared_PIN(keyB);
    SET_Infrared_PIN(keyX);
    SET_Infrared_PIN(keyY);
		 
	SET_Infrared_PIN(up);
    SET_Infrared_PIN(down);
    SET_Infrared_PIN(left);
    SET_Infrared_PIN(right);
    SET_Infrared_PIN(ctrl);

    
    // Paint_Clear(WHITE);
    // Paint_DrawRectangle(208, 15, 237, 45, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(208, 75, 237, 105, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(208, 135, 237, 165, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(208, 195, 237, 225, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(60, 60, 91, 90, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(60, 150, 91, 180, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(15, 105, 46, 135, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(105, 105, 136, 135, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // Paint_DrawRectangle(60, 105, 91, 135, 0xF800, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
    // LCD_1IN3_Display(BlackImage);

    void clearPaint() {
        Paint_Clear(WHITE);
        LCD_1IN3_Display(BlackImage);
    }
    struct PaintedRect {
        int x;
        int y;
        int width;
        int height;
        struct PaintedRect *next;
    };
    struct PaintedRect *paint_to_clear = NULL;
    void fillRect(UWORD x, UWORD y, UWORD width, UWORD height, UWORD color) {
        Paint_DrawRectangle(x, y, x + width, y + height, color, DOT_PIXEL_2X2, DRAW_FILL_FULL);
        LCD_1IN3_DisplayWindows(x, y, x + width, y + height, BlackImage);
        
        struct PaintedRect *painted_rect = malloc(sizeof(struct PaintedRect));
        painted_rect->x = x;
        painted_rect->y = y;
        painted_rect->width = width;
        painted_rect->height = height;
        painted_rect->next = paint_to_clear;
        paint_to_clear = painted_rect;
    }
    void clearRects() {
        for (struct PaintedRect *curr_rect = paint_to_clear; curr_rect != NULL; curr_rect = curr_rect->next) {
            Paint_DrawRectangle(
                curr_rect->x, curr_rect->y,
                curr_rect->x + curr_rect->width, curr_rect->y + curr_rect->height,
                WHITE, DOT_PIXEL_2X2, DRAW_FILL_FULL);
            LCD_1IN3_DisplayWindows(
                curr_rect->x, curr_rect->y,
                curr_rect->x + curr_rect->width, curr_rect->y + curr_rect->height,
                BlackImage);
        }

        struct PaintedRect *free_rect = paint_to_clear;
        while (paint_to_clear != NULL) {
            free_rect = paint_to_clear;
            paint_to_clear = paint_to_clear->next;
            free(free_rect);
        }
    }

    struct V {
        char x;
        char y;
    };
    int TILE_SIZE = 10;
    struct V DIM = {LCD_1IN3.WIDTH / TILE_SIZE, LCD_1IN3.HEIGHT / TILE_SIZE};

    struct V snake_head = {DIM.x / 3, DIM.y / 2};
    struct V snake_dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char snake_dir_i;
    char last_snake_dir_i = snake_dir_i;
    int snake_grow;
    int snake_len;
    char snake_dead;
    int max_len = DIM.x * DIM.y;
    int snake_body[max_len + 1];
    for (int i = 0; i < max_len + 1; i++) {
        snake_body[i] = -1;
    }
    void moveSnake() {
        last_snake_dir_i = snake_dir_i;
        struct V snake_dir = snake_dirs[snake_dir_i];
        struct V new_head = {snake_head.x + snake_dir.x, snake_head.y + snake_dir.y};
        if (new_head.x < 0 || new_head.x > DIM.x - 1 || new_head.y < 0 || new_head.y > DIM.y - 1) {
            snake_dead = 1;
        }
        if (snake_dead) return;
        
        // move position dirs down by one
        // move head & insert snake_dir_i
        // only keep last position dir if snake_grow, set snake_grow to false
        snake_head.x = new_head.x;
        snake_head.y = new_head.y;
    
        int snake_last_i;
        for (snake_last_i = 0; snake_last_i < max_len; snake_last_i++) {
            char body_dir_i = snake_body[snake_last_i];
            if (body_dir_i < 0) break;
        }
        if (snake_grow) {
            snake_len += 1;
            snake_grow -= 1;
        }
        for (int i = snake_len - 1; i > 0; i--) {
            snake_body[i] = snake_body[i - 1];
        }
        snake_body[0] = snake_dir_i;
        
        struct V curr_pos = {new_head.x, new_head.y};
        for (int i = 0; i < max_len; i++) {
            if (i > 0 && new_head.x == curr_pos.x && new_head.y == curr_pos.y) {
                snake_dead = 1;
                break;
            }
            int body_dir_i = snake_body[i];
            if (body_dir_i < 0) break;
            struct V body_dir = snake_dirs[body_dir_i];
            curr_pos.x = curr_pos.x - body_dir.x;
            curr_pos.y = curr_pos.y - body_dir.y;
        }
    }
    void drawSnake() {
        struct V curr_pos = {snake_head.x, snake_head.y};
        for (int i = 0; i < max_len; i++) {
            fillRect(curr_pos.x * TILE_SIZE, curr_pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0x0f00);
            int body_dir_i = snake_body[i];
            if (body_dir_i < 0) break;
            struct V body_dir = snake_dirs[body_dir_i];
            curr_pos.x = curr_pos.x - body_dir.x;
            curr_pos.y = curr_pos.y - body_dir.y;
        }
    }

    struct V apple = {0, 0};
    int score = 0;
    srand(time(NULL));
    void spawnApple() {
        apple.x = rand() % DIM.x;
        apple.y = rand() % DIM.y;
    }
    void drawApple() {
        fillRect(apple.x * TILE_SIZE, apple.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, 0xf000);
    }

    void newGame() {
        clearPaint();
        spawnApple();
        for (int i = 0; i < max_len; i++) {
            if (snake_body[i] < 0) break;
            snake_body[i] = -1;
        }
        snake_grow = 2;
        snake_len = 1;
        snake_dead = 0;
        snake_head.x = DIM.x / 3;
        snake_head.y = DIM.y / 2;
        snake_dir_i = 0;
    }
    newGame();


    clock_t start = clock();
    int i = 0;
    clearPaint();
    drawApple();
    drawSnake();
    while (1) {
        if (DEV_Digital_Read(up) == 0 && last_snake_dir_i != 1) snake_dir_i = 3;
        if (DEV_Digital_Read(down) == 0 && last_snake_dir_i != 3) snake_dir_i = 1;
        if (DEV_Digital_Read(left) == 0 && last_snake_dir_i != 0) snake_dir_i = 2;
        if (DEV_Digital_Read(right) == 0 && last_snake_dir_i != 2) snake_dir_i = 0;
        if (DEV_Digital_Read(keyA) == 0 && snake_dead) newGame();
        
        clock_t elapsed = clock() - start;
        int elapsed_ms = elapsed * 1000 / CLOCKS_PER_SEC;
        i += 1;
        if (i > 70000) {
        // if (elapsed_ms > 250) {
            i = 0;

            clearRects();
            drawApple();
            drawSnake();

            // spawnApple();
            moveSnake();
            if (snake_head.x == apple.x && snake_head.y == apple.y) {
                score += 1;
                spawnApple();
                snake_grow = 1;
            }
        }
    }

#endif

    /* Module Exit */
    free(BlackImage);
    BlackImage = NULL;
    
    
    DEV_Module_Exit();
    return 0;
}
