writestr:	lodl 1
	pshi
	addd c1:
	stol 2
	call xbsywt:
	lodl 0
	jzer scrnl:
	stod 4094
	subd c255:
	jneg scrnl:
	pop
	rshift 8
	push
	call xbsywt:
	pop
	stod 4094
	jump writestr:

scrnl:	insp 1
	lodd cr:
	stod 4094
	call xbsywt:
	lodd nl:
	stod 4094
	call xbsywt:
	retn
