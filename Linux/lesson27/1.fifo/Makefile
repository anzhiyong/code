SERVER=server
CLIENT=client
cc=g++
SERVER_SRC=Server.cc
CLIENT_SRC=Client.cc

.PHONY:all
all:$(SERVER) $(CLIENT)

$(SERVER):$(SERVER_SRC)
	$(cc) -o $@ $^ -std=c++11
$(CLIENT):$(CLIENT_SRC)
	$(cc) -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f $(SERVER) $(CLIENT)