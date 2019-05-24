#ifndef STEERING_WHEEL_DEFINITIONS_H
#define STEERING_WHEEL_DEFINITIONS_H

#define CSX_MASK (1 << 0)
#define DCX_MASK (1 << 1)
#define WRX_MASK (1 << 2)
#define RDX_MASK (1 << 3)
#define RST_MASK (1 << 26)

#define PORTC_DATA_MASK 0x00000FF0
#define PORTB_DATA_MASK 0x000F0C0F

// clang-format off
#define HX8357_NOP                      0x00
#define HX8357_SOFTWARE_RESET           0x01
#define HX8357_GET_RED_CHANNEL          0x06
#define HX8357_GET_GREEN_CHANNEL        0x07
#define HX8357_GET_BLUE_CHANNEL         0x08
#define HX8357_GET_POWER_MODE           0x0A
#define HX8357_GET_MADCTL               0x0B
#define HX8357_GET_PIXEL_FORMAT         0x0C
#define HX8357_GET_DISPLAY_MODE         0x0D
#define HX8357_GET_SIGNAL_MODE          0x0E
#define HX8357_GET_DIAGNOSTIC_RESULT    0x0F
#define HX8357_ENTER_SLEEP_MODE         0x10
#define HX8357_EXIT_SLEEP_MODE          0x11
#define HX8357_ENTER_PARTIAL_MODE       0x12
#define HX8357_ENTER_NORMAL_MODE        0x13
#define HX8357_EXIT_INVERSION_MODE      0x20
#define HX8357_ENTER_INVERSION_MODE     0x21
#define HX8357_SET_DISPLAY_OFF          0x28
#define HX8357_SET_DISPLAY_ON           0x29
#define HX8357_SET_COLUMN_ADDRESS       0x2A
#define HX8357_SET_PAGE_ADDRESS         0x2B
#define HX8357_WRITE_MEMORY_START       0x2C
#define HX8357_READ_MEMORY_START        0x2E
#define HX8357_SET_PARTIAL_AREA         0x30
#define HX8357_SET_SCROLL_AREA          0x33
#define HX8357_SET_TEAR_OFF             0x34
#define HX8357_SET_TEAR_ON              0x35
#define HX8357_SET_ADDRESS_MODE         0x36
#define HX8357_SET_SCROLL_START         0x37
#define HX8357_EXIT_IDLE_MODE           0x38
#define HX8357_ENTER_IDLE_MODE          0x39
#define HX8357_SET_PIXEL_FORMAT         0x3A
#define HX8357_WRITE_MEMORY_CONTINUE    0x3C
#define HX8357_READ_MEMORY_CONTINUE     0x3E
#define HX8357_SET_TEAR_SCAN_LINES      0x44
#define HX8357_GET_SCAN_LINES           0x45
#define HX8357_READ_DDB_START           0xA1
#define HX8357_WRITE_DISPLAY_BRIGHTNESS 0x51
#define HX8357_READ_DISPLAY_BRIGHTNESS  0x52
#define HX8357_WRITE_CTRL_DISPLAY       0x53
#define HX8357_READ_CTRL_DISPLAY        0x54
#define HX8357_WRITE_CABC               0x55
#define HX8357_READ_CABC                0x56
#define HX8357_WRITE_CABC_MIN           0x5E
#define HX8357_READ_CABC_MIN            0x5F
#define HX8357_READ_CABC_DIAGNOSTIC     0x68
#define HX8357_SET_EXTENDED_COMMAND     0xB0
#define HX8357_SET_DEEP_STANDBY_MODE    0xB1
#define HX8357_SET_GRAM_ACCESS          0xB3
#define HX8357_SET_DISPLAY_MODE         0xB4
#define HX8357_GET_DEVICE_ID            0xBF
#define HX8357_SET_PANEL_DRIVING        0xC0
#define HX8357_SET_TIMING_NORMAL        0xC1
#define HX8357_SET_TIMING_PARTIAL       0xC2
#define HX8357_SET_TIMING_IDLE          0xC3
#define HX8357_SET_DISPLAY_FRAME        0xC5
#define HX8357_SET_RGB_INTERFACE        0xC6
#define HX8357_SET_GAMMA                0xC8
#define HX8357_SET_POWER                0xD0
#define HX8357_SET_VCOM                 0xD1
#define HX8357_SET_POWER_NORMAL         0xD2
#define HX8357_SET_POWER_PARTIAL        0xD3
#define HX8357_SET_POWER_IDLE           0xD4
#define HX8357_SET_ID                   0xE0
#define HX8357_SET_OTP_SETTING          0xE2
#define HX8357_SET_OTP_KEY              0xE3
#define HX8357_SET_CABC                 0xE4
#define HX8357_SET_PANEL_RELATED        0xE9
#define HX8357_SET_EQ_FUNCTION          0xEE
// clang-format on

// clang-format off
#define NOP __asm("NOP\n");

#define REP0(x)
#define REP1(x)  x
#define REP2(x)  REP1(x) x
#define REP3(x)  REP2(x) x
#define REP4(x)  REP3(x) x
#define REP5(x)  REP4(x) x
#define REP6(x)  REP5(x) x
#define REP7(x)  REP6(x) x
#define REP8(x)  REP7(x) x
#define REP9(x)  REP8(x) x
#define REP10(x) REP9(x) x

#define REP(hundreds,tens,ones,x) \
    REP##hundreds(REP10(REP10(x))) \
    REP##tens(REP10(x)) \
    REP##ones(x)

#define NOPN(hundreds,tens,ones) REP(hundreds,tens,ones,NOP)
// clang-format on

#define PCR_MUX(x) (x << 8)
#define PCR_PE 0x02
#define PCR_PS 0x01

#endif // STEERING_WHEEL_DEFINITIONS_H
