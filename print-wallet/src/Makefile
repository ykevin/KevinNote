.PHONY:clean

CC = gcc
RM = rm
RMFLAGS = -rf
LIBS = -L/usr/lib  -lwiringPi -lpython2.7 -lpthread -lm -ldl -lutil -liniparser
INCLUDE = -I/usr/include/python2.7
#CFLAGS = -Wall -O -g

EXE = wallet
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(INCLUDE) $(LIBS)
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(INCLUDE) $(LIBS) 

clean:
	$(RM) $(RMFLAGS) $(EXE) $(OBJS)


