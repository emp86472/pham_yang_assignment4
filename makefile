compile:
	g++ -c -Wall -pedantic-errors BinaryTree.cpp
	g++ -c -Wall -pedantic-errors main.cpp

link: compile
	g++ -o main main.o BinaryTree.o

run: link
	./main

clean:
	rm -f main BinaryTree.o main.o
