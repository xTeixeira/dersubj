SRCDIR = src
BINDIR = bin
INSTALLDIR = /bin
SRC = $(addprefix $(SRCDIR)/, DerHandler.cpp DerHandler.h FileReader.cpp FileReader.h main.cpp)
CC = g++
CFLAGS= -std=c++11
LFLAGS = -lcrypto

dersubj : $(SRC)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(SRC) -o $(BINDIR)/dersubj

install :
	cp $(BINDIR)/dersubj $(INSTALLDIR)/dersubj
