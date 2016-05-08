OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I.

TARGETS = UsutfTest

all: $(TARGETS)

UsutfTest: UsutfTest.o Usutf.o
	g++ -o UsutfTest UsutfTest.o Usutf.o

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o

