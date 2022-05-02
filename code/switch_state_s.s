	.arch msp430g2553
	.p2align 1,0
	.text

	.global state
	.extern switch_state
COLOR_RED:	.word 0xf800
COLOR_GREEN:	.word 0x07e0

table:
	.word default
	.word case_1
	.word case_2
	.word case_3
	.word case_4
state:
	mov.b &switch_state, r12
	add r12, r12
	mov table(r12), pc
default:
	jmp end_table
case_1:
	mov #80, r12
	mov #15, r13
	mov #2, r14
	mov &COLOR_RED, r15
	call draw_circle
	jmp end_table
case_2:
	mov #20, r12
	mov #20, r13
	mov #4, r14
	mov &COLOR_RED, r15
	call draw_circle
	jmp end_table
case_3:
	mov #50, r12
	mov #15, r13
	mov #3, r14
	mov &COLOR_GREEN, r15
	call draw_circle
	jmp end_table
case_4:
	mov #30, r12
	mov #30, r13
	mov #6, r14
	mov &COLOR_GREEN, r15
	call draw_circle
	jmp end_table
end_table:
	pop r0
