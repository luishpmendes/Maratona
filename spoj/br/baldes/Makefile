CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf baldes

baldes: baldes.cpp
	$(COMPILER) $(CFLAGS) baldes.cpp -o baldes
