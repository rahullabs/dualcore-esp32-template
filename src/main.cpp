/*
*	Aurthor: Rahul Singh Maharjan
*	https://rahullabs.github.io/
*/
#include <Arduino.h>

TaskHandle_t task_on_core_0;
TaskHandle_t task_on_core_1;


void core_0_task(void *pvParameters);
void core_1_task(void *pvParameters);


void setup() {
	Serial.begin(115200);
	/*Pinning the Task on core 0 and core 1*/
	xTaskCreatePinnedToCore(
		core_0_task,	// task on core 0 finction name
		"core_0",		// Name of the task
		10000,			// Size of stack
		NULL,			// Parameter of the task
		1,				// priority
		&task_on_core_0,// Task tracker
		0);				// Core number 0
	delay(100);
	xTaskCreatePinnedToCore(
		core_1_task,	// task on core 1 finction name
		"core_1",		// Name of the task
		10000,			// Size of stack
		NULL,			// Parameter of the task
		1,				// priority
		&task_on_core_1,// Task tracker
		1);				// Core number 1

	delay(100);
}

/* START OF CORE 0 TASK */
void core_0_task(void *pvParameters){
	for(;;){

		delay(10); // Always use delay(xxx) to prevent ESP32 core from rebooting because of core dump
	}
}

/* START OF CORE 1 TASK */
void core_1_task(void *pvParameters){
	for(;;){

		delay(10); // Always use delay(xxx) to prevent ESP32 core from rebooting because of core dump
	}
}

/*DO NOT USE LOOP WHILE USING MULTICORE PROCESSING*/
void loop() {
}