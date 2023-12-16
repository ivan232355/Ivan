all : prog

prog: main.o temp_api.o
	gcc -o app main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c main.c

temp_api.o: temp_api.c temp_api.h
	gcc -c temp_api.c

clean:
	del *.o prog