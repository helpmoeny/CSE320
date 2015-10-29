#
# Sample makefile for Project #5
#
# The executable program ("proj05") is built from three
# object code files (two local, one in course directory)

proj05: proj05.support.o proj05.driver.o
	gcc -Wall \
            proj05.support.o \
            proj05.driver.o \
            /user/cse320/lib/bitlib.o \
            -o proj05

proj05.driver.o: proj05.driver.c
	gcc -c -Wall proj05.driver.c

proj05.support.o: proj05.support.c
	gcc -c -Wall proj05.support.c

