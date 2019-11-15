#include "stm32f4xx_hal.h"
#include "fonts.h"

#ifndef oled
#define oled

// I2c port as defined in main generated by CubeMx
#define OLED_I2C_PORT		hi2c1
// I2c address
#define OLED_I2C_ADDR        0x78
// SSD1306 width in pixels
#define OLED_WIDTH           128
// SSD1306 LCD height in pixels
#define OLED_HEIGHT          64


//
//  Enumeration for screen colors
//
typedef enum {
	Black = 0x00, // Black color, no pixel
	White = 0x01  //Pixel is set. Color depends on LCD
} OLED_COLOR;

//
//  Struct to store transformations
//
typedef struct {
	uint16_t CurrentX;
	uint16_t CurrentY;
	uint8_t Inverted;
	uint8_t Initialized;
} OLED_t;

//	Definition of the i2c port in main
extern I2C_HandleTypeDef OLED_I2C_PORT;

//
//  Function definitions
//
uint8_t oled_Init(void);
void oled_Fill(OLED_COLOR color);
void oled_UpdateScreen(void);
void oled_DrawVLine(uint8_t x1, uint8_t x2, uint8_t y, OLED_COLOR color);
void oled_DrawHLine(uint8_t y1, uint8_t y2, uint8_t x, OLED_COLOR color);
void oled_DrawSquare(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, OLED_COLOR color);
void oled_DrawPixel(uint8_t x, uint8_t y, OLED_COLOR color);
char oled_WriteChar(char ch, FontDef Font, OLED_COLOR color);
char oled_WriteString(char* str, FontDef Font, OLED_COLOR color);
void oled_SetCursor(uint8_t x, uint8_t y);

#endif
