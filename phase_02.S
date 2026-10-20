
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

00000000004020f0 <phase_02>:
  4020f0:	endbr64
  4020f4:	push   %rbp
  4020f5:	mov    %rsp,%rbp
  4020f8:	push   %r13
  4020fa:	mov    %rsi,%r13
  4020fd:	mov    $0x6,%esi
  402102:	push   %r12
  402104:	mov    %rdi,%r12
  402107:	push   %rbx
  402108:	sub    $0x28,%rsp
  40210c:	call   402c60 <valid_u32_fields>
  402111:	test   %al,%al
  402113:	jne    402128 <phase_02+0x38>
  402115:	xor    %ebx,%ebx
  402117:	lea    -0x18(%rbp),%rsp
  40211b:	mov    %ebx,%eax
  40211d:	pop    %rbx
  40211e:	pop    %r12
  402120:	pop    %r13
  402122:	pop    %rbp
  402123:	ret
  402124:	nopl   0x0(%rax)
  402128:	mov    %eax,%ebx
  40212a:	lea    -0x2c(%rbp),%rax
  40212e:	lea    -0x3c(%rbp),%rcx
  402132:	mov    $0x40317a,%esi
  402137:	push   %rax
  402138:	lea    -0x30(%rbp),%rax
  40213c:	lea    -0x40(%rbp),%rdx
  402140:	mov    %r12,%rdi
  402143:	push   %rax
  402144:	lea    -0x34(%rbp),%r9
  402148:	lea    -0x38(%rbp),%r8
  40214c:	xor    %eax,%eax
  40214e:	call   4011e0 <__isoc99_sscanf@plt>
  402153:	pop    %rdx
  402154:	pop    %rcx
  402155:	cmp    $0x6,%eax
  402158:	jne    402115 <phase_02+0x25>
  40215a:	mov    %r13,%rax
  40215d:	mov    -0x40(%rbp),%esi
  402160:	shr    $0x14,%rax
  402164:	add    %eax,%eax
  402166:	and    $0x1e,%eax
  402169:	add    $0x1f,%eax
  40216c:	cmp    %eax,%esi
  40216e:	jne    402115 <phase_02+0x25>
  402170:	mov    $0x14,%ecx
  402175:	mov    $0x1,%edx
  40217a:	mov    %r13,%rax
  40217d:	shr    %cl,%rax
  402180:	and    $0x3f,%eax
  402183:	add    %edx,%eax
  402185:	xor    %esi,%eax
  402187:	mov    -0x40(%rbp,%rdx,4),%esi
  40218b:	lea    (%rax,%rax,4),%eax
  40218e:	cmp    %eax,%esi
  402190:	jne    402115 <phase_02+0x25>
  402192:	add    $0x1,%rdx
  402196:	add    $0x2,%ecx
  402199:	cmp    $0x6,%rdx
  40219d:	jne    40217a <phase_02+0x8a>
  40219f:	jmp    402117 <phase_02+0x27>

Disassembly of section .fini:
