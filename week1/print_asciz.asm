.cpu cortex-m0
.text
.align 1
.global print_asciz



print_asciz:
    push {r5,lr}    @push link register onto stack
    mov r5, r0      @save r0 for processing in loop

loop:
    ldrb r0, [r5]   @load r5 data from earlier
    cmp r0,#0       @evaluate While condition
    beq done        @branch to done if equals 
    mov  r0, r5     @move char to r0
    bl toggle_case  @branch link to case
    bl uart_put_char@branch link to uart... if not 
    add r5,r5,#1    @increase index by 1
    b loop          @branch to start of loop
    
done:
    pop {r5,pc}     @pop program counters


toggle_case:
  ldrb    r0, [r0]        
  cmp     r0, #96     
  bls     lowercase  @branch lower if char is less than 96('a')
  cmp     r0, #122
  bhi     lowercase  @branch lower if char is higher than 122('z')
  sub     r0, r0, #32
  b end
  
lowercase:
  cmp     r0, #64
  bls     end
  cmp     r0, #90
  bhi     end
  add     r0, r0, #32
  b end

end:
  mov pc, lr
