#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"
//https://github.com/FauxJake/CSE320-SS13-Backup/blob/master/proj09/proj09.support.s
//https://github.com/xianhechen/CSE320/tree/master/proj09
//https://github.com/wrightmhw/project5/blob/master/UnweightedGraph.cpp
int main(){
    printf("\nNegate:\n");
    printf("-(%d) = %d\n", 1, negate(1));
    printf("-(%d) = %d\n", 2, negate(2));

    printf("Absolute:\n");
    printf("abs(%d) = %d\n", 1, absolute(1));
    printf("abs(%d) = %d\n", -1, absolute(-1));
    printf("abs(%d) = %d\n", 69, absolute(69));
    printf("abs(%d) = %d\n", -100, absolute(-100));

    printf("Add:\n");
    printf(" %d + %d = %d\n", 1, 1, add(1,1));
    printf("%d + %d = %d\n", -1, 1, add(-1,1));
    printf(" %d + %d = %d\n", 2, -2, add(2,-2));
    printf("%d + %d = %d\n", 25, 12, add(25,12));

    printf("Sub:\n");
    printf(" %d - %d = %d\n", 1, 1, sub(1,1));
    printf("%d - %d = %d\n", -1, 1, sub(-1,1));
    printf(" %d - %d = %d\n", 2, -2, sub(2,-2));
    printf("%d - %d = %d\n", 25, 12, sub(25,12));

    printf("Mul:\n");
	printf("%08x * %d = %08x\n", 2147483647, 2, mul(2147483647,2));	//high overflow case
	printf("%08x * %d = %08x\n", 0x80000000, 2, mul(0x80000000,2));	//lower overflowcase
    printf(" %d * %d = %d\n", 1, 1, mul(1,1));
    printf("%d * %d = %d\n", -1, 1, mul(-1,1));
    printf(" %d * %d = %d\n", 2, -2, mul(2,-2));
    printf("%d * %d = %d\n", 25, 12, mul(25,12));

    printf("Divide:\n");
	printf(" %d / %d = %d\n", 0, 1, divide(0,1));
	printf(" %d / %d = %08x\n", 1, 0, divide(1,0));		//Can't divide by zero case
    printf(" %d / %d = %d\n", 1, 1, divide(1,1));
    printf("%d / %d = %d\n", -1, 1, divide(-1,1));
    printf(" %d / %d = %d\n", 2, -2, divide(2,-2));
    printf("%d / %d = %d\n", 25, 5, divide(25,5));

    printf("Remain:\n");
	printf(" %d mod %d = %d\n", 0, 1, remain(0,1));
	printf(" %d mod %d = %08x\n", 1, 0, remain(1,0));
    printf(" %d mod %d = %d\n", 1, 1, remain(1,1));
    printf(" %d mod %d = %d\n", 9, 3, remain(9,3));
    printf(" %d mod %d = %d\n", 9, 5, remain(9,5));
    printf(" %d mod %d = %d\n", 9, 7, remain(9,7));
	printf("%d / %d = %d\n", 25, 5, divide(25,5));
    printf("%d mod %d = %d\n", -100, 99, remain(-100,99));	//first value negative
    printf(" %d mod %d = %d\n", -69, -6, remain(-69,-6));	//both negative
    printf("  %d mod %d = %d\n", 69, -10, remain(53,-10));	//second value negative

    printf("Power:\n");
	printf("%d ^ %d = %d\n", 0, 2, power(0,2));
    printf("%d ^ %d = %d\n", 1, 1, power(1,1));
	printf("%d ^ %d = %08x\n", -1, -1, power(-1,-1));	//no negative powers allowed
    printf("%d ^ %d = %d\n", 2, 3, power(2,3));
    printf("%d ^ %d = %d\n", 3, 3, power(3,3));
    printf("%d ^ %d = %d\n", -1, 1, power(-1,1));
    printf("%d ^ %d = %d\n", -2, 2, power(-2,2));
    printf("%d ^ %d = %d\n", -4, 2, power(-4,2));
	printf("%d ^ %d = %08x\n", -4, -2, power(-4,-2));	//no negative powers allowed

    printf("Factorial:\n");
    printf("%d! = %d\n", 1, factorial(1));
	printf("%d! = %08x\n", -1, factorial(-1));
    printf("%d! = %d\n", 3, factorial(3));
    printf("%d! = %d\n", 5, factorial(5));
    printf("%d! = %d\n\n", 10, factorial(10));

    return 0;
}
