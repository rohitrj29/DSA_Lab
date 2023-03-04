rm *.o
gcc -c readdata.c
gcc -c main.c 
gcc -c list2array.c
gcc -c insertion.c
gcc -c lower.c
gcc -o run_main_exe readdata.o main.o list2array.o insertion.o lower.o
./run_main_exe 