/*
 * software_timer.h
 *
 *  Created on: Sep 29, 2024
 *      Author: NAM NGUYEN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include <stdint.h>
#include "main.h"

extern TIM_HandleTypeDef htim2;
void setTimerDOT (int duration);
void setTimer0(int duration);
void setTimerClock (int duration);
void timer_run();

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#endif /* INC_SOFTWARE_TIMER_H_ */
