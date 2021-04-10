dijkstra: driver.o utility.o 
	gcc -o dijkstra driver.o utility.o
	
driver.o: driver.c
	gcc -c driver.c header.h
utility.o: utility.c
	gcc -c utility.c header.h