DATA SEGMENT 
    
     MSG1 DB 'THE CURRENT TIME OF THE SYSTEM IS : $'
    HR DB ?
    MIN DB ?
    SEC DB ?
    MSEC DB ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
   START:        MOV AX, DATA
        MOV DS, AX
        MOV AH,2CH    	 	
        INT 21H
        MOV HR, CH     	 	
        MOV MIN, CL   	  	
        MOV SEC, DH     		
        MOV MSEC, DL   	 	
        LEA DX, MSG1    		
        MOV AH, 09H
        INT 21H
        MOV AL, HR    		
        AAM        			
        MOV BX, AX
        CALL DISPLAY    		
        MOV DL, ':'    		 
        MOV AH, 02H
        INT 21H
        MOV AL, MIN      
        AAM     
        MOV BX, AX
        CALL DISPLAY    		
        MOV DL, ':'    	 	
        MOV AH, 02H
        INT 21H
        MOV AL, SEC    
        AAM                   
        MOV BX, AX
        CALL DISPLAY   	 	
        MOV DL, '.'     		
        MOV AH, 02H
        INT 21H
        MOV AL, MSEC   
        AAM                     
        MOV BX, AX
        CALL DISPLAY    		
        MOV AH, 4CH
        INT 21H
        DISPLAY PROC NEAR
                MOV DL, BH
                ADD DL, 30H    		
                MOV AH, 02H
                INT 21H
                MOV DL, BL
                ADD DL, 30H    		
                MOV AH, 02H
                INT 21H
                RET
      DISPLAY ENDP
      HLT
CODE ENDS
END START