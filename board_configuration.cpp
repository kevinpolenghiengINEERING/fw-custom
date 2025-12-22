#include "pch.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::E3;
}

Gpio getRunningLedPin() {
	return Gpio::E0;
}

Gpio getWarningLedPin() {
	return Gpio::E2;
}

// board-specific configuration setup
static void customBoardDefaultConfiguration() {
     engineConfiguration->injectionPins[0] = Gpio::D12;
    //engineConfiguration->ignitionPins[0] = Gpio::E15;

   engineConfiguration->triggerInputPins[0] = Gpio::A0;
//	engineConfiguration->triggerInputPins[1] = Gpio::Unassigned;

	engineConfiguration->map.sensor.hwChannel = EFI_ADC_2;

	engineConfiguration->clt.adcChannel = EFI_ADC_5;

	engineConfiguration->iat.adcChannel = EFI_ADC_7;


    	 //5.6k high side/10k low side = 1.56 ratio divider
    	engineConfiguration->analogInputDividerCoefficient = 1.56f;

    	// 6.34k high side/ 1k low side
//    	engineConfiguration->vbattDividerCoeff = (6.34 + 1) / 1;

	engineConfiguration->adcVcc = 3.3f;

	//engineConfiguration->clt.config.bias_resistor = 2490;
	//engineConfiguration->iat.config.bias_resistor = 2490;


	// Battery sense on PA4
	engineConfiguration->vbattAdcChannel = EFI_ADC_4;
}

void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
