	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"gpioled.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"/sys/class/gpio/export\000"
	.align	2
.LC1:
	.ascii	"%d\000"
	.align	2
.LC2:
	.ascii	"/sys/class/gpio/gpio%d/direction\000"
	.align	2
.LC3:
	.ascii	"out\000"
	.align	2
.LC4:
	.ascii	"/sys/class/gpio/gpio%d/value\000"
	.align	2
.LC5:
	.ascii	"1\000"
	.text
	.align	2
	.global	ledControl
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	ledControl, %function
ledControl:
	@ args = 0, pretend = 0, frame = 8208
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8192
	sub	sp, sp, #16
	sub	r3, fp, #8192
	sub	r3, r3, #4
	str	r0, [r3, #-12]
	mov	r1, #1
	ldr	r0, .L3
	bl	open
	str	r0, [fp, #-8]
	sub	r3, fp, #8192
	sub	r3, r3, #4
	mov	r2, r3
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	ldr	r2, [r2, #-12]
	ldr	r1, .L3+4
	mov	r0, r3
	bl	sprintf
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	mov	r0, r3
	bl	strlen
	mov	r2, r0
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	mov	r1, r3
	ldr	r0, [fp, #-8]
	bl	write
	ldr	r0, [fp, #-8]
	bl	close
	sub	r3, fp, #8192
	sub	r3, r3, #4
	mov	r2, r3
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	ldr	r2, [r2, #-12]
	ldr	r1, .L3+8
	mov	r0, r3
	bl	sprintf
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	mov	r1, #1
	mov	r0, r3
	bl	open
	str	r0, [fp, #-8]
	mov	r2, #4
	ldr	r1, .L3+12
	ldr	r0, [fp, #-8]
	bl	write
	ldr	r0, [fp, #-8]
	bl	close
	sub	r3, fp, #8192
	sub	r3, r3, #4
	mov	r2, r3
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	ldr	r2, [r2, #-12]
	ldr	r1, .L3+16
	mov	r0, r3
	bl	sprintf
	sub	r3, fp, #8192
	sub	r3, r3, #4
	sub	r3, r3, #4
	mov	r1, #1
	mov	r0, r3
	bl	open
	str	r0, [fp, #-8]
	mov	r2, #2
	ldr	r1, .L3+20
	ldr	r0, [fp, #-8]
	bl	write
	ldr	r0, [fp, #-8]
	bl	close
	bl	getchar
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L4:
	.align	2
.L3:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.size	ledControl, .-ledControl
	.section	.rodata
	.align	2
.LC6:
	.ascii	"Usage : %s GPIO_NO\012\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	ldr	r3, [fp, #-16]
	cmp	r3, #1
	bgt	.L6
	ldr	r3, [fp, #-20]
	ldr	r3, [r3]
	mov	r1, r3
	ldr	r0, .L8
	bl	printf
	mvn	r3, #0
	b	.L7
.L6:
	ldr	r3, [fp, #-20]
	add	r3, r3, #4
	ldr	r3, [r3]
	mov	r0, r3
	bl	atoi
	str	r0, [fp, #-8]
	ldr	r0, [fp, #-8]
	bl	ledControl
	mov	r3, #0
.L7:
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L9:
	.align	2
.L8:
	.word	.LC6
	.size	main, .-main
	.ident	"GCC: (Raspbian 10.2.1-6+rpi1) 10.2.1 20210110"
	.section	.note.GNU-stack,"",%progbits
