
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

00000000004023a0 <phase_04>:
  4023a0:	endbr64
  4023a4:	push   %rbp
  4023a5:	mov    %rsp,%rbp
  4023a8:	push   %r12
  4023aa:	mov    %rsi,%r12
  4023ad:	mov    $0x1,%esi
  4023b2:	push   %rbx
  4023b3:	mov    %rdi,%rbx
  4023b6:	sub    $0x10,%rsp
  4023ba:	call   402c60 <valid_u32_fields>
  4023bf:	test   %al,%al
  4023c1:	jne    4023d0 <phase_04+0x30>
  4023c3:	add    $0x10,%rsp
  4023c7:	xor    %eax,%eax
  4023c9:	pop    %rbx
  4023ca:	pop    %r12
  4023cc:	pop    %rbp
  4023cd:	ret
  4023ce:	xchg   %ax,%ax
  4023d0:	xor    %eax,%eax
  4023d2:	lea    -0x14(%rbp),%rdx
  4023d6:	mov    $0x403189,%esi
  4023db:	mov    %rbx,%rdi
  4023de:	call   4011e0 <__isoc99_sscanf@plt>
  4023e3:	cmp    $0x1,%eax
  4023e6:	jne    4023c3 <phase_04+0x23>
  4023e8:	mov    %r12,%rcx
  4023eb:	mov    %r12,%rax
  4023ee:	mov    %r12d,%edi
  4023f1:	xor    %esi,%esi
  4023f3:	shr    $0x20,%rax
  4023f7:	shr    $0x7,%rcx
  4023fb:	and    $0x7f,%edi
  4023fe:	mov    $0x7f,%edx
  402403:	xor    %eax,%ecx
  402405:	call   402330 <p4_walk>
  40240a:	cmp    %eax,-0x14(%rbp)
  40240d:	sete   %al
  402410:	add    $0x10,%rsp
  402414:	pop    %rbx
  402415:	pop    %r12
  402417:	pop    %rbp
  402418:	ret

Disassembly of section .fini:
