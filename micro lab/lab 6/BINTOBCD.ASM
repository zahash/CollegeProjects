; 16 BIT BINARY TO BCD CONVERTER

ASSUME CS:CODE, DS:DATA

DATA SEGMENT
;BIN DB 0FFFDH
BCD DW 5 DUP(?)                                                                                                                                                                                                                                         
DATA ENDS

CODE SEGMENT
START:

MOV AX, DATA
MOV DS, AX

MOV SI, OFFSET BCD

MOV AX, 0FFFDH                                                                                                                                                                                                                                          
MOV BX, 0000H

MOV CX, 2710H

NEXT:
DIV CX, 0AH             ; FIX THIS LINE
JZ TERM

DIG:
SUB AX, CX
INC BX
JNC DIG
ADD AX, CX
MOV [SI], AX
JMP NEXT

TERM:
HLT
CODE ENDS
END START
