/*
 * software_timer.c
 *
 *  Created on: Sep 25, 2024
 *      Author: NAM NGUYEN
 */
#include "software_timer.h"

#define TIMER_CYCLE 1

uint16_t flag_timer2 = 0;
uint16_t timer2_counter = 0;
uint16_t timer2_MUL = 0;

uint16_t flag_timer3 = 0;
uint16_t timer3_counter = 0;
uint16_t timer3_MUL = 0;

uint16_t flag_timer4 = 0;
uint16_t timer4_counter = 0;
uint16_t timer4_MUL = 0;

uint16_t flag_timer5 = 0;
uint16_t timer5_counter = 0;
uint16_t timer5_MUL = 0;

void timer_init() {
    HAL_TIM_Base_Start_IT(&htim2);
}

// Set timer functions
void setTimer(uint16_t* timer_counter, uint16_t* timer_MUL, uint16_t duration, uint16_t* flag) {
    *timer_MUL = duration / TIMER_CYCLE;
    *flag = 0;
    *timer_counter = *timer_MUL;
}

void setTimer2(uint16_t duration) {
    setTimer(&timer2_counter, &timer2_MUL, duration, &flag_timer2);
}

void setTimer3(uint16_t duration) {
    setTimer(&timer3_counter, &timer3_MUL, duration, &flag_timer3);
}

void setTimer4(uint16_t duration) {
    setTimer(&timer4_counter, &timer4_MUL, duration, &flag_timer4);
}

void setTimer5(uint16_t duration) {
    setTimer(&timer5_counter, &timer5_MUL, duration, &flag_timer5);
}

// Timer run functions
void runTimer(uint16_t* timer_counter, uint16_t* flag, uint16_t* timer_MUL) {
    if (*timer_counter > 0) {
        (*timer_counter)--;
        if (*timer_counter <= 0) {
            *flag = 1;
            *timer_counter = *timer_MUL;
        }
    }
}

void timer2_run() {
    runTimer(&timer2_counter, &flag_timer2, &timer2_MUL);
}

void timer3_run() {
    runTimer(&timer3_counter, &flag_timer3, &timer3_MUL);
}

void timer4_run() {
    runTimer(&timer4_counter, &flag_timer4, &timer4_MUL);
}

void timer5_run() {
    runTimer(&timer5_counter, &flag_timer5, &timer5_MUL);
}
///////////////////////////////////////////////////////////
