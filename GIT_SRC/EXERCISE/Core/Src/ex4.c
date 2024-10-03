/*
 * ex4.c
 *
 *  Created on: Sep 28, 2024
 *      Author: NAM NGUYEN
 */

#include "ex4.h"
void display7SEG(int num) {
    // Dữ liệu để điều khiển các LED (LED1 đến LED7) cho số từ 0 đến 9
    uint8_t segment_data[10] = {
        0xC0,  // 0: 1100 0000 (a,b,c,d,e,f - tắt các đoạn LED tương ứng)
        0xF9,  // 1: 1111 1001 (b,c)
        0xA4,  // 2: 1010 0100 (a,b,d,e,g)
        0xB0,  // 3: 1011 0000 (a,b,c,d,g)
        0x99,  // 4: 1001 1001 (b,c,f,g)
        0x92,  // 5: 1001 0010 (a,c,d,f,g)
        0x82,  // 6: 1000 0010 (a,c,d,e,f,g)
        0xF8,  // 7: 1111 1000 (a,b,c)
        0x80,  // 8: 1000 0000 (a,b,c,d,e,f,g)
        0x90   // 9: 1001 0000 (a,b,c,d,f,g)
    };

    // Đặt giá trị các chân PB0-PB6 (LED1 đến LED7) tương ứng với số num
    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (segment_data[num] & 0x01) ? SET : RESET);  // LED1
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (segment_data[num] & 0x02) ? SET : RESET);  // LED2
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (segment_data[num] & 0x04) ? SET : RESET);  // LED3
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (segment_data[num] & 0x08) ? SET : RESET);  // LED4
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (segment_data[num] & 0x10) ? SET : RESET);  // LED5
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (segment_data[num] & 0x20) ? SET : RESET);  // LED6
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (segment_data[num] & 0x40) ? SET : RESET);  // LED7
}
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

int seven_segment_counter = 100 / MAX_LED;
int seven_segment_EN_state = 0;
int LED_counter = 100;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	seven_segment_counter--;
	if (seven_segment_counter <= 0){
		seven_segment_counter = 100 / MAX_LED;

		if (index_led >= MAX_LED) index_led = 0;
		update7SEG(index_led++);
	}

	LED_counter--;
	if (LED_counter <= 0){
		LED_counter = 100;
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	}
}

void update7SEG(int index){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[0]);

		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[1]);

		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[2]);

		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_buffer[3]);

		break;
	default:
		break;
	}
}