CC := gcc

SOFLAGS := -shared -fPIC -m32
CFLAGS := -O2 -s -flto

all: antiogg.so oggrawsize

debug: CFLAGS += -DDEBUG

debug: all

antiogg.so: src/antiogg.c
	$(CC) $(SOFLAGS) $(CFLAGS) $^ -o $@

oggrawsize: src/oggrawsize.c
	$(CC) $(CFLAGS) $^ -o $@ -lvorbisfile

clean:
	rm -f antiogg.so oggrawsize
