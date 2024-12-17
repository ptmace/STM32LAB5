/*
 * fsm_uart.c
 *
 *  Created on: Dec 11, 2024
 *      Author: 2004p
 */

#ifndef SRC_FSM_UART_C_
#define SRC_FSM_UART_C_

#include "command_parser_fsm.h"

void command_parser_fsm(){
	switch(status_cmd){
		case WAIT_START_CHAR:
			if(temp == '!'){
				buffer_cmd_flag = 0;
				status_cmd = WAIT_END_CHAR;
			}
			break;
		case WAIT_END_CHAR:
			if(temp == '#'){
				status_cmd = WAIT_START_CHAR;
				buffer_cmd_flag = 1;
				buffer_cmd[index_buffer_cmd] = '\0';
			}
			else{
				if(temp == '!'){
					buffer_cmd_flag = 0;
				}
				else{
					buffer_cmd[index_buffer_cmd++] = temp;

					if(index_buffer_cmd == MAX_BUFFER_SIZE)
						index_buffer_cmd = 0;
				}
			}
			break;
		default: break;
	}
}
#endif /* SRC_FSM_UART_C_ */
