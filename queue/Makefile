main: main.o queue.o Node.o
	g++ -o main main.o queue.o Node.o

main.o: main.cpp stack.h

queue.o: queue.cpp queue.h

node.o: Node.cpp Node.h

clean:
	rm *.o