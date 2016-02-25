all:
	gcc -Wall -c Array.c
	gcc -Wall -c CheckArray.c
	gcc -Wall -o CheckArray.exe Array.o CheckArray.o