# AVR-ATmega32
is the MCU that precedes the famous **ATmega32p** --the one used in **ARDUINO** development boards-- 

this repository contains:
- the **ATmega32** peripherals Drivers . It is structured into four main layers (APP,MCAL,HAL,LIB):
    - **MCAL (Microcontroller Abstraction Layer)**
    - **HAL (Hardware Abstraction Layer)**
    - **LIB (Utility Layer)**
    - **APP (Main Program Layer)**
- Cmake file to build  the app

## Structure

├── MCAL/
│ ├── DIO/
│ ├── USART/
│ ├── I2C/
│ ├── EXTI/
│ └── ADC/
│
├── HAL/
│ ├── LCD/
│ ├── KEYPAD/
│ └── SSEG/
│
├── LIB/
│ ├── STD_TYPES.h
│ └── BIT_MATH.h
│
├── APPLICATION/
  └── main.c





##  MCAL Drivers

### 1. DIO (Digital I/O) --GPIO like--
- Configure direction (input/output) of individual pins or full ports.
- Write and read digital values.
- Toggle pins.
- Bit-level access using port register abstraction.

### 2. ADC (Analog-to-Digital Converter)
- Configurable voltage reference: `AVCC`, `AREF`, or `INTERNAL`
- Selectable adjustment: `LEFT_ADJUST` or `RIGHT_ADJUST`
- Supports auto-trigger mode and free running mode
- Configurable prescaler
- Blocking analog read with polling (with optional auto trigger support)

### 3. EXTI (External Interrupts)
- INT0, INT1, INT2 setup
- Modes: low level, rising edge, falling edge, any change
- Global interrupt enable/disable
- Callback registration
- Vector table handling (ISR abstraction)

### 4. USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
- Baud rate selection (common rates: 9600, 19200, 38400, 57600, 115200).
- Send and receive characters/strings.
- USART configuration through initialization function.

### 5. I2C (TWI – Two-Wire Interface)
- Master Initialization & Communication
- Slave Initialization & Communication
- Start, Restart, Stop Conditions
- Sending/Receiving Data
- Acknowledgment (ACK/NACK) error checking




## HAL Drivers

### 1. LCD (16x2 Character LCD)
- Initialization in 8-bit mode with 2 lines and 5x10 font.
- Send strings or characters to the LCD.
- Clear display.
- Create and display custom characters (stored in CGRAM).
- Set cursor position.

### 2. KEYPAD (4x4 Matrix Keypad)
- Supports 4 rows × 4 columns matrix keypad.
- Returns ASCII characters mapped to physical keys.
- Debounces input to avoid multiple detections.

### 3. Seven Segment Display (SSEG)
- Supports Common Cathode or Common Anode configurations (based on wiring).

### 4. Servo Motor
  - Upcoming




## LIB 

### 1. STD_TYPES.h
- Defines standard types: u8, u16, s8, f32, etc.

### 2. BIT_MATH.h
- Common macros: SET_BIT, CLEAR_BIT, TOGGLE_BIT, GET_BIT.



## Sample Debug Notes
Don't forget to include sei(); to enable global interrupts after enabling a peripheral interrupt.



### Build

```bash
Cmake        # Compiles the source code
make flash  # Uploads to ATmega32 using avrdude --yet to come--



