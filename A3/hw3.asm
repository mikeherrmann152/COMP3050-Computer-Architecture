loop:	lodd myCounter:		; Load  counter of numbers to Accumulator (ac)
		jzer done:	; If zero, then done
		subd constant1:	; decrement 1 from myCounter
		stod myCounter:	; store the result from substraction to counter
one:	lodd daddr:		; load poiter array to accumuator (ac)
		pshi		; push argument to stack
		addd constant1:	
		stod daddr:	; Store pointer array for next fib
		call fib:	; Call fib with the arg that is on stack
		insp 1		; Clear stack
two:	push			; Put return on stack
		lodd raddr:	; load result pointer array
		popi		
		addd constant1:	
		stod raddr:	; store pointer array for later use
		jump loop:	; resurcive the function
fib:	lodl 1			; Load the arg from stack
		jzer fibZero:	; if counter is zero, go to fibZero
		subd constant1:	; decrement argument
		jzer fibOne:	; if 0 go to fibOne
		push		
		call fib:	; Recursive call to fib
		push		
		lodl 1		; load arg - 1 from stack
		subd constant1:	; ac is arg - 2
		push		
		call fib:	; resurcively call fib again
clear:	insp 1			; Clear the arg - 2 from stack
		addl 0		; store new result in ac
		insp 2		; Clear all arguements from stack
		retn		; Return function
fibZero:lodd constant0:		; set ac = 0
		retn		; Return
fibOne:	lodd constant1:		; set ac = 1
		retn		; Return
done:	halt			; Halt program execution


	.LOC 100		; data begin at 100
data:
	3
	9
	18
	23
	25
resultA:
	0
	0
	0
	0
	0
daddr:		data:
raddr:		resultA:
constant0:		0      	;constant 0
constant1:		1	;constant 1
myCounter:	 5
