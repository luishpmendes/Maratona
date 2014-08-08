CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf sorvete

sorvete: sorvete.cpp
	$(COMPILER) $(CFLAGS) sorvete.cpp -o sorvete
