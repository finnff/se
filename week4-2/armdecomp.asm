.cpu cortex-m0 
.bss
	buffer: .fill 0x28 //fill with 40
.text 
.align 2 
.global armdecomp

armdecomp:
	PUSH {R4, R5, R6, R7, LR} 	//push alle registers naar de stack
	LDR	R3, =buffer				//start van buffer in R3
	LDR	R4, =encoded			//in R4 word een pointer naar de eerste geheugenlocatie geplaatst
	MOV	R5, #0					//init index pointer met 0	
	MOV	R6, #0					//init offset met 0
	MOV	R7, #0					//init lengte met 0
	
loop1:
	ADD R0, R4, R5				//stop het geheugenadress van R4 met index R5 in R0
	LDRB R0, [r0]				//haal de waarde van het geheugenadress op en stop het in R0
	ADD R5, R5, #1				//verhoog index pointer met 1
	CMP R0, #0					//controleer of we het einde van compressed bereikt hebben
	BEQ	done
	
	CMP R0, #'@'				//controleer of het character in R0 compressed is
	BEQ	decode				//in geval van compressie branch naar decode
	bl swap					//branch link naar de swap functie
	bl uart_put_char			//print het character in R0
	b loop1					//ga verder met door compressed itereren
	
	
	
decode:
	ADD R6, R4, R5				//stop het geheugenadress van R4 met index R5 in R6
	LDRB r6, [R6]				//haal de waarde van het geheugenadress op en stop het in R6
	ADD R5, R5, #1				//verhoog de index pointer met 1
	ADD R7, R4, R5				//stop het geheugenadress van R4 met index R5 in R7
	LDRB r7, [R7]				//haal de waarde van het geheugenadress op en stop het in R7
	ADD R5, R5, #1				//verhoog de index pointer met 1
	SUB R6, R6, #'0'			//trek er '0'(==48) van af
	SUB R7, R7, #'0'			//trek er '0'(==48) van af
	
decodeLoop:
	ADD R0, R3, R6				//tell R6 bij R3 op en stop dat in R0
	LDRB R0, [R0]				//haal de waarde van het geheugenadress op en stop het in R0
	bl swap					//branch link naar de swap functie
	bl uart_put_char			//print het character in R0
	SUB	R7, R7, #1				//verlaag lengte met 1
	BEQ loop1				//als het hele woord gedecodeed is ga door met loop1
	b decodeLoop			//ga verder met het woord decodeen
	
swap:
	PUSH {LR}
	MOV R1, #39					//zet de buffer lengte in R1
swapLoop:
	SUB R1, R1, #1 				//zet R1 op de vorige index door er 1 vanaf te halen
	ADD R2, R3, R1 				//stop het geheugenadress van R3 met index R1 in R2
	LDRB R2, [R2] 				//Haal de waarde van het geheungenadress op en zet dat in R2
	ADD R1, R1, #1				//tel 1 op bij R1
	STRB R2, [R3, R1]			//store het character op buffer[R1]
	SUB R1, R1, #1				//trek 1 van R1 af voor de volgende loop

	CMP R1, #0					//compare R1 met 0
	BEQ SwapEnd				//als het gelijk is branch naar SwapEnd
	b swapLoop				//zo niet ga door met swapLoop
	
SwapEnd:
	STRB R0, [R3, #0]			//plaats huidige char op index 0
	POP {PC}	
	
done:
	POP {R4, R5, R6, R7, PC} 	//pop alles weer van de stack