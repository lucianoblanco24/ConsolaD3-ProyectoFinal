#include <samples.h>
#include <samples.h>
#include "LPC17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_adc.h"
#include "lpc17xx_dac.h"
#include "lpc17xx_gpdma.h"

#define PORT_0 (uint8_t)0
#define PIN_1 (uint32_t)(1<<1)

void cfgDAC(void);
void cfgTMR(void);
void cfgGPIO(void);

volatile uint32_t idx = 0;

int main(void) {
	cfgGPIO();
	cfgDAC();
	cfgTMR();

	while(1){}

	return 0;
}

void cfgDAC(void){
	DAC_Init();

	return;
}
void cfgGPIO(void){
	PINSEL_CFG_Type cfgADC0_MAT0_CH1;//P1.29
	PINSEL_CFG_Type cfgPinDac;

	cfgPinDac.portNum = PINSEL_PORT_0;
	cfgPinDac.pinNum = PINSEL_PIN_26;
	cfgPinDac.funcNum = PINSEL_FUNC_2;
	cfgPinDac.pinMode = PINSEL_TRISTATE;
	cfgPinDac.openDrain = PINSEL_OD_NORMAL;

	PINSEL_ConfigPin(&cfgPinDac);

	cfgADC0_MAT0_CH1.portNum = PINSEL_PORT_1;
	cfgADC0_MAT0_CH1.pinNum = PINSEL_PIN_29;
	cfgADC0_MAT0_CH1.funcNum = PINSEL_FUNC_3;
	cfgADC0_MAT0_CH1.pinMode = PINSEL_TRISTATE;
	cfgADC0_MAT0_CH1.openDrain = PINSEL_OD_NORMAL;

	PINSEL_ConfigPin(&cfgADC0_MAT0_CH1);


	return;
}

void cfgTMR(void){

	TIM_TIMERCFG_Type cfgTimerMode;
	TIM_MATCHCFG_Type cfgMAT0_CH1;

	cfgTimerMode.prescaleOption = TIM_USVAL;
	cfgTimerMode.prescaleValue = 1;

	cfgMAT0_CH1.matchChannel = 1;
	cfgMAT0_CH1.matchValue = 62; // 625us/1us - 1
	cfgMAT0_CH1.intOnMatch = ENABLE;
	cfgMAT0_CH1.stopOnMatch = DISABLE;
	cfgMAT0_CH1.resetOnMatch = ENABLE;
	cfgMAT0_CH1.extMatchOutputType = TIM_NOTHING;

	TIM_Init(LPC_TIM0,TIM_TIMER_MODE,&cfgTimerMode);
	TIM_ConfigMatch(LPC_TIM0,&cfgMAT0_CH1);
	TIM_Cmd(LPC_TIM0,ENABLE);
	NVIC_EnableIRQ(TIMER0_IRQn);
	NVIC_SetPriority(TIMER0_IRQn,0);

	return;
}

void TIMER0_IRQHandler(void){

	uint16_t val10bit = sampleS1[idx] << 2;   // convertir 8→10 bits
	DAC_UpdateValue(val10bit);
	idx++;
	if (++idx >= SAMPLE_S1_LEN) idx = 0;

	TIM_ClearIntPending(LPC_TIM0,TIM_MR1_INT);
	return;
}




