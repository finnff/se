.cpu cortex-m0
.text
.align 1
.global application



application:
  push {lr} @push lr to stack            
  ldr 	r0, = string @load string into r0
  bl 	print_asciz  @branch link to print function
  pop 	{pc} @pop programcounter out

string:
  .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"