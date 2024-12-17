/*
 * software_timer.c
 *
 *  Created on: Dec 18, 2024
 *      Author: 2004p
 */

#include "software_timer.h"

int timer_flag[MAXTM];
int timer_counter[MAXTM];

void setTimer(int index, int counter){
	timer_flag[index] = 0;
	timer_counter[index] = counter;
}
void timerRun(){
	for(int i = 0; i < MAXTM; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;

			if(timer_counter <= 0){
				timer_flag[i] = 1;
			}
		}
		else{
			timer_flag[i] = 1;
		}
	}
}

