CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf recupera

recupera: recupera.cpp
	$(COMPILER) $(CFLAGS) recupera.cpp -o recupera
