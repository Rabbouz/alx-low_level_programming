global main
extern printf

format db 'Hello, Holberton', 10, 0


main:
mov edi, format
call printf
xor eax, eax
ret
