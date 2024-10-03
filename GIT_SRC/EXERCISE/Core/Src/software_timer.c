/*
 * software_time.c
 *
 *  Created on: Sep 29, 2024
 *      Author: NAM NGUYEN
 */

#include "software_timer.h"
#include "main.h"
int TIMER_CYCLE = 10;

int timer0_counter = 0;
int timer0_flag = 0;
void setTimer0 ( int duration ) {
	timer0_counter = duration / TIMER_CYCLE ;
	timer0_flag = 0;
}

int timer_DOT_counter = 0;
int timer_DOT_flag = 0;
void setTimerDOT ( int duration ) {
	timer_DOT_counter = duration / TIMER_CYCLE ;
	timer_DOT_flag = 0;
}

int timer_clock_counter = 0;
int timer_clock_flag = 0;
void setTimerClock ( int duration ) {
	timer_clock_counter = duration / TIMER_CYCLE ;
	timer_clock_flag = 0;
}

void timer_run () {
	if( timer0_counter > 0) {
		timer0_counter --;
		if( timer0_counter == 0) timer0_flag = 1;
	}

	if( timer_DOT_counter > 0) {
		timer_DOT_counter --;
		if( timer_DOT_counter == 0) timer_DOT_flag = 1;
	}

	if( timer_clock_counter > 0) {
		timer_clock_counter --;
		if( timer_clock_counter == 0) timer_clock_flag = 1;
	}
}
