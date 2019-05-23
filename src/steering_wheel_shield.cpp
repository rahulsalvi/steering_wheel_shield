#include "steering_wheel_shield.h"
#include "steering_wheel_definitions.h"

namespace steering_wheel_shield {

    inline void set_csx() { GPIOC_PSOR = CSX_MASK; }
    inline void clr_csx() { GPIOC_PCOR = CSX_MASK; }

    inline void set_dcx() { GPIOC_PSOR = DCX_MASK; }
    inline void clr_dcx() { GPIOC_PCOR = DCX_MASK; }

    inline void set_wrx() { GPIOC_PSOR = WRX_MASK; }
    inline void clr_wrx() { GPIOC_PCOR = WRX_MASK; }

    inline void set_rdx() { GPIOC_PSOR = RDX_MASK; }
    inline void clr_rdx() { GPIOC_PCOR = RDX_MASK; }

    inline void set_rst() { GPIOE_PSOR = RST_MASK; }
    inline void clr_rst() { GPIOE_PCOR = RST_MASK; }

    inline void clr_data() {
        GPIOB_PCOR = PORTB_DATA_MASK;
        GPIOC_PCOR = PORTC_DATA_MASK;
    };

    void write_command(uint8_t* data, uint8_t n) {
        clr_csx();

        clr_dcx();
        GPIOC_PSOR = data[0] << 4;
        clr_wrx();
        __asm("nop");
        set_wrx();
        __asm("nop");
        GPIOC_PCOR = data[0] << 4;
        set_dcx();

        for (int i = 1; i < n; i++) {
            GPIOC_PSOR = data[i] << 4;
            clr_wrx();
            __asm("nop");
            set_wrx();
            __asm("nop");
            GPIOC_PCOR = data[i] << 4;
        }

        set_csx();
    }

    void reset() {
        set_csx();
        set_dcx();
        set_wrx();
        set_rdx();
        set_rst();
        clr_data();

        delay(100);
        clr_rst();
        delay(100);
        set_rst();
        delay(100);

        uint8_t buf[16];

        buf[0] = HX8357_SET_POWER;
        buf[1] = 0x44;
        buf[2] = 0x41;
        buf[3] = 0x06;
        write_command(buf, 4);

        buf[0] = HX8357_SET_VCOM;
        buf[1] = 0x40;
        buf[2] = 0x10;
        write_command(buf, 3);

        buf[0] = HX8357_SET_POWER_NORMAL;
        buf[1] = 0x05;
        buf[2] = 0x12;
        write_command(buf, 3);

        buf[0] = HX8357_SET_PANEL_DRIVING;
        buf[1] = 0x14;
        buf[2] = 0x3B;
        buf[3] = 0x00;
        buf[4] = 0x02;
        buf[5] = 0x11;
        write_command(buf, 6);

        buf[0] = HX8357_SET_DISPLAY_FRAME;
        buf[1] = 0x0C;
        write_command(buf, 2);

        buf[0] = HX8357_SET_PANEL_RELATED;
        buf[1] = 0x01;
        write_command(buf, 2);

        buf[0]  = HX8357_SET_GAMMA;
        buf[1]  = 0x00;
        buf[2]  = 0x15;
        buf[3]  = 0x00;
        buf[4]  = 0x22;
        buf[5]  = 0x00;
        buf[6]  = 0x08;
        buf[7]  = 0x77;
        buf[8]  = 0x26;
        buf[9]  = 0x77;
        buf[10] = 0x22;
        buf[11] = 0x04;
        buf[12] = 0x00;
        write_command(buf, 13);

        buf[0] = HX8357_SET_ADDRESS_MODE;
        buf[1] = 0xC0;
        write_command(buf, 2);

        buf[0] = HX8357_SET_PIXEL_FORMAT;
        buf[1] = 0x06;
        write_command(buf, 2);

        buf[0] = HX8357_SET_COLUMN_ADDRESS;
        buf[1] = 0x00;
        buf[2] = 0x00;
        buf[3] = 0x01;
        buf[4] = 0x3f;
        write_command(buf, 5);

        buf[0] = HX8357_SET_PAGE_ADDRESS;
        buf[1] = 0x00;
        buf[2] = 0x00;
        buf[3] = 0x01;
        buf[4] = 0xdf;
        write_command(buf, 5);

        buf[0] = HX8357_SET_DISPLAY_MODE;
        buf[1] = 0x00;
        write_command(buf, 2);

        buf[0] = HX8357_EXIT_SLEEP_MODE;
        write_command(buf, 1);

        delay(120);
        buf[0] = HX8357_SET_DISPLAY_ON;
        write_command(buf, 1);

        delay(10);
    }

    void begin() {
        // TODO pin initialization
        reset();
    }

} // namespace steering_wheel_shield
