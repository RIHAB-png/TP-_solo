all : prog

prog : def.o menu.o game.o
	gcc -o prog def.o menu.o game.o

def.o : def.c
	gcc -o def.o -c def.c

menu.o : menu.c
	gcc -o menu.o -c menu.c

game.o : game.c
	gcc -o game.o -c game.c

clean :
	rm -f*.o prog
install :
	mkdir var
	mkdir var/bin
	make
	cp main var/bin
	cd ../../
	cd data
	cp hi.score TP-_solo/snake/data 
