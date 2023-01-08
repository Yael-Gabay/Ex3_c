#Dictionery:
CFLAGS = gcc -c -Wall -g
FLAG = gcc -Wall -o 

isort.o: isort.c 
	$(CFLAGS) isort.c 
txtfind.o: txtfind.c  
	$(CFLAGS) txtfind.c 
isort: isort.o 
	$(FLAG) isort isort.o 
txtfind: txtfind.o  
	$(FLAG) txtfind txtfind.o 
	
all: isort txtfind

clean: 
	rm -rf *.o isort txtfind 






