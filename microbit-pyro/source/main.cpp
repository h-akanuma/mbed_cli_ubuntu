#include "MicroBit.h"

MicroBit uBit;

MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ANALOG);
MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_DIGITAL);

MicroBitImage smiley("0,255,0,255, 0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
MicroBitImage closing_eyes("0,0,0,0, 0\n255,255,0,255,255\n0,0,0,0,0\n0,255,255,255,0\n0,0,0,0,0\n");

int pyro_value = 0;

int main()
{
  uBit.init();
  uBit.serial.send("Starting micro:bit pyroelectric.\r\n");
  uBit.display.scroll("HELLO!");

  while(true) {
    pyro_value = P0.getAnalogValue();
    uBit.serial.printf("%d\r\n", pyro_value);

    if (pyro_value >= 500) {
      P1.setDigitalValue(1);
      uBit.display.print(smiley);
    } else {
      P1.setDigitalValue(0);
      uBit.display.print(closing_eyes);
    }

    uBit.sleep(1000);
  }
}
