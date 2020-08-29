
OBJECTS=main.o heapTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
heapTree.o: heapTree.cpp Node.h heapTree.h

main.o: main.cpp Node.h heapTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)