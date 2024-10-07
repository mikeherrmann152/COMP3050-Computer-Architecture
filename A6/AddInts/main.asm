start:	lodd on:
	stod 4095
	stod 4093
	loco str1:
	push
	call writestr:
	insp 1
	call readint:
	stod binum:
	loco str1
	push
	call writestr:
	insp 1
	call readint:
	stod binum2:
	lodd binum1:
	push
	lodd binum2:
	push
	call addints:
	insp 2
	stod sum:
	jpos ptrsum:
	loco str3:
	push
	call writestr:
	insp 1
	halt
prtsum:	loco str2:
	push
	call writestr:
	insp 1
	lodd sum:
	push
	call writeint:
	insp 1
	halt
