readint:	call rbsywt:
	lodd 4092
	subd numoff:
	push
nxtdig:	call rbsywt:
	lodd 4092
	stod nxtchr:
	subd n1:
	jzer done:
	mult 10
	lodd nxtchr:
	subd numoff:
	adl 0
	stol 0
	jump nxtdig:

done:	pop
	retn
