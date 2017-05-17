CPPC=g++
CFLAGS= -Wall
DEBUGFLAGS= -g -O0 -fno-inline

COMPILER=$(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean:
	rm -rf 1124 1124.out

1124: 1124.cpp
	$(COMPILER) $(CFLAGS) 1124.cpp -o 1124
