.intel_syntax noprefix

.global _syscall
_syscall:
	mov r10, rcx
	syscall
	ret

#define c(x, n)		\
.global x;		\
x:;			\
	mov eax, n;	\
	jmp _syscall

c(exit, 60)
c(read,  0)
c(write, 1)
c(time, 201)

.global _start
_start:
	xor rbp, rbp
	pop rdi		/* argc */
	mov rsi, rsp	/* argv */
	call main
	call exit


