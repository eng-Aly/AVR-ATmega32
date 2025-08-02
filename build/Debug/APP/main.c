#include <util/delay.h>
#include "../HAL/LCD/LCD_Header.h"
#include "../MCAL/DIO/DIO_Header.h"

#define SNAKE_CHAR       0
#define MAX_SNAKE_LENGTH 25
#define SNAKE_LENGTH     5
#define DELAY_MS         300

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

u8 current_snake_length = SNAKE_LENGTH;
Position snake_body[MAX_SNAKE_LENGTH];
u8 head_index = 0;


Position food;
u16 pseudo_random_seed = 7;
int food_exists=0; 




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



u8 pseudo_random(u8 max) {
    pseudo_random_seed = (pseudo_random_seed * 37 + 23) % 251;
    return pseudo_random_seed % max;
}

void spawn_food() {
    u8 valid = 0;
    while (!valid) {
        food.row = pseudo_random(MAX_ROW);
        food.col = pseudo_random(MAX_COL);

        valid = 1;
        food_exists=1;
        if (snake_body[head_index].row == food.row && snake_body[head_index].col == food.col) {
            valid = 0;
            food_exists=0;
            break;
        }
    }
    

    LCD_SetCursor(food.row, food.col);
    LCD_WriteChar('*'); // Food character
}

void move_snake(u8 new_row, u8 new_col) {
    // 1) Spawn food if needed
    if (!food_exists) {
        spawn_food();
    }

    // 2) Check if we're eating
    uint8_t ate = (new_row == food.row && new_col == food.col);
    if (ate) {
        food_exists = 0;
        if (current_snake_length < MAX_SNAKE_LENGTH) {
            current_snake_length++;
        }
    }

    // 3) If not eating, clear the tail cell on screen
    if (!ate) {
        Position tail = snake_body[current_snake_length - 1];
        clear_dot(tail.row, tail.col);
    }

    // 4) Shift body positions back by one
    //    snake_body[i] = snake_body[i-1], for i from length-1 down to 1
    for (int i = current_snake_length - 1; i > 0; i--) {
        snake_body[i] = snake_body[i - 1];
    }

    // 5) Insert new head at index 0
    snake_body[0].row = new_row;
    snake_body[0].col = new_col;
    draw_dot(new_row, new_col);

    _delay_ms(DELAY_MS);
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
        food_exists=0;
        current_snake_length=SNAKE_LENGTH;
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
