.PHONY:clean


CC = g++ -std=c++11
CXXFALGS = -g -Wall -O0
LDFALGS = -lprotobuf


EXE  = test
SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CXXFALGS) $(LDFALGS)
%.o : %.cc 
	$(CC) -o $@ -c $<


#check: messages.pb storage.pb types.pb
#%.pb :%.proto
#	protoc --cpp_out=. $<

clean:
	rm -rf $(EXE) $(OBJS) *.pb.o

