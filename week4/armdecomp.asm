.cpu cortex-m0 
.text
.align 1
.global armdecomp


 armdecomp:
  push{lr}
  ldr r0,output
  