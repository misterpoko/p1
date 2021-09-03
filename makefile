EV = -g -Wall -pedantic-errors

compile: main.o student.o instructor.o
	g++ -o main $(EV) main.o

main.o: main.cpp 
	g++ -o main.o $(EV) -c main.cpp

student.o: student.cpp
	g++ -o student.o $(EV) -c student.cpp

instructor.o: instructor.cpp
	g++ -o instructor.o $(EV) -c instructor.cpp

run: compile
	./main

clean:
	rm main.o main
	rm student.o student
	rm instructor.o instructor
