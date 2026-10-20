
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000402050 <p1_compute>:
  402050:	endbr64
  402054:	push   %rbp
  402055:	mov    %rdi,%rdx
  402058:	mov    %rdi,%rax
  40205b:	shr    $0x20,%rax
  40205f:	mov    %rdx,%rsi
  402062:	mov    %eax,%edi
  402064:	shr    $0x10,%rsi
  402068:	mov    %rsp,%rbp
  40206b:	call   402030 <p1_step1>
  402070:	mov    %edi,%esi
  402072:	mov    %edx,%edi
  402074:	mov    %eax,%ecx
  402076:	call   402020 <p1_step0>
  40207b:	mov    %ecx,%esi
  40207d:	mov    %eax,%edi
  40207f:	call   402040 <p1_step2>
  402084:	pop    %rbp
  402085:	ret

Disassembly of section .fini:
