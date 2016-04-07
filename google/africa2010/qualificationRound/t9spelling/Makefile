CPPC = g++
CFLAGS = -Wall
DEBUGFLAGS = -g -O0 -fno-inline

COMPILER = $(CPPC)
CFLAGS += $(DEBUGFLAGS)

clean: 
	rm -rf t9spelling

t9spelling: t9spelling.cpp
	$(COMPILER) $(CFLAGS) t9spelling.cpp -o t9spelling
