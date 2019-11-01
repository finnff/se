//@finnff

.cpu cortex-m0 
.bss
	buffer: .fill 0x28 //fill with 40
.text 
.align 2 
.global armdecomp


armdecomp:
	PUSH {R4, R5, R6, R7, LR} //Push R4-R7+PC to stack
	LDR	R3, =buffer						// Load Buffer in R3
	LDR	R4, =encoded					// Load Encoded in R4
	MOV	R5, #0								// generate index
	MOV	R6, #0								// generate offset
	MOV	R7, #0								// generate length
	

loop1:
	ADD R0, R4, R5			//move pointer R4[R5] into R0
	LDRB R0, [r0]				//Dereference value from R0
	ADD R5, R5, #1			//increment pointer
	CMP R0, #0					//set flags for #0
	BEQ	done						// if R0 ==0, branch to done
	
	CMP R0, #'@'				//Set Flags for #@
	BEQ	decode					// If R0 == @, Branch to decode
	bl swap					    // branch link to Swap
	bl uart_put_char		// branch link to Print
	b loop1							// restart loop1
	
	
decode:
	ADD R6, R4, R5				//move pointer R4[R5] into R6	
	LDRB r6, [R6]					//Dereference pointer into R6	
	ADD R5, R5, #1				//Increment R5								
	ADD R7, R4, R5				//move pointer R4[R5] into R7	
	LDRB r7, [R7]					//Dereference pointer into R6	
	ADD R5, R5, #1				//increment R5								
	SUB R6, R6, #48			  //Subtract 48 from R6		
	SUB R7, R7, #48			  //Subtract 48 from R7		
	
decodeLoop:
	ADD R0, R3, R6				// Add R3+R6 into R0											
	LDRB R0, [R0]				 	// dereference into R0										
	bl swap								// Branchlink swap												
	bl uart_put_char			// Branchlink Print												
	SUB	R7, R7, #1				// Subtract 1 from R7											
	BEQ loop1			      	// Brance to Loop1, once word is finishe`d	
	b decodeLoop			   	// Else continue looping									
	
swap:
	PUSH {LR}
	MOV R1, #39						//Set Buffer length in R1

swapLoop:
	SUB R1, R1, #1 				// Subtract 1 From R1 to return to previous index		
	ADD R2, R3, R1 				//move pointer R3[R1] into R2												
	LDRB R2, [R2] 				//Dereference Pointer into R2												
	ADD R1, R1, #1				//Increment R1																			
	STRB R2, [R3, R1]			//Store R2 on buffer ar R3[R1]											
	SUB R1, R1, #1				//Remove 1 from R1																	
	CMP R1, #0						//Set Flags																					
	BEQ SwapEnd						//If R1==0, Branch to SwapEnd												
	b swapLoop						//Else Continue Looping															
	
SwapEnd:
	STRB R0, [R3, #0]			//Store R0 onto R3[0]
	POP {PC}	
	
done:
	POP {R4, R5, R6, R7, PC} 	//pop R4-R7+PC From stack