gcc -c stackDriver.c
gcc -c stack_array.c
gcc -o stackADT_exe stack_array.o stackDriver.o
./stackADT_exe