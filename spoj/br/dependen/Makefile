CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf dependen

dependen: dependen.cpp
	$(COMPILER) $(CFLAGS) dependen.cpp -o dependen
