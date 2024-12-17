/*
 * software_timer.h
 *
 *  Created on: Dec 18, 2024
 *      Author: 2004p
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define MAXTM 10

extern int timer_flag[MAXTM];
extern int timer_counter[MAXTM];

void setTimer(int index, int counter);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
