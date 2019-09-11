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
  ldrb    r0, [r0]   @load r0 registers
  cmp     r0, #96    @compare with 'a'
  bls     lower      @branch lower if char is less than 96('a')
  cmp     r0, #122   @comapre with 'z'
  bhi     end        @branch end if char is higher than 122('z')
  sub     r0, r0, #32@subract 32 to capitalize
  b end              @end routine
  
lower:
  cmp     r0, #64    @compare with"A"
  bls     end        @branch if less than 64 
  cmp     r0, #90    @compare with "Z"
  bhi     end        @branch if higher than 90
  add     r0, r0, #32@add 32 to lower
  b end              @end subroutine

end:
  mov pc, lr         @move program counter
