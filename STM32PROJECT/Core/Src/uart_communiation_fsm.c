/*
 * fsm_adc.c
 *
 *  Created on: Dec 11, 2024
 *      Author: 2004p
 */

#include "uart_communication_fsm.h"

void uart_communiation_fsm(){
	switch(status_uart){
		case FIND_RST:
			if(buffer_cmd_flag){
				buffer_cmd_flag = 0;

				if(buffer_cmd[0] == 'R' && buffer_cmd[1] == 'S' && buffer_cmd[2] == 'T'){
					status_uart = SEND_ADC;
					HAL_ADC_Start(&hadc1);
					ADC_value = HAL_ADC_GetValue(&hadc1);
					HAL_ADC_Stop(&hadc1);
					HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
					setTimer(0, 3000);
				}
			}
			break;
		case SEND_ADC:
			HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%lu#\r\n", ADC_value), 1000);
			status_uart = FIND_OK;
			break;
		case FIND_OK:
			if(buffer_cmd_flag){
				buffer_cmd_flag = 0;

				if(buffer_cmd[0] == 'O' && buffer_cmd[1] == 'K'){
					HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n"), 1000);
					status_uart = FIND_RST;
					timer_flag[0] = 0;
				}
			}
			if(timer_flag[0]){
				status_uart = SEND_ADC;
				setTimer(0, 3000);
			}
		default: break;
	}
}
