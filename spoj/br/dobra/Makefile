CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf dobra

dobra: dobra.cpp
	$(COMPILER) $(CFLAGS) dobra.cpp -o dobra
