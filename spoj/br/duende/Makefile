CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf duende

duende: duende.cpp
	$(COMPILER) $(CFLAGS) duende.cpp -o duende
