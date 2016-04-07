CPPC = g++
CFLAGS = -Wall
DEBUGFLAGS = -g -O0 -fno-inline

COMPILER = $(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf problemA

problemA: problemA.cpp
	$(COMPILER) $(CFLAGS) problemA.cpp -o problemA
