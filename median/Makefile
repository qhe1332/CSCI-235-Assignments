
OBJECTS=main.o heap.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
heap.o: heap.cpp Node.h heap.h

main.o: main.cpp Node.h heap.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)