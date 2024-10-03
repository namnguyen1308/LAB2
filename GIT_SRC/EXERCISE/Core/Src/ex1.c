/*
 * ex1.c
 *
 *  Created on: Sep 25, 2024
 *      Author: NAM NGUYEN
 */
#include "ex1.h"

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
uint8_t active_display = 0;  // 0 for the first display, 1 for the second

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if(htim->Instance == TIM2) {
        // Handle the multiplexing for the 7-segment displays
        if (flag_timer2 == 1) {
            flag_timer2 = 0; // Reset the flag

            // Toggle between the two displays
            if (active_display == 0) {
                // Display "1" on the first 7-segment display
                HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET); // Enable Display 1
                HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);   // Disable Display 2
                display7SEG(1);  // Show "1" on the first display
                active_display = 1; // Switch to the next display
            } else {
                // Display "2" on the second 7-segment display
                HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);   // Disable Display 1
                HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET); // Enable Display 2
                display7SEG(2);  // Show "2" on the second display
                active_display = 0; // Switch back to the first display
            }
        }

        // Run the software timers
        timer2_run(); // To handle the 500ms delay for switching between displays
    }
}
