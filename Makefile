CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Icommon

OBJ=main.o \
	client/dfs_client.o \
	metadata_server/metadata.o \
	storage_node/storage.o

TARGET=cdfs

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

client/dfs_client.o: client/dfs_client.c
	$(CC) $(CFLAGS) -c client/dfs_client.c -o client/dfs_client.o

metadata_server/metadata.o: metadata_server/metadata.c
	$(CC) $(CFLAGS) -c metadata_server/metadata.c -o metadata_server/metadata.o

storage_node/storage.o: storage_node/storage.c
	$(CC) $(CFLAGS) -c storage_node/storage.c -o storage_node/storage.o

clean:
	rm -f $(TARGET) *.o client/*.o metadata_server/*.o storage_node/*.o chunk_*.dat
