	.arch msp430g2553
	.text
	.extern st
	.extern tet
	.extern state
	.extern "buzzer.h"
	.extern buzzer_set_period
	; globl soundStates	
	.global advanceSounds
	.global newTune
advanceSounds:	
	mov st, r12
	add #1, state
	call #buzzer_set_period
newTune:
	mov tet, r12
	add #1, state
	call #buzzer_set_period
