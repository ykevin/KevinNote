.PHONY:clean

CC = g++
CXXFALGS = -g -Wall -O0
LDFALGS = -lprotobuf


EXE  = test
SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CXXFALGS) $(LDFALGS)
%.o : %.cc 
	$(CC) -o $@ -c $<

proto :	*.proto
	protoc --cpp_out=. $<

clean:
	rm -rf $(EXE) $(OBJS) *.pb.*

