CPPC = g++
CFLAGS = -Wall
DEBUGFLAGS = -g -O0 -fno-inline

COMPILER = $(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf problemB

problemB: problemB.cpp
	$(COMPILER) $(CFLAGS) problemB.cpp -o problemB
