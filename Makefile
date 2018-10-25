#Name: Hrishee Shastri.

CXX=g++-7
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-O3
LDFLAGS=$(CXXFLAGS) 
#$(OPTFLAGS)

# this is a "Suffix Rule" - how to create a .o from a .cpp file
.cpp.o:
	$(CXX) $(CCFLAGS) -c $<

test_tree: test_tree.o
	$(CXX) -o test_tree test_tree.o

clean:
	rm -f *.o
