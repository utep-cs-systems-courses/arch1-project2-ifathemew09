	.arch msp430g2553
	.p2align 1,0

	.data
S:
	.word 1

	.text
jt:
	.word default
	.word red

	.text
	.global switching_leds_assembly
switching_leds_assembly:
	mov &S, r12
	cmp #3, r12
	jc default

	add r12, r12
	mov jt(r12), r0

default:
	cmp.b #1, &green_on
	jz end

	mov.b #1, &green_on
	mov.b #0, &red_on
	jmp red

red:
	mov.b #0, &green_on
	mov.b #1, &red_on
	jmp end
end:
	ret
