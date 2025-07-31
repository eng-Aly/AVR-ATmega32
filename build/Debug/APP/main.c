#include <util/delay.h>
#include "../HAL/LCD/LCD_Header.h"
#include "../MCAL/DIO/DIO_Header.h"

#define SNAKE_CHAR      0
#define SNAKE_LENGTH    10
#define DELAY_MS        25

#define KEYS_DDR        DDRD_REG
#define KEYS_PORT       PORTD_REG
#define KEYS_PINS       PIND_REG

#define UP              PD4
#define DOWN            PD5
#define LEFT            PD6
#define RIGHT           PD7


#define MAX_COL 16
#define MAX_ROW 2 


typedef enum { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP } Direction;
const int8_t drow[] = { 0, +1,  0, -1 };
const int8_t dcol[] = {+1,  0, -1,  0 };


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

void snake_game_pooling(u8 *L_flag,u8 *R_flag ,u8 *U_flag,u8 *D_flag,u8 *current_row,u8 *current_column){

    for (u8 col = 0; col < 16; col++) {
        move_snake(0, col);
        
        if(~(DIO_DigitalRead(KEYS_PINS,UP))) {
            LCD_WriteString("A7A");
            break;}
        if(~(DIO_DigitalRead(KEYS_PINS,DOWN))) {
            LCD_WriteString("A7A2");
            
            break;}
        if(~(DIO_DigitalRead(KEYS_PINS,LEFT))) {
            
            break;}
        if(~(DIO_DigitalRead(KEYS_PINS,RIGHT))) {
            
            break;}
        
    }
    if ((~(DIO_DigitalRead(KEYS_PINS,RIGHT)))&&~(*L_flag))
    {
        *R_flag=1;
        *U_flag=0;
        *D_flag=0;
        while (1)
        {
            *current_column+=1;
            move_snake(*current_row,*current_column);
            if(~(DIO_DigitalRead(KEYS_PINS,UP))) {break;};
            if(~(DIO_DigitalRead(KEYS_PINS,DOWN))) {break;};

        }
        

    }
    if ((~(DIO_DigitalRead(KEYS_PINS,LEFT)))&&~(*R_flag))
    {
        *L_flag=1;
        *U_flag=0;
        *D_flag=0;
        while (1)
        {
            *current_column-=1;
            move_snake(*current_row,*current_column);
            if(~(DIO_DigitalRead(KEYS_PINS,UP))) {break;};
            if(~(DIO_DigitalRead(KEYS_PINS,DOWN))) {break;};

        }
        

    }
    if ((~(DIO_DigitalRead(KEYS_PINS,DOWN)))&&~(*U_flag))
    {
        *D_flag=1;
        *R_flag=0;
        *L_flag=0;
        while (1)
        {
            *current_row+=1;
            move_snake(*current_row,*current_column);
            if(~(DIO_DigitalRead(KEYS_PINS,LEFT))) {break;};
            if(~(DIO_DigitalRead(KEYS_PINS,RIGHT))) {break;};

        }
        

    }
    if ((~(DIO_DigitalRead(KEYS_PINS,UP)))&&~(*D_flag))
    {
        *U_flag=1;
        *R_flag=0;
        *L_flag=0;
        while (1)
        {
            *current_row-=1;
            move_snake(*current_row,*current_column);
            if(~(DIO_DigitalRead(KEYS_PINS,LEFT))) {break;};
            if(~(DIO_DigitalRead(KEYS_PINS,RIGHT))) {break;};

        }
        

    }            
    
}


void snake_pooling(Direction *dir, uint8_t *row, uint8_t *col) {

    if (!(DIO_DigitalRead(KEYS_PINS,RIGHT)) && *dir != DIR_LEFT) {
        *dir = DIR_RIGHT;
    } else if (!(DIO_DigitalRead(KEYS_PINS,DOWN)) && *dir != DIR_UP) {
        *dir = DIR_DOWN;
    } else if (!(DIO_DigitalRead(KEYS_PINS,LEFT)) && *dir != DIR_RIGHT) {
        *dir = DIR_LEFT;
    } else if (!(DIO_DigitalRead(KEYS_PINS,UP)) && *dir != DIR_DOWN) {
        *dir = DIR_UP;
    }


    *row += drow[*dir];
    *col += dcol[*dir];


    if (*col >= MAX_COL || *col < 0 || *row >= MAX_ROW || *row < 0) {

        LCD_Clear();
        LCD_WriteString("Game Over");
        _delay_ms(500);

        *row = 0;
        *col = 0;
        *dir = DIR_RIGHT;
        LCD_Clear();
        return;
    }

    move_snake(*row, *col);

    _delay_ms(2);
}

int main(void) {
    setup();  // your init: LCD_init_8bit(), KEYPAD_INIT(), etc.

    Direction dir = DIR_RIGHT;
    uint8_t row = 0, col = 0;

    LCD_WriteString("Snake Game");
    _delay_ms(500);
    LCD_Clear();

    while (1) {
        snake_pooling(&dir, &row, &col);
    }
    return 0;
}
