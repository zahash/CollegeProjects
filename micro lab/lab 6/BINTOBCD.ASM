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

MOV DX, 0FFFDH                                                                                                                                                                                                                                          
MOV CX, 0000H           ; THIS STORES EACH DIGIT BEFORE PUSH TO MEMORY

MOV AX, 2710H
MOV BL, 0AH

NEXT:
DIV BL             ; FIX THIS LINE
JZ TERM

DIG:
SUB DX, AX
INC CX
JNC DIG
ADD DX, AX
MOV [SI], DX
JMP NEXT

TERM:
HLT
CODE ENDS
END START
