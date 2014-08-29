CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf chigago

chigago: chigago.cpp
	$(COMPILER) $(CFLAGS) chigago.cpp -o chigago
