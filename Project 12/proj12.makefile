#CC = gcc
#CFLAGS = -g -Wall

proj12: proj12.driver.c proj12.support.s /user/cse320/Projects/project12.support.h 
	gcc -Wall -o proj12 proj12.driver.c proj12.support.s /user/cse320/lib/reglib.o

clean:
	rm -f proj12.support.o
	rm -f proj12.driver.o
	rm -f proj12

