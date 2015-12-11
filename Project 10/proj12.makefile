#CC = gcc
#CFLAGS = -g -Wall

proj10: proj10.driver.c proj10.support.s /user/cse320/Projects/project09.support.h 
	gcc -Wall -o proj10 proj10.driver.c proj10.support.s /user/cse320/lib/reglib.o

clean:
	rm -f proj10.support.o
	rm -f proj10.driver.o
	rm -f proj10

