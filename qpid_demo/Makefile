CC=g++
CFLAGS=-std=c++11 -g -O0 
#SRC=qpid_server.cc
OBJ=server client
LIBS=-lqpidmessaging -lqpidtypes
INC=

all:${OBJ}

client:qpid_client.cc
    $(CC) $< -o $@ $(CFLAGS) $(LIBS)
server:qpid_server.cc
    $(CC) $< -o $@ $(CFLAGS) $(LIBS)

clean:
    rm $(OBJ) -rf
