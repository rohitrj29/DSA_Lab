gcc -c stackDriver.c
gcc -c stack_linked.c
gcc -o stackADT_exe stack_linked.o stackDriver.o
./stackADT_exe