
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

00000000004025c0 <phase_06>:
  4025c0:	endbr64
  4025c4:	push   %rbp
  4025c5:	mov    %rsp,%rbp
  4025c8:	push   %r12
  4025ca:	mov    %rsi,%r12
  4025cd:	mov    $0x1,%esi
  4025d2:	push   %rbx
  4025d3:	mov    %rdi,%rbx
  4025d6:	sub    $0x10,%rsp
  4025da:	call   402c60 <valid_u32_fields>
  4025df:	test   %al,%al
  4025e1:	jne    4025f0 <phase_06+0x30>
  4025e3:	add    $0x10,%rsp
  4025e7:	xor    %eax,%eax
  4025e9:	pop    %rbx
  4025ea:	pop    %r12
  4025ec:	pop    %rbp
  4025ed:	ret
  4025ee:	xchg   %ax,%ax
  4025f0:	xor    %eax,%eax
  4025f2:	lea    -0x14(%rbp),%rdx
  4025f6:	mov    $0x403189,%esi
  4025fb:	mov    %rbx,%rdi
  4025fe:	call   4011e0 <__isoc99_sscanf@plt>
  402603:	cmp    $0x1,%eax
  402606:	jne    4025e3 <phase_06+0x23>
  402608:	mov    %r12,%rdi
  40260b:	call   402570 <p6_dispatch>
  402610:	cmp    %eax,-0x14(%rbp)
  402613:	sete   %al
  402616:	add    $0x10,%rsp
  40261a:	pop    %rbx
  40261b:	pop    %r12
  40261d:	pop    %rbp
  40261e:	ret

Disassembly of section .fini:
