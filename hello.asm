.586
.MODEL flat,stdcall

includelib	msvcrt.lib

INCLUDELIB kernel32.lib
INCLUDELIB ucrt.lib
INCLUDELIB legacy_stdio_definitions.lib

ExitProcess PROTO, dwExitCode:DWORD		; return code
printf proto C: vararg

.data
	msg db 'Hello World！',13,10,0
.code
main PROC
;main:

	mov eax,10000h		; EAX = 10000h
	add eax,40000h		; EAX = 50000h
	sub eax,20000h		; EAX = 30000h

	invoke printf, offset msg
	pushad
		push offset msg
		call printf
	popad
	pushad
		;push 0h
		;call ExitProcess
		invoke ExitProcess,0
	popad

main ENDP
end main