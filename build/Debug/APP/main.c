#include "../MCAL/DIO/DIO_Header.h"
#include "../HAL/KEYPAD/KEYPAD_Header.h"
#include "../HAL/LCD/LCD_Header.h"
#include <util/delay.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_EXPR_LEN 32
#define MAX_TOKENS   32

// --- Expression buffer ---
static char expr[MAX_EXPR_LEN+1];
static uint8_t expr_idx = 0;

// --- Stacks for shunting‐yard eval ---
static float val_stack[MAX_TOKENS];
static int   val_top;
static char  op_stack[MAX_TOKENS];
static int   op_top;

// --- Forward declarations ---
static int   prec(char op);
static void  apply_op(void);
static float parse_number(const char *e, int *p);
static float evaluate_expression(const char *e);
static void  ftoa2(float x, char *buf, int bufsize);

// --- Operator precedence ---
static int prec(char op) {
    if (op=='+'||op=='-') return 1;
    if (op=='*'||op=='/') return 2;
    return 0;
}

// --- Apply top operator to top two values ---
static void apply_op(void) {
    if (val_top<2||op_top<1) return;
    float b=val_stack[--val_top];
    float a=val_stack[--val_top];
    char  o=op_stack[--op_top];
    float r=0.0f;
    switch(o){
    case '+': r=a+b; break;
    case '-': r=a-b; break;
    case '*': r=a*b; break;
    case '/': r=(b!=0.0f?a/b:0.0f); break;
    }
    val_stack[val_top++]=r;
}

// --- Parse number (int + optional .frac) from e[*p] ---
static float parse_number(const char *e,int *p){
    float v=0.0f;
    while(e[*p]>='0'&&e[*p]<='9'){
        v=v*10.0f+(e[*p]-'0');
        (*p)++;
    }
    if(e[*p]=='.'){
        (*p)++;
        float f=0.0f,d=1.0f;
        while(e[*p]>='0'&&e[*p]<='9'){
            f=f*10.0f+(e[*p]-'0');
            d*=10.0f;
            (*p)++;
        }
        v+=f/d;
    }
    return v;
}

// --- Evaluate with proper precedence ---
static float evaluate_expression(const char *e){
    val_top=op_top=0;
    int p=0;
    while(e[p]){
        if(e[p]==' '){ p++; continue; }
        if((e[p]>='0'&&e[p]<='9')||e[p]=='.'){
            float num=parse_number(e,&p);
            val_stack[val_top++]=num;
            continue;
        }
        char o=e[p++];
        while(op_top>0 && prec(op_stack[op_top-1])>=prec(o)){
            apply_op();
        }
        op_stack[op_top++]=o;
    }
    while(op_top>0) apply_op();
    return (val_top>0?val_stack[val_top-1]:0.0f);
}

// --- Fast float to string with 2 decimals ---
static void ftoa2(float x,char *buf,int bufsize){
    int i=0;
    if(x<0){ if(i<bufsize-1)buf[i++]='-'; x=-x; }
    int whole=(int)x; float frac=x-whole;
    char tmp[12]; int ti=0;
    if(whole==0) tmp[ti++]='0';
    else{
        while(whole>0 && ti<11){ tmp[ti++]='0'+(whole%10); whole/=10; }
    }
    while(ti>0 && i<bufsize-1) buf[i++]=tmp[--ti];
    if(i<bufsize-1) buf[i++]='.';
    int f2=(int)(frac*100+0.5f);
    if(i<bufsize-1) buf[i++]='0'+(f2/10);
    if(i<bufsize-1) buf[i++]='0'+(f2%10);
    buf[i]='\0';
}

int main(void){
    LCD_init_8bit();
    KEYPAD_INIT();
    LCD_Clear();
    LCD_WriteString("Calculator:");

    while(1){
        uint8_t key = KEYPAD_GetPressedKey();
        if(key==0xFF) continue;

        // Clear
        if(key=='c'){
            expr_idx=0; expr[0]='\0';
            LCD_Clear(); LCD_WriteString("Calculator:");
        }
        // Calculate
        else if(key=='='){
            expr[expr_idx]='\0';
            float ans=evaluate_expression(expr);
            char buf[16];
            ftoa2(ans,buf,sizeof(buf));
            LCD_Clear();
            LCD_WriteString(expr);
            LCD_SetCursor(1,0);
            LCD_WriteString("=");
            LCD_WriteString(buf);
            // chain: copy result back into expr
            expr_idx=strlen(buf);
            if(expr_idx>MAX_EXPR_LEN) expr_idx=MAX_EXPR_LEN;
            memcpy(expr,buf,expr_idx);
            expr[expr_idx]='\0';
        }
        // Append digit/operator
        else {
            if(expr_idx<MAX_EXPR_LEN){
                expr[expr_idx++]=key;
                expr[expr_idx]='\0';
                LCD_Clear();
                LCD_WriteString(expr);
            }
        }
        _delay_ms(20); // simple debounce
    }
    return 0;
}
