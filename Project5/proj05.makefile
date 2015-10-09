proj05: proj05.driver.o proj05.support.o bitlib.o
	g++ -o proj05 proj05.support.o proj05.driver.o bitlib.o

proj05.support.o: proj05.support.c /user/cse320/Projects/project05.support.h
	g++ -c proj05.support.c

proj05.driver.o: proj05.driver.c /user/cse320/Projects/project05.support.h \
		/user/cse320/lib/bitlib.h
	g++ -c proj05.driver.c

bitlib.o: /user/cse320/lib/bitlib.c /user/cse320/lib/bitlib.h
	g++ -c /user/cse320/lib/bitlib.c

