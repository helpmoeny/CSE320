proj07:			proj07.driver.o proj07.support.o
			gcc -o proj07 proj07.driver.o proj07.support.o

proj07.driver.o:	proj07.driver.c
			gcc -c proj07.driver.c

proj07.support.o:	proj07.support.c
			gcc -c proj07.support.c
