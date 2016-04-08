CPPC = g++
CFLAGS = -Wall
DEBUGFLAGS = -O0

COMPILER = $(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf problemC

problemC: problemC.cpp
	$(COMPILER) $(CFLAGS) problemC.cpp -o problemC
