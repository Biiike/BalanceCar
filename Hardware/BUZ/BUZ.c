#include "BUZ.h"
#include "BUZ/BUZ.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"

void BUZ_ON()
{
    DL_GPIO_setPins(BUZ_PORT, BUZ_Buz_PIN);
}

void BUZ_OFF()
{
    DL_GPIO_clearPins(BUZ_PORT, BUZ_Buz_PIN);
}