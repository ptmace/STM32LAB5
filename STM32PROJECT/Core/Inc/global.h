/*
 * global.h
 *
 *  Created on: Dec 11, 2024
 *      Author: 2004p
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define MAX_BUFFER_SIZE 10

#define WAIT_START_CHAR	0	//WAIT_!
#define WAIT_END_CHAR	1	//WAIT_#
#define FIND_RST	2
#define SEND_ADC	3
#define FIND_OK		4

extern int status_cmd;
extern int status_uart;

extern uint32_t ADC_value;

extern char str[10];
extern uint8_t temp;

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t buffer_cmd[MAX_BUFFER_SIZE];
extern uint8_t index_buffer_cmd;
extern uint8_t buffer_cmd_flag;

#endif /* INC_GLOBAL_H_ */
