.cpu cortex-m0
.text
.align 1
.global application



application:
  push {lr}             
  ldr 	r0, = string    
  bl 	print_asciz        
  pop 	{pc} 

string:
  .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"