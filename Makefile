# Author: NULL_703
# Created on: 2022.11.11    17:44
bin := iptools.exe
link := -I ./include
all: $(bin)

$(bin): main.o
	gcc -s -Wall main.o -L./lib -lformula -o $(bin)

main.o: main.c
	gcc -s -Wall $(link) -c main.c -o main.o

.PHONY: clean

clean: 
	del *.o
	del *.exe