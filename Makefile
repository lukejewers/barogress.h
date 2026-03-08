CC     := gcc
SRC    := example.c
TARGET := example

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
