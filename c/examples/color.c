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

int color(void)
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

    void fillRect(UWORD x, UWORD y, UWORD width, UWORD height, UWORD color) {
        Paint_DrawRectangle(x, y, x + width, y + height, color, DOT_PIXEL_1X1, DRAW_FILL_FULL);
        LCD_1IN3_DisplayWindows(x, y, x + width, y + height, BlackImage);
    }

    struct V {
        char x;
        char y;
    };
    int TILE_SIZE = 1;
    struct V DIM = {LCD_1IN3.WIDTH / TILE_SIZE, LCD_1IN3.HEIGHT / TILE_SIZE};

    int r = 0;
    int g = 0;
    int b = 0;
    int i = 0;
    while (1) {
        i += 1;
        if (i > 70000) {
            r = (r + 1) % 16;
            g = (g + 2) % 16;
            b = (b + 3) % 16;
            int rgb = (r * 16 * 16 + g * 16 + b) * 16;
            fillRect(0, 0, DIM.x, DIM.y, rgb);
        }
    }

#endif

    /* Module Exit */
    free(BlackImage);
    BlackImage = NULL;
    
    
    DEV_Module_Exit();
    return 0;
}
