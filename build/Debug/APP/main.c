#include <util/delay.h>
#include "../HAL/LCD/LCD_Header.h"
#include "../MCAL/DIO/DIO_Header.h"

#define SNAKE_CHAR      0
#define SNAKE_LENGTH    5
#define DELAY_MS        25

#define KEYS_DDR        DDRD_REG
#define KEYS_PORT       PORTD_REG
#define KEYS_PINS       PIND_REG

#define UP              PD4
#define DOWN            PD5
#define LEFT            PD6
#define RIGHT           PD7


typedef struct {
    u8 row;
    u8 col;
} Position;

// Snake position buffer
Position snake_body[SNAKE_LENGTH];
u8 head_index = 0;

// Draw a dot on LCD
void draw_dot(u8 row, u8 col) {
    LCD_SetCursor(row, col);
    LCD_WriteChar(SNAKE_CHAR);
}

// Clear a cell on LCD
void clear_dot(u8 row, u8 col) {
    LCD_SetCursor(row, col);
    LCD_WriteChar(' ');
}

// Store new head position and clear tail
void move_snake(u8 new_row, u8 new_col) {
    // Clear tail
    Position tail = snake_body[head_index];
    clear_dot(tail.row, tail.col);

    // Add new head
    snake_body[head_index].row = new_row;
    snake_body[head_index].col = new_col;
    draw_dot(new_row, new_col);

    // Move index
    head_index = (head_index + 1) % SNAKE_LENGTH;

    _delay_ms(DELAY_MS);
}

void setup(){
    LCD_init_8bit();
    //Init the keys
    DIO_PINMode(KEYS_DDR,UP,INPUT);
    DIO_PINMode(KEYS_DDR,DOWN,INPUT);
    DIO_PINMode(KEYS_DDR,LEFT,INPUT);
    DIO_PINMode(KEYS_DDR,RIGHT,INPUT);

    //Add pull up to the keys
    DIO_DigitalWrite(KEYS_PORT,UP,HIGH);
    DIO_DigitalWrite(KEYS_PORT,DOWN,HIGH);
    DIO_DigitalWrite(KEYS_PORT,LEFT,HIGH);
    DIO_DigitalWrite(KEYS_PORT,RIGHT,HIGH);



    u8 dot_symbol[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00100,
        0b00000,
        0b00000,
        0b00000,
        0b00000
    };

    LCD_CreateCustomChar(SNAKE_CHAR, dot_symbol);
    // Initialize snake positions off-screen
    for (u8 i = 0; i < SNAKE_LENGTH; i++) {
        snake_body[i].row = 0;
        snake_body[i].col = 0;
    }

    
    

}

void loop_snake(){
    // ➡ Top row right
    for (u8 col = 0; col < 16; col++) {
        move_snake(0, col);
    }

    // ⬇ Right column down
    move_snake(1, 15);

    // ⬅ Bottom row left
    for (int col = 14; col >= 0; col--) {
        move_snake(1, col);
    }

    // ⬆ Left column up
    move_snake(0, 0);
}

int main(){
    setup();
    while (1) {
        loop_snake();
    }
    return 0;
}
