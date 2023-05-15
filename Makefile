
# Makefile for s2023, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
CFLAGS = -g

# LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

LDFLAGS = 	-ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h ecs36b_Exception.h
INC_CL	=	GPS.h JvTime.h SP_Person.h Team.h Commutable.h Message.h
OBJ	=	GPS.o JvTime.o SP_Person.o Team.o Commutable.o Message.o

# rules.
all: 	mobility_server mobility_send mobility_dump

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

mobility_client.h:		ecs36b_mobility.json
	jsonrpcstub ecs36b_mobility.json --cpp-server=mobility_Server --cpp-client=mobility_Client

mobility_server.h:		ecs36b_mobility.json
	jsonrpcstub ecs36b_mobility.json --cpp-server=mobility_Server --cpp-client=mobility_Client

mobility_send.o:		mobility_send.cpp mobility_client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) mobility_send.cpp

mobility_dump.o:		mobility_dump.cpp mobility_client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) mobility_dump.cpp

mobility_server.o:		mobility_server.cpp mobility_server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) mobility_server.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

GPS.o:		GPS.cpp GPS.h $(INC)
	$(CC) -c $(CFLAGS) GPS.cpp

Message.o:		Message.cpp Message.h $(INC)
	$(CC) -c $(CFLAGS) Message.cpp

Commutable.o:		Commutable.cpp Commutable.h $(INC)
	$(CC) -c $(CFLAGS) Commutable.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

SP_Person.o:	SP_Person.cpp SP_Person.h $(INC)
	$(CC) -c $(CFLAGS) SP_Person.cpp

Team.o:	Team.cpp Team.h $(INC)
	$(CC) -c $(CFLAGS) Team.cpp

mobility_server:	mobility_server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mobility_server mobility_server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

mobility_send:	mobility_send.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mobility_send mobility_send.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

mobility_dump:	mobility_dump.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mobility_dump mobility_dump.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core mobility_client.h mobility_server.h mobility_dump mobility_send mobility_server


