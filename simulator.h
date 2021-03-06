#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "lex.yy.c"
#include "timer.h"
#include "boot.h"
#include "utility.h"
#include "debug.h"
/*
 * This function identifies one instruction and performs neccesary action
 */
void executeOneInstruction(int);

/*
 *	This function does the following:
 *	1. Loads OS Startup Code.
 *	2. Copies the instruction to be parsed as per the address specified by the IP register.
 *	3. Checks whether interrupt is disabled. If not th clock ticks.
 *	4. Begins the lexical analysis by getting the first token and passing it as arguement to executeOneInstruction.
 *	5. If step flag is enabled enters debug mode
 *	6. Finally checks if time slice allocated is over or not. If yes and mode is user mode ,and if timer interrupt is enabled then
 *		INT 0 code is run.
 */
void run(int is_timer_enabled);
#endif
