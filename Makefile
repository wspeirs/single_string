GPP   = /usr/bin/g++
GCC   = /usr/bin/gcc
FLAGS =  --std=c++11 -W -Wall -g -Wctor-dtor-privacy -Wold-style-cast -Woverloaded-virtual
LIBS  =
EXEC  = single_string

all: main.o single_string.o
	$(GPP) $(FLAGS) $(LIBS) *.o -o $(EXEC)

main.o: main.cpp single_string.h
	$(GPP) -c $(FLAGS) main.cpp

single_string.o: single_string.cpp single_string.h
	$(GPP) -c $(FLAGS) single_string.cpp

clean:
	rm *~ *.o $(EXEC)
