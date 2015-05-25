CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf 100

100: 100.cpp
	$(COMPILER) $(CFLAGS) 100.cpp -o 100
