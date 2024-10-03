/*
 * ex2.c
 *
 *  Created on: Sep 27, 2024
 *      Author: NAM NGUYEN
 */
#include "ex2.h"
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
