	.arch msp430g2553
	.p2align 1,0
	.text

	.global state
	.extern switch_state
COLOR_RED:	.word 0x001f
COLOR_GREEN:	.word 0x07e0
COLOR_YELLOW:	.word 0x07ff
COLOR_ORANGE:	.word 0x053f
	
	
table:
	.word default
	.word case_1
	.word case_2
	.word case_3
	.word case_4
state:
	mov &switch_state, r12
	add r12, r12
	mov table(r12), pc
default:
	jmp end_table
case_1:
	mov #30, r12
	mov #10, r13
	mov #2, r14
	mov &COLOR_RED, r15
	call #draw_circle
	jmp end_table
case_2:
	mov #50, r12
	mov #10, r13
	mov #2, r14
	mov &COLOR_GREEN, r15
	call #draw_circle
	jmp end_table
case_3:
	mov #70, r12
	mov #10, r13
	mov #2, r14
	mov &COLOR_YELLOW, r15
	call #draw_circle
	jmp end_table
case_4:
	mov #90, r12
	mov #10, r13
	mov #2, r14
	mov &COLOR_ORANGE, r15
	call #draw_circle
	jmp end_table
end_table:
	pop r0
