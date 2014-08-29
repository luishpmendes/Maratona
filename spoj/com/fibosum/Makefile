CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf fibosum

fibosum: fibosum.cpp
	$(COMPILER) $(CFLAGS) fibosum.cpp -o fibosum
