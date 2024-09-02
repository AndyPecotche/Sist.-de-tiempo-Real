opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 7503"

opt pagewidth 120

	opt lm

	processor	16F84A
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
	FNROOT	_main
	FNCALL	intlevel1,_isr
	global	intlevel1
	FNROOT	intlevel1
	global	_contador
	global	_flag1
	global	_PORTB
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:
_PORTB	set	6
	global	_TMR0
_TMR0	set	1
	global	_GIE
_GIE	set	95
	global	_RA0
_RA0	set	40
	global	_RA1
_RA1	set	41
	global	_T0IE
_T0IE	set	93
	global	_T0IF
_T0IF	set	90
	global	_TRISA
_TRISA	set	133
	global	_TRISB
_TRISB	set	134
	global	_PS0
_PS0	set	1032
	global	_PS1
_PS1	set	1033
	global	_PS2
_PS2	set	1034
	global	_PSA
_PSA	set	1035
	global	_T0CS
_T0CS	set	1037
	global	_T0SE
_T0SE	set	1036
	file	"C:\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect	bssBANK0,class=BANK0,space=1
global __pbssBANK0
__pbssBANK0:
_contador:
       ds      2

_flag1:
       ds      2

; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
	clrf	((__pbssBANK0)+2)&07Fh
	clrf	((__pbssBANK0)+3)&07Fh
psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	??_main
??_main:	; 0 bytes @ 0x0
psect	cstackBANK0,class=BANK0,space=1
global __pcstackBANK0
__pcstackBANK0:
	global	?_main
?_main:	; 0 bytes @ 0x0
	global	?_isr
?_isr:	; 0 bytes @ 0x0
	global	??_isr
??_isr:	; 0 bytes @ 0x0
	ds	4
;;Data sizes: Strings 0, constant 0, data 0, bss 4, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON           0      0       0
;; BANK0           66      4       8

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _isr in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _isr in BANK0
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 0
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (1) _isr                                                  4     4      0       0
;;                                              0 BANK0      4     4      0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;
;; _isr (ROOT)
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            0      0       0       0        0.0%
;;EEDATA              40      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;COMMON               0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       0       2        0.0%
;;BANK0               42      4       8       3       12.1%
;;ABS                  0      0       8       4        0.0%
;;BITBANK0            42      0       0       5        0.0%
;;DATA                 0      0       8       6        0.0%

	global	_main
psect	maintext

;; *************** function _main *****************
;; Defined at:
;;		line 14 in file "..\..\..\..\..\..\..\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       0
;;      Totals:         0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"..\..\..\..\..\..\..\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.c"
	line	14
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 7
; Regs used in _main: [wreg+status,2]
	line	16
	
l1347:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1037/8)^080h,(1037)&7
	line	19
	bcf	(1036/8)^080h,(1036)&7
	line	23
	bcf	(1035/8)^080h,(1035)&7
	line	26
	bcf	(1034/8)^080h,(1034)&7
	line	27
	bcf	(1033/8)^080h,(1033)&7
	line	28
	bcf	(1032/8)^080h,(1032)&7
	line	32
	bsf	(95/8),(95)&7
	line	40
	bsf	(93/8),(93)&7
	line	76
	
l1349:	
	movlw	(0EFh)
	movwf	(134)^080h	;volatile
	line	77
	movlw	(03h)
	movwf	(133)^080h	;volatile
	line	79
	
l171:	
	line	81
	movlw	(083h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(1)	;volatile
	line	82
	
l1351:	
	btfss	(40/8),(40)&7
	goto	u2191
	goto	u2190
u2191:
	goto	l1355
u2190:
	
l1353:	
	btfsc	(41/8),(41)&7
	goto	u2201
	goto	u2200
u2201:
	goto	l171
u2200:
	goto	l1355
	
l174:	
	goto	l1355
	line	84
	
l175:	
	line	85
	
l1355:	
	movlw	01h
	xorwf	(_flag1),w
	iorwf	(_flag1+1),w
	skipz
	goto	u2211
	goto	u2210
u2211:
	goto	l1355
u2210:
	line	86
	
l1357:	
	movf	(6),w	;volatile
	xorlw	010h
	movwf	(6)	;volatile
	line	87
	
l1359:	
	clrf	(_flag1)
	clrf	(_flag1+1)
	goto	l1355
	line	88
	
l176:	
	goto	l1355
	line	89
	
l177:	
	line	84
	goto	l1355
	
l178:	
	goto	l171
	line	90
	
l172:	
	goto	l171
	line	91
	
l179:	
	line	79
	goto	l171
	
l180:	
	line	92
	
l181:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
	global	_isr
psect	text108,local,class=CODE,delta=2
global __ptext108
__ptext108:

;; *************** function _isr *****************
;; Defined at:
;;		line 94 in file "..\..\..\..\..\..\..\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0
;;      Params:         0       0
;;      Locals:         0       0
;;      Temps:          0       4
;;      Totals:         0       4
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text108
	file	"..\..\..\..\..\..\..\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.c"
	line	94
	global	__size_of_isr
	__size_of_isr	equ	__end_of_isr-_isr
	
_isr:	
	opt	stack 7
; Regs used in _isr: [wreg+status,2]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(??_isr+0)
	movf	fsr0,w
	movwf	(??_isr+1)
	movf	pclath,w
	movwf	(??_isr+2)
	movf	btemp+1,w
	movwf	(??_isr+3)
	ljmp	_isr
psect	text108
	line	95
	
i1l1361:	
	bcf	(95/8),(95)&7
	line	96
	btfss	(90/8),(90)&7
	goto	u222_21
	goto	u222_20
u222_21:
	goto	i1l1371
u222_20:
	line	97
	
i1l1363:	
	bcf	(90/8),(90)&7
	line	98
	
i1l1365:	
	movlw	(08Dh)
	movwf	(1)	;volatile
	line	99
	movlw	low(01h)
	addwf	(_contador),f
	skipnc
	incf	(_contador+1),f
	movlw	high(01h)
	addwf	(_contador+1),f
	movlw	0FAh
	xorwf	((_contador)),w
	iorwf	((_contador+1)),w
	skipz
	goto	u223_21
	goto	u223_20
u223_21:
	goto	i1l1371
u223_20:
	line	100
	
i1l1367:	
	movlw	low(01h)
	movwf	(_flag1)
	movlw	high(01h)
	movwf	((_flag1))+1
	line	101
	
i1l1369:	
	clrf	(_contador)
	clrf	(_contador+1)
	goto	i1l1371
	line	103
	
i1l185:	
	goto	i1l1371
	line	104
	
i1l184:	
	line	105
	
i1l1371:	
	bsf	(95/8),(95)&7
	line	107
	
i1l186:	
	movf	(??_isr+3),w
	movwf	btemp+1
	movf	(??_isr+2),w
	movwf	pclath
	movf	(??_isr+1),w
	movwf	fsr0
	swapf	(??_isr+0)^00h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_isr
	__end_of_isr:
;; =============== function _isr ends ============

	signat	_isr,88
psect	text109,local,class=CODE,delta=2
global __ptext109
__ptext109:
	global	btemp
	btemp set 04Eh

	DABS	1,78,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
