CC = gcc
CFLAGS = -Wall
INSTALL_DIR = /usr/local/bin

bingen: bingen.c
	$(CC) $(CFLAGS) -o bingen bingen.c

install: bingen
	cp bingen $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)/bingen
