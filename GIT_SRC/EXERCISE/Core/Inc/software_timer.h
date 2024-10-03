/*
 * software_timer.h
 *
 *  Created on: Sep 28, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include <stdint.h>
#include "main.h"

extern TIM_HandleTypeDef htim2;

extern uint16_t flag_timer1;
extern uint16_t flag_timer2;
extern uint16_t flag_timer3;
extern uint16_t flag_timer4;
extern uint16_t flag_timer5;

void timer_init();
void setTimer2(uint16_t duration);
void setTimer3(uint16_t duration);
void setTimer4(uint16_t duration);
void setTimer5(uint16_t duration);
void timer2_run();
void timer3_run();
void timer4_run();
void timer5_run();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#endif /* INC_SOFTWARE_TIMER_H_ */
