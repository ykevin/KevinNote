.PHONY:clean



CC = g++
CXXFLAGS = -g -Wall -O0 -std=c++11
LDFLAGS = -lprotobuf

EXE = test
SRCS = $(wildcard *.cc)
OBJS = $(patsubst %.cc, %.o, $(SRCS))

$(EXE):$(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CXXFLAGS) $(LDFLAGS)
%.o : %.cc proto
	$(CC) -o $@ -c $< $(CXXFLAGS)

proto: test.proto
	protoc --cpp_out . $<

clean:
	rm -rf $(OBJS) $(EXE) test.pb.*




