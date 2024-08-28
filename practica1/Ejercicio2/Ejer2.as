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
	global	_contador
	global	_PORTB
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:
_PORTB	set	6
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

; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
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
;;Data sizes: Strings 0, constant 0, data 0, bss 2, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON           0      0       0
;; BANK0           66      0       2

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   None.
;;
;; Critical Paths under _main in BANK0
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

;; Call Graph Graphs:

;; _main (ROOT)
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
;;BANK0               42      0       2       3        3.0%
;;ABS                  0      0       2       4        0.0%
;;BITBANK0            42      0       0       5        0.0%
;;DATA                 0      0       2       6        0.0%

	global	_main
psect	maintext

;; *************** function _main *****************
;; Defined at:
;;		line 11 in file "..\..\..\..\..\..\..\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.c"
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
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"..\..\..\..\..\..\..\Users\windows\Documents\Sist. de tiempo real\practica1\Ejercicio2\Ejer2.c"
	line	11
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 8
; Regs used in _main: [wreg+status,2]
	line	13
	
l1331:	
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1037/8)^080h,(1037)&7
	line	16
	bcf	(1036/8)^080h,(1036)&7
	line	20
	bcf	(1035/8)^080h,(1035)&7
	line	23
	bcf	(1034/8)^080h,(1034)&7
	line	24
	bcf	(1033/8)^080h,(1033)&7
	line	25
	bcf	(1032/8)^080h,(1032)&7
	line	29
	bcf	(95/8),(95)&7
	line	37
	bcf	(93/8),(93)&7
	line	49
	bcf	(90/8),(90)&7
	line	75
	
l1333:	
	movlw	(0EFh)
	movwf	(134)^080h	;volatile
	line	76
	movlw	(03h)
	movwf	(133)^080h	;volatile
	goto	l1335
	line	77
	
l169:	
	line	79
	
l1335:	
	bcf	status, 5	;RP0=0, select bank0
	btfss	(40/8),(40)&7
	goto	u2181
	goto	u2180
u2181:
	goto	l173
u2180:
	
l1337:	
	btfsc	(41/8),(41)&7
	goto	u2191
	goto	u2190
u2191:
	goto	l1335
u2190:
	goto	l173
	
l172:	
	line	81
	
l173:	
	line	82
	btfss	(90/8),(90)&7
	goto	u2201
	goto	u2200
u2201:
	goto	l174
u2200:
	line	83
	
l1339:	
	movlw	low(01h)
	addwf	(_contador),f
	skipnc
	incf	(_contador+1),f
	movlw	high(01h)
	addwf	(_contador+1),f
	line	84
	
l1341:	
	bcf	(90/8),(90)&7
	line	85
	
l174:	
	line	86
	movlw	high(07A12h)
	xorwf	(_contador+1),w
	skipz
	goto	u2215
	movlw	low(07A12h)
	xorwf	(_contador),w
u2215:

	skipz
	goto	u2211
	goto	u2210
u2211:
	goto	l173
u2210:
	line	87
	
l1343:	
	movf	(6),w	;volatile
	xorlw	010h
	movwf	(6)	;volatile
	line	88
	
l1345:	
	clrf	(_contador)
	clrf	(_contador+1)
	goto	l173
	line	89
	
l175:	
	goto	l173
	line	90
	
l176:	
	line	81
	goto	l173
	
l177:	
	goto	l1335
	line	91
	
l170:	
	goto	l1335
	line	92
	
l178:	
	line	77
	goto	l1335
	
l179:	
	line	93
	
l180:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,88
psect	maintext
	global	btemp
	btemp set 04Eh

	DABS	1,78,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
