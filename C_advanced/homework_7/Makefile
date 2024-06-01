all: pumpkin_drone

pumpkin_drone: main.o navigation.o drone.o field.o aux_func.o
	gcc -o pumpkin_drone main.o navigation.o drone.o field.o aux_func.o

main.o: main.c
	gcc -c -o main.o main.c

navigation.o: navigation.c
	gcc -c -o navigation.o navigation.c

drone.o:drone.c
	gcc -c -o drone.o drone.c

field.o: field.c
	gcc -c -o field.o field.c

aux_func.o : aux_func.c
	gcc -c -o aux_func.o aux_func.c

clean: 
	rm -rf *.o pumpkin_drone