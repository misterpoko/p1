EV = -g -pedantic-errors

compile: main.o student.o instructor.o
	g++ -o main $(EV) main.o student.o instructor.o

main.o: main.cpp
	g++ -o main.o $(EV) -c main.cpp

student.o: main.cpp
	g++ -o student.o $(EV) -c student.cpp

instructor.o: instructor.cpp
	g++ -o instructor.o $(EV) -c instructor.cpp

run: compile
	./main ./students.txt ./instructors.txt

clean:
	rm main.o student.o instructor.o main
