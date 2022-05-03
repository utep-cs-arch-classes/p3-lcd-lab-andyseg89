	.arch msp430g2553
	.p2align 1,0
	.text

	.global state
	.extern switch_state

	
table:
	.word default
	.word case_1
	.word case_2
	.word case_3
	.word case_4
state:
	mov &switch_state, r12
	and 0x00ff, r12
	add r12, r12
	mov table(r12), pc
default:
	jmp end_table
case_1:
	mov #80, r12
	mov #15, r13
	mov #2, r14
	mov 0xf800, r15
	#call draw_circle
	jmp end_table
case_2:
	mov #30, r12
	mov #10, r13
	mov #4, r14
	mov 0xf800, r15
	call draw_circle
	jmp end_table
case_3:
	mov #80, r12
	mov #15, r13
	mov #2, r14
	mov 0xf800, r15
	#call draw_circle
	jmp end_table
case_4:
	mov #30, r12
	mov #30, r13
	mov #6, r14
	mov 0xf800, r15
	#call draw_circle
	jmp end_table
end_table:
	pop r0
