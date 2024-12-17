/*
 * global.c
 *
 *  Created on: Dec 11, 2024
 *      Author: 2004p
 */
#include "global.h"

int status_uart = FIND_RST;
int status_cmd = WAIT_START_CHAR;

uint32_t ADC_value;

char str[10];
uint8_t temp = 0;

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t buffer_cmd[MAX_BUFFER_SIZE];
uint8_t index_buffer_cmd = 0;
uint8_t buffer_cmd_flag = 0;
char _char;
