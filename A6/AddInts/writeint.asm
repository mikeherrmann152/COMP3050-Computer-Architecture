writeint:	lodl 1
	stod temp:
	
cnvrt:	lodd c10:
	push
	lodd temp:
	push
	div
	lodd lpcnt:
	addd c1:
	stod lpcnt:
	lodl 1
	addd numoff:
	push
	lodd psum:
	popi
	addd c1:
	stod psum:
	lodl 0
	insp 4
	jzer wrloop:
	stod temp:
	jump cnvrt:
	
wrloop:	lodd lpcnt:
	jzer icrnl:
	subd c1:
	stod lpcnt:
	lodd psum:
	subd c1:
	stod psum:
	pshi
	call xbsywt:
	pop
	stod 4094
	jump wrloop:

icrnl:	lodd cr:
	stod 4094
	call xbsywt:
	lodd nl:
	stod 4094
	call xbsywt:
	retn
